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
namespace ScreamingJazz
{

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
    File file(mPath);
    try
    {
        if (!(file.exists() && file.canRead()) || file.isDevice())
        {
            throw exception();
        }

    }
    catch (...)
    {
        cout << mPath.toString() << endl;

        string s = R"swag(<html><body>Bad request</body></html>)swag";
        response.setContentLength(s.length());
        response.setStatus(response.HTTP_BAD_REQUEST);
        response.send() << s;
        return;
    }
    if (file.isFile())
    {
        auto data = FileUtil::readBinaryFile(mPath.toString());
        response.setContentLength(data.size());
        response.send().write((char*) data.data(), data.size());
        return;
    }
    else
    {
        vector<File> buffer;
        file.list(buffer);
        response.setChunkedTransferEncoding(true);
        auto&& stream = response.send();
        stream << "<html>";
        for (auto&& file : buffer)
        {
            string suffix = "";
            if (file.isDirectory())
            {
                suffix += "/";
            }
            suffix += "\">";
            Path path(file.path());
            stream << "<a href=\"./" << path.getFileName() << suffix << path.getFileName() << "</a>" << "<br>";
        }
        stream << "</html>";
        return;
    }
    response.setContentLength(0);
    response.setStatus(response.HTTP_PAYMENT_REQUIRED);
    response.send();
}


}
