/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileOutputFactory.h
 * Author: Pan Piotr
 *
 * Created on 23 May 2016, 11:32
 */

#ifndef FILEOUTPUTFACTORY_H
#define FILEOUTPUTFACTORY_H

#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Path.h>

using namespace Poco::Net;
using namespace Poco;

class FileOutputFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:

    FileOutputFactory(unsigned startAt, Path homeDir);
    FileOutputFactory(const FileOutputFactory& orig);
    virtual ~FileOutputFactory();
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) override;

private:
    unsigned mStartAt;
    Path mHomePath;
};

#endif /* FILEOUTPUTFACTORY_H */

