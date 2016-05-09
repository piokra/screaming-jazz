/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExactTextSelector.h
 * Author: Pan Piotr
 *
 * Created on 09 May 2016, 13:23
 */

#ifndef EXACTTEXTSELECTOR_H
#define EXACTTEXTSELECTOR_H

#include <string>
#include "TextSelector.h"
using namespace std;
class ExactTextSelector : public TextSelector
{
public:
    ExactTextSelector(const string& str);
    virtual ~ExactTextSelector();
    
    bool matches(const string& str) override;

private:
    string mStr;
};

#endif /* EXACTTEXTSELECTOR_H */

