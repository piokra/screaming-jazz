/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringUtil.cpp
 * Author: Pan Piotr
 * Created on 13 May 2016, 12:54
 */

#include "StringUtil.h"
using namespace std;

void StringUtil::split(const string& toSplit, const string& seperators, vector<string>& buffer)
{
    vector<string::size_type> pos;
    string::size_type ptr = toSplit.find_first_of(seperators);
    while (ptr != string::npos)
    {
        pos.push_back(ptr);
        ptr = toSplit.find_first_of(seperators, ptr + 1);
    }
    pos.push_back(toSplit.size());
    int start = 0, end = 0;
    for (int i = 0; i < pos.size(); i++)
    {
        end = pos[i];
        if (end - start > 1)
        {
            buffer.push_back(toSplit.substr(start, end - start));

        }
        start = end + 1;
    }
}

vector<string> StringUtil::split(const string& toSplit, const string& seperators)
{
    vector<string> ret;
    split(toSplit, seperators, ret);
    return ret;
}


