/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleFactories.h
 * Author: Pan Piotr
 *
 * Created on 01 May 2016, 20:13
 */

#ifndef SIMPLEFACTORIES_H
#define SIMPLEFACTORIES_H

#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>

using namespace Poco;
using namespace Poco::Net;

template <typename T>
class SimpleRequestHandlerFactory : public HTTPRequestHandlerFactory
{

    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) override
    {
        return new T();
    };

};

#endif /* SIMPLEFACTORIES_H */

