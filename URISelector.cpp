/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   URISelector.cpp
 * Author: Pan Piotr
 * 
 * Created on 09 May 2016, 12:13
 */

#include "URISelector.h"
#include <iostream>
URISelector::URISelector() : URISelector(1,false)
{
}

URISelector::URISelector(int priority, bool force) : mPriority(priority),
        mForce(force)
{
    
}


URISelector::URISelector(const URISelector& orig)
{
}

URISelector::~URISelector()
{
}

void URISelector::addNextSelector(TextSelector* ptr, int usage)
{
    mSelectors.push_back(SelectorCountPair(ptr,usage));
}

RequestSelector::Selection URISelector::choose(const HTTPServerRequest& request) const
{

}

vector<string> URISelector::seperateRequest(const HTTPServerRequest& request)
{
    vector<string> ret;
    int ptr = 0;
    string& uri = request.getURI();
    cout << uri << endl;
    
}
