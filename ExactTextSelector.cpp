/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExactTextSelector.cpp
 * Author: Pan Piotr
 * 
 * Created on 09 May 2016, 13:23
 */

#include "ExactTextSelector.h"

ExactTextSelector::ExactTextSelector(const string& str) : mStr(str)
{
}

ExactTextSelector::~ExactTextSelector()
{
}

bool ExactTextSelector::matches(const string& str)
{
    return str==mStr;
}

