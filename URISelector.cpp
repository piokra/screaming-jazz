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
#include <Poco/Net/HTTPServerRequest.h>
#include <iostream>

namespace ScreamingJazz
{

using namespace Poco::Net;

URISelector::URISelector() : URISelector(1, false)
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
    mSelectors.push_back(SelectorCountPair(ptr, usage));
}

RequestSelector::Selection URISelector::choose(const HTTPServerRequest& request) const
{
    vector<string> strings = seperateRequest(request);
    bool result = true;
    int countsThisSelector = 0;
    auto selector = mSelectors.begin();
    for(auto it=strings.begin(); it!=strings.end(); ++it)
    {
        bool &= selector->selector->matches(*it);
        countsThisSelector++;
        if((countsThisSelector == selector->usage) && (selector != mSelectors.end()))
        {
            countsThisSelector = 0;
            ++selector;
        }
        if(result==false)
        {
            return {false,false, -1};
        }
    }
    return {true,mForce,mPriority};

}

vector<string> URISelector::seperateRequest(const HTTPServerRequest& request) const
{
    vector<string> ret;
    vector<string::size_type> pos;
    string uri = request.getURI();
    string::size_type ptr = uri.find_first_of("/?");
    while (ptr != string::npos)
    {
        cout << ptr << endl;
        pos.push_back(ptr);
        ptr = uri.find_first_of("/?", ptr + 1);
    }
    pos.push_back(uri.size());
    int start = 0, end = 0;
    for (int i = 0; i < pos.size(); i++)
    {
        end = pos[i];
        if (end - start > 1)
        {
            ret.push_back(uri.substr(start, end-start));

        }
        start = end + 1;
    }
    return ret;
}
}