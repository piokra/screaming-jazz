/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SelectorRequestHandlerFactory.h
 * Author: Pan Piotr
 *
 * Created on 01 May 2016, 19:05
 */

#ifndef SELECTORREQUESTHANDLERFACTORY_H
#define SELECTORREQUESTHANDLERFACTORY_H

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <vector>
#include <tuple>
#include <memory>
#include "RequestSelector.h"
namespace ScreamingJazz
{

using namespace Poco;
using namespace Poco::Net;
using namespace std;

class SelectorRequestHandlerFactory : public HTTPRequestHandlerFactory
{
    using RSPtr = std::shared_ptr<RequestSelector>;
    using RRSPtr = RequestSelector*;
    using FPtr = std::shared_ptr<HTTPRequestHandlerFactory>;
    using RFPtr = HTTPRequestHandlerFactory*;
    using RSFPair =
            std::pair<RSPtr,FPtr>;
public:
    SelectorRequestHandlerFactory();
    SelectorRequestHandlerFactory(const SelectorRequestHandlerFactory& orig);
    virtual ~SelectorRequestHandlerFactory();

    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) override;

    void addSelectorAndFactory(RequestSelector* req, HTTPRequestHandlerFactory* fac);

private:
    std::vector<RSFPair> mSelectorsFactories;
};

}
#endif /* SELECTORREQUESTHANDLERFACTORY_H */

