/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PenisHandler.h
 * Author: Pan Piotr
 *
 * Created on 01 May 2016, 20:14
 */

#ifndef PENISHANDLER_H
#define PENISHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>

namespace ScreamingJazz
{
using namespace Poco;
using namespace Poco::Net;
class PenisHandler : public HTTPRequestHandler
{
public:
    PenisHandler();
    PenisHandler(const PenisHandler& orig);
    virtual ~PenisHandler();
    
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) override;

private:

};
}
#endif /* PENISHANDLER_H */

