/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RequestLogger.cpp
 * Author: Joanna Cichowska
 * 
 * Created on 29 maja 2016, 19:31
 */

#include "RequestLogger.h"
#include "ScreamingJazzApp.h"
namespace ScreamingJazz
{
RequestLogger::RequestLogger(HTTPRequestHandlerFactory* toForwardTo, string tag, 
                  bool create, int severity) : mForward(toForwardTo), mTag(tag)
{
    SQLLogger* logger = ScreamingJazzApp::defaultSQLLogger();
    if(create)
    {
        logger->createTag(tag,severity);
    }
}



RequestLogger::~RequestLogger()
{
}

HTTPRequestHandler* RequestLogger::createRequestHandler(const HTTPServerRequest& request)
{
    SQLLogger* logger = ScreamingJazzApp::defaultSQLLogger();
    string log = format("Got request FROM: %s URI: %s", request.getHost(),
                        request.getURI());
    logger->log(log,mTag);
    return mForward->createRequestHandler(request);
}

}
