/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextSelector.h
 * Author: Pan Piotr
 *
 * Created on 09 May 2016, 12:16
 */

#ifndef TEXTSELECTOR_H
#define TEXTSELECTOR_H

#include <string>

using namespace std;
class TextSelector
{
public:
    virtual bool matches(const string& str) = 0; 
};

#endif /* TEXTSELECTOR_H */

