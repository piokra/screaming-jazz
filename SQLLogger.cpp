/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SQLLogger.cpp
 * Author: Pan Piotr
 * 
 * Created on 28 May 2016, 19:05
 */

#include "SQLLogger.h"
#include <Poco/UUIDGenerator.h>
#include <Poco/UUID.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/Connector.h>
#include <Poco/Data/Binding.h>
#include <Poco/Data/AbstractBinding.h>
#include <Poco/DynamicAny.h>
#include <Poco/Nullable.h>
#include <iostream>
#include <Poco/Thread.h>
using namespace Poco::Data::Keywords;

SQLLogger::SQLLogger(const string& loggerName, const string& host, const string& port,
                     const string& db, const string& user, const string& passw) :
mLoggerName(loggerName), mListener(this)
{
    MySQL::Connector::registerConnector();
    //connect;
    auto str = format("host=%s;port=%s;db=%s;user=%s;password=%s;compress=true;auto-reconnect=true",
                      host, port, db, user, passw);
    mSession = new Session("MySQL", str);
    auto&& session = *mSession;

    //check for default
    Nullable<int> def;
    session << "SELECT idTag FROM Tag WHERE name='[INFO]'", into(def), now;
    if (def.isNull())
    {
        session << "INSERT INTO Tag(name,severity) VALUES('[INFO]',1)", now;
        cout << "No default\n";
        def.clear();
        session << "SELECT idTag FROM Tag WHERE name='[INFO]'", into(def), now;
    }
    mDefaultTagID = def.value();

    //check for err
    Nullable<int> err;

    session << "SELECT idTag FROM Tag WHERE name='[ERROR]'", into(err), now;
    if (err.isNull())
    {
        cout << "No err\n";
        session << "INSERT INTO Tag(name,severity) VALUES('[ERROR]',69)", now;
        err.clear();
        session << "SELECT idTag FROM Tag WHERE name='[ERROR]'", into(err), now;
    }
    mErrorTagID = err.value();

    //register logger
    mUUID = UUIDGenerator::defaultGenerator().createOne().toString();
    session << "INSERT INTO Logger(loggerName,loggerStart,UUID) VALUES (?,NOW(),?)",
            use(mLoggerName), use(mUUID), now;
    session << "SELECT idLogger FROM Logger WHERE UUID=? LIMIT 1", use(mUUID), into(mID), now;
}

SQLLogger::~SQLLogger()
{
    auto&& session = *mSession;
    session << "UPDATE Logger SET loggerEnd=NOW() WHERE UUID=?", use(mUUID), now;
    session.close();
    MySQL::Connector::unregisterConnector();

    delete mSession;
}

SQLLogger::Message::Message(const string& msg, const string& msg_level)
{
    this->msg = msg;
    this->msg_level = msg_level;
}

SQLLogger::Message::Message()
{
    terminate = true;
}

void SQLLogger::listen()
{
    bool done = false;
    while (!done)
    {

        Message* msg = (Message*) mMsgQueue.waitDequeueNotification();
        if (!msg->terminate)
        {
            sendMessage(msg);
        }
        else
        {
            done = true;
        }
        delete msg;
    }
}

void SQLLogger::sendMessage(Message* msg)
{
    Nullable<int> tagID;
    auto&& session = *mSession;
    session << "SELECT idTag FROM Tag WHERE name=? LIMIT 1", use(msg->msg_level),
            into(tagID), now;
    if (tagID.isNull())
    {
        log(msg->msg_level+": not found.", "[ERROR]");
        tagID=mDefaultTagID;
    }
    session << "INSERT INTO Log(text,Tag_idTag, Logger_idLogger) VALUES (?,?,?)",
            use(msg->msg), use(tagID), use(mID), now;
}

void SQLLogger::log(const string& msg)
{
    log(msg,"[INFO]");
}

void SQLLogger::log(const string& msg, const string& msg_level)
{
    Message* _msg = new Message(msg,msg_level);
    mMsgQueue.enqueueNotification(_msg);
}

void SQLLogger::createTag(const string& _str, int severity)
{
    string str = _str;
    auto&& session = *mSession;
    Nullable<int> id;
    //check for existance
    session << "SELECT idTag FROM Tag WHERE name=?", use(str), into(id), now;
    if(id.isNull())
    {
        session << "INSERT INTO Tag(name, severity) VALUES (?,?)", use(str), 
                use(severity), now;
    }
    else
    {
        log(str+": ALREADY EXISTS");
    }
}

void SQLLogger::start()
{
    mThread.start(mListener);
}

void SQLLogger::stop()
{
    mMsgQueue.enqueueNotification(new Message());
    mThread.join();
}

SQLLogger::Listener::Listener(SQLLogger* master) : mMaster(master)
{
    
}

void SQLLogger::Listener::run()
{
    mMaster->listen();
}


