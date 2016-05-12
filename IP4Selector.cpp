/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IP4Selector.cpp
 * Author: Joanna Cichowska
 * 
 * Created on 12 maja 2016, 13:24
 */

#include "IP4Selector.h"
namespace ScreamingJazz
{

IP4Selector::IP4Selector(const string& ip) : IP4Selector(ip, false, 0)
{
    
}

IP4Selector::IP4Selector(const string& ip,bool force, int priority) : mIP(ip), mForce(force), mPriority(priority)
{
    
}

IP4Selector::IP4Selector(const IP4Selector& orig)
{
}

IP4Selector::~IP4Selector()
{
}

RequestSelector::Selection IP4Selector::choose(const HTTPServerRequest& request) const
{
    return {(request.clientAddress().host() == IPAddress::parse(mIP)), mForce, mPriority};
}


}
