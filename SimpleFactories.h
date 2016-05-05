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
#include "TemplateUtil.h"
#include <tuple>

using namespace Poco;
using namespace Poco::Net;
using namespace std;

template <typename T, typename...R>
class SimpleRequestHandlerFactory : public HTTPRequestHandlerFactory {
    tuple<R...> mParams;
    typename gens<sizeof...(R)>::type mSequence;

    template<int...i>
    HTTPRequestHandler* creator(seq<i...>) {
        return new T(get<i>(mParams)...);
    }
public:

    SimpleRequestHandlerFactory(R...r) {
        mParams = make_tuple(r...);
    }

    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) override {
        return creator(mSequence);
    };



};

template <typename T>
class SimpleRequestHandlerFactory<T> : public HTTPRequestHandlerFactory
{
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request) override {
        return new T();
    };
};

#endif /* SIMPLEFACTORIES_H */

