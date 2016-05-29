/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RequestLogger.h
 * Author: Joanna Cichowska
 *
 * Created on 29 maja 2016, 19:31
 */

#ifndef REQUESTLOGGER_H
#define REQUESTLOGGER_H

#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <memory>
#include <string>

#include "SQLLogger.h"
namespace ScreamingJazz
{

using namespace Poco;
using namespace Poco::Net;
using namespace std;

class RequestLogger : public HTTPRequestHandlerFactory
{
    
    using FPtr = unique_ptr<HTTPRequestHandlerFactory>;
public:
    RequestLogger(HTTPRequestHandlerFactory* toForwardTo, string tag, 
                  bool create = true, int severity = 100);
    RequestLogger(const RequestLogger& orig) = delete;
    virtual ~RequestLogger();
    
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) override;

private:
    FPtr mForward;
    string mTag;
    
};
}
#endif /* REQUESTLOGGER_H */

