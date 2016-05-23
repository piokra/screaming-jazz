/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringUtil.h
 * Author: Pan Piotr
 *
 * Created on 13 May 2016, 12:54
 */

#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <string>
#include <vector>
class StringUtil
{
    //using namespace std;
public:
    StringUtil() = delete;
    StringUtil(const StringUtil& orig) = delete;
    
    static void split(const std::string& toSplit, const std::string& seperators, std::vector<std::string>& buffer);
    static std::vector<std::string> split(const std::string& toSplit, const std::string& seperators);
private:

};

#endif /* STRINGUTIL_H */

