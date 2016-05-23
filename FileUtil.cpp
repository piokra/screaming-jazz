/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileUtil.cpp
 * Author: Pan Piotr
 * 
 * Created on 23 May 2016, 10:36
 */

#include "FileUtil.h"
#include <iterator>
FileUtil::FileUtil()
{
}

FileUtil::FileUtil(const FileUtil& orig)
{
}

FileUtil::~FileUtil()
{
}

vector<BYTE> FileUtil::readBinaryFile(const string& path)
{

    ifstream file(path, std::ios::binary);

    file.unsetf(std::ios::skipws);

    streampos fileSize;

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    vector<BYTE> vec;
    vec.reserve(fileSize);

    vec.insert(vec.begin(),
               istream_iterator<BYTE>(file),
               istream_iterator<BYTE>());

    return vec;

}
