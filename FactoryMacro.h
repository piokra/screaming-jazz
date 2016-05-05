/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FactoryMacro.h
 * Author: Pan Piotr
 *
 * Created on 01 May 2016, 20:09
 */

#ifndef FACTORYMACRO_H
#define FACTORYMACRO_H

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>

#define SIMPLE_HTTP_REQUEST_HANDLER_FACTORY(CNAME, RTYPE) \
\
namespace ScreamingJazz \
{ \
using namespace Poco; \
using namespace Poco::Net; \
class RTYPE; \
\
class CNAME : public HTTPRequestHandlerFactory \
{ \
public: \
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) override \
{\
    return new RTYPE (); \
}\
    \
private: \
 \
}; \
 \
}




#endif /* FACTORYMACRO_H */

