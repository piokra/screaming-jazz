/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PenisHandler.cpp
 * Author: Pan Piotr
 * 
 * Created on 01 May 2016, 20:14
 */

#include "PenisHandler.h"
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <iostream>
using namespace std;
namespace ScreamingJazz
{

PenisHandler::PenisHandler()
{
}

PenisHandler::PenisHandler(const PenisHandler& orig)
{
}

PenisHandler::~PenisHandler()
{
}

void PenisHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    cout << request.getURI() << endl;
    response.setContentType("text/html");
    response.setChunkedTransferEncoding(true);
    auto& out = response.send();
    out << R"swag(<html><head><meta charset="UTF-8"><title>HTTP Server powered by POCO C++ Libraries</title></head >)swag";
    auto penis =
            R"swag(
     <pre>
           ,-'-.     _.,  <br>
        . (    '("'-'  ').  <br>
     ( ' ((  |.      )\/( ) <br>
      '(  )) | () |" |  | ') <br>
         ( . ,-. ,-.. __.) <br>
           /)  /  ' /         <br>
          /   /) / /                <br>
    …………………...„„-~^^~„-„„_<br>
………………„-^*'' : : „'' : : : : *-„<br>
…………..„-* : : :„„--/ : : : : : : : '\<br>
…………./ : : „-* . .| : : : : : : : : '|<br>
……….../ : „-* . . . | : : : : : : : : |<br>
………...\„-* . . . . .| : : : : : : : :'|<br>
……….../ . . . . . . '| : : : : : : : :|<br>
……..../ . . . . . . . .'\ : : : : : : : |<br>
……../ . . . . . . . . . .\ : : : : : : :|<br>
……./ . . . . . . . . . . . '\ : : : : : /<br>
…/ . . . . . . . ./ . . . . . . .| <br>
../ . . . . . . . .'/ . . . . . . .'|<br>
./ . . . . . . . . . . . . . . .'|<br>
'/ . . . . . . . . . . . . . . . .'|<br>
'| . . . . . \ . . . . . . . . . .|<br>
'| . . . . . . \„_^- „ . . . . .'|<br>
'| . . . . . . . . .'\ .\ ./ '/ . |<br>
| .\ . . . . . . . . . \ .'' / . '|<br>
| . . . . . . . . . . / .'/ . . .|<br>
| . . . . . . .| . . / ./ ./ . .|</pre>)swag";
    out << "<body>";
    out << penis;
    out << "</body>";
    out << "</html>";
}


}