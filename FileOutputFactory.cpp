/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileOutputFactory.cpp
 * Author: Pan Piotr
 * 
 * Created on 23 May 2016, 11:32
 */

#include "FileOutputFactory.h"
#include "StringUtil.h"
#include "FileOutputHandler.h"

namespace ScreamingJazz
{

FileOutputFactory::FileOutputFactory(unsigned startAt, Path homeDir) : mStartAt(startAt), mHomePath(homeDir)
{
}

FileOutputFactory::FileOutputFactory(const FileOutputFactory& orig)
{
}

FileOutputFactory::~FileOutputFactory()
{

}

HTTPRequestHandler* FileOutputFactory::createRequestHandler(const HTTPServerRequest& request)
{
    Path requestPath = mHomePath;
    auto vec = StringUtil::split(request.getURI(), "?/");
    for (unsigned i = mStartAt; i < vec.size(); i++)
    {
        auto part = vec[i];
        if (part == "..")
        {
        }
        else
        {
            requestPath.append(part);
        }
    }
    return new FileOutputHandler(requestPath);

}

}

