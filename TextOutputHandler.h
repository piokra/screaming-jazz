/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextOutputHandler.h
 * Author: Pan Piotr
 *
 * Created on 08 May 2016, 11:38
 */

#ifndef TEXTOUTPUTHANDLER_H
#define TEXTOUTPUTHANDLER_H

#include <string>
#include <Poco/Net/HTTPRequestHandler.h>
using namespace Poco::Net;
using namespace std;
namespace ScreamingJazz
{
class TextOutputHandler : public HTTPRequestHandler
{
public:
    TextOutputHandler(const string& msg);
    TextOutputHandler(const TextOutputHandler& orig);
    virtual ~TextOutputHandler();
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) override;

private:
    string mMsg;
};
}
#endif /* TEXTOUTPUTHANDLER_H */

