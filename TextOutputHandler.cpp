/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextOutputHandler.cpp
 * Author: Pan Piotr
 * 
 * Created on 08 May 2016, 11:38
 */

#include <Poco/Net/HTTPMessage.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include "TextOutputHandler.h"
#include <iostream>
namespace ScreamingJazz
{

TextOutputHandler::TextOutputHandler(const std::string& msg) : mMsg(msg)
{
}

TextOutputHandler::TextOutputHandler(const TextOutputHandler& orig)
{
}

TextOutputHandler::~TextOutputHandler()
{
}

void TextOutputHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    cout << request.clientAddress().host().toString() << endl;
    response.setContentType("text/html");
    response.setContentLength(mMsg.length());
    auto& out = response.send();
    out << mMsg;
}


}