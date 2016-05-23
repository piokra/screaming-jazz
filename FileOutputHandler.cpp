/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileOutputHandler.cpp
 * Author: Pan Piotr
 * 
 * Created on 23 May 2016, 10:11
 */

#include <Poco/Net/HTTPMessage.h>

#include "FileOutputHandler.h"
#include "FileUtil.h"
#include <string>
#include <Poco/Net/HTTPServerResponse.h>
#include <fstream>
#include <iostream>
using namespace std;


FileOutputHandler::FileOutputHandler(Path path) : mPath(path)
{
    
}

FileOutputHandler::FileOutputHandler(const FileOutputHandler& orig)
{
}

FileOutputHandler::~FileOutputHandler()
{
}

void FileOutputHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    string file_path;
    try
    {
        File file(mPath);
        if(!(file.exists() && file.canRead()))
        {
            throw exception();
        }
        
    }
    catch (...)
    {
        cout << mPath.toString() << endl;
        
        string s = R"swag(<html><body>exception thrown</body></html>)swag";
        response.setContentLength(s.length());
        response.send() << s;
        return;
    }
    auto data = FileUtil::readBinaryFile(mPath.toString());
    response.setContentLength(data.size());
    response.send().write((char*)data.data(),data.size());
    
}
