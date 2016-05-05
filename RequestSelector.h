/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   URISelector.h
 * Author: Pan Piotr
 *
 * Created on 01 May 2016, 13:04
 */

#ifndef URISELECTOR_H
#define URISELECTOR_H

#include <Poco/Net/HTTPServerRequest.h>

using namespace Poco;
using namespace Poco::Net;

namespace ScreamingJazz
{

class RequestSelector
{
public:
    struct Selection
    {
        bool wants;
        bool force;
        int priority;
    };

    virtual Selection choose(const HTTPServerRequest& request) const = 0;
};

}
#endif /* URISELECTOR_H */

