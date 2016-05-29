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
#include "StringUtil.h"
#include <Poco/Net/HTTPServerRequest.h>
#include <iostream>
#include <Poco/URI.h>
namespace ScreamingJazz
{
using namespace std;
using namespace Poco;
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
        if(selector==mSelectors.end())
        {
            return {false,false, -1};
        }
        result &= selector->selector->matches(*it);
        countsThisSelector++;
        auto next = selector;
        ++next;
        if((countsThisSelector == selector->usage))
        {
            countsThisSelector = 0;
            ++selector;
        }
        if(result==false)
        {
            return {false,false, -1};
        }
    }
    if(mSelectors.size()!=0 && strings.size()==0)
    {
        return {false,false,-1};
    }
    
    return {true,mForce,mPriority};

}

vector<string> URISelector::seperateRequest(const HTTPServerRequest& request) const
{
    vector<string> ret;
    vector<string::size_type> pos;
    string uri_t = request.getURI();
    string uri = "";
    URI::decode(uri_t,uri);
    StringUtil::split(uri,"/?",ret);
    return ret;
}
}