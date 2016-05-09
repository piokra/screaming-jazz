/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AllTextSelector.h
 * Author: Pan Piotr
 *
 * Created on 09 May 2016, 13:30
 */

#ifndef ALLTEXTSELECTOR_H
#define ALLTEXTSELECTOR_H

#include <string>
#include "TextSelector.h"
using namespace std;

class AllTextSelector : public TextSelector
{
public:
    AllTextSelector();
    AllTextSelector(const AllTextSelector& orig);
    virtual ~AllTextSelector();
    
    bool matches(const string& str) override;

private:

};

#endif /* ALLTEXTSELECTOR_H */

