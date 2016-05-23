/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileUtil.h
 * Author: Pan Piotr
 *
 * Created on 23 May 2016, 10:36
 */

#ifndef FILEUTIL_H
#define FILEUTIL_H
#include <fstream>
#include <vector>

using namespace std;
using BYTE = unsigned char;
class FileUtil
{
public:
    
    
    static vector<BYTE> readBinaryFile(const string& path);
private:
    
    FileUtil();
    FileUtil(const FileUtil& orig);
    virtual ~FileUtil();
};

#endif /* FILEUTIL_H */

