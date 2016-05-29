/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileOutputHandler.h
 * Author: Pan Piotr
 *
 * Created on 23 May 2016, 10:11
 */

#ifndef FILEOUTPUTHANDLER_H
#define FILEOUTPUTHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/File.h>
#include <Poco/Path.h>

namespace ScreamingJazz
{
using namespace Poco;
using namespace Poco::Net;

class FileOutputHandler : public HTTPRequestHandler
{
public:
    FileOutputHandler(Path path);
    FileOutputHandler(const FileOutputHandler& orig);
    virtual ~FileOutputHandler();
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) override;

private:
    Path mPath;
};
}
#endif /* FILEOUTPUTHANDLER_H */

