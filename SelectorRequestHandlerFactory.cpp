/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SelectorRequestHandlerFactory.cpp
 * Author: Pan Piotr
 * 
 * Created on 01 May 2016, 19:05
 */

#include "SelectorRequestHandlerFactory.h"

namespace ScreamingJazz
{

SelectorRequestHandlerFactory::SelectorRequestHandlerFactory()
{
}

SelectorRequestHandlerFactory::SelectorRequestHandlerFactory(const SelectorRequestHandlerFactory& orig)
{
}

SelectorRequestHandlerFactory::~SelectorRequestHandlerFactory()
{
}

HTTPRequestHandler* SelectorRequestHandlerFactory::createRequestHandler(const HTTPServerRequest& request)
{
    int size = mSelectorsFactories.size();
    FPtr best_factory = 0;
    int best_priority = -1;
    for (int i = 0; i < size; i++)
    {

        auto test = mSelectorsFactories.at(i).first->choose(request);
        if (test.wants)
        {
            if ((test.priority > best_priority) || test.force)
            {
                best_factory = mSelectorsFactories.at(i).second;
                best_priority = test.priority;
            }

            if (test.force)
            {
                break;
            }
        }
    }
    return best_factory->createRequestHandler(request);
}

void SelectorRequestHandlerFactory::addSelectorAndFactory(RequestSelector* req, HTTPRequestHandlerFactory* fac)
{


    mSelectorsFactories.push_back(RSFPair(RSPtr(req), FPtr(fac)));
}


}