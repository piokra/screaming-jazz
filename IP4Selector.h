/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IP4Selector.h
 * Author: Joanna Cichowska
 *
 * Created on 12 maja 2016, 13:24
 */

#ifndef IP4SELECTOR_H
#define IP4SELECTOR_H

#include "RequestSelector.h"
#include <Poco/Foundation.h>
#include <string>

namespace ScreamingJazz
{
using namespace Poco;
using namespace std;
class IP4Selector : public RequestSelector
{
public:
    IP4Selector(const string& ip);
    IP4Selector(const string& ip, bool force, int priority);
    IP4Selector(const IP4Selector& orig);
    virtual ~IP4Selector();
    
    RequestSelector::Selection choose(const HTTPServerRequest& request) const override;

private:
    bool mForce;
    int mPriority;
    string mIP;
};
}
#endif /* IP4SELECTOR_H */

