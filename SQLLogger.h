/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SQLLogger.h
 * Author: Pan Piotr
 *
 * Created on 28 May 2016, 19:05
 */

#ifndef SQLLOGGER_H
#define SQLLOGGER_H

#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/Session.h>
#include <Poco/NotificationQueue.h>
#include <Poco/Notification.h>
#include <Poco/Types.h>
#include <string>
using namespace std;
using namespace Poco::Data;
using namespace Poco;

class SQLLogger
{
public:
    SQLLogger(const string& loggerName, const string& host, const string& port,
              const string& db, const string& user, const string& passw);
    SQLLogger(const SQLLogger& orig) = delete;
    virtual ~SQLLogger();
    
    void log(const string& msg);
    void log(const string& msg, const string& msg_level);
    void createTag(const string& str, int severity);
    void start();
    void stop();
protected:
    
    struct Message : public Notification
    {
        Message(const string& msg, const string& msg_level);
        Message();
        bool terminate = false;
        string msg;
        string msg_level;
    };
    
    class Listener : public Runnable
    {
    public:
        Listener(SQLLogger* master);
        void run() override;
    private:
        SQLLogger* mMaster;
    };
    
    void listen();
    void sendMessage(Message* msg);
private:
    Listener mListener;
    Thread mThread;
    string mLoggerName;
    NotificationQueue mMsgQueue;
    Session* mSession;
    string mUUID;
    int mID;
    int mDefaultTagID;
    int mErrorTagID;
};

#endif /* SQLLOGGER_H */

