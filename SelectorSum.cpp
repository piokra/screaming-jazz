/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SelectorSum.cpp
 * Author: Pan Piotr
 * 
 * Created on 02 May 2016, 01:33
 */

#include "SelectorSum.h"
namespace ScreamingJazz
{

SelectorSum::SelectorSum()
{
}

SelectorSum::SelectorSum(const SelectorSum& orig)
{
}

SelectorSum::~SelectorSum()
{
}

RequestSelector::Selection SelectorSum::choose(const HTTPServerRequest& request) const
{
    Selec ret{false, false, 0};
    for (auto it = getSelectors().begin(); it != getSelectors().end(); ++it)
    {

        auto t = (*it)->choose(request);
        ret.wants |= t.wants;
        ret.force |= t.force;
        ret.priority = max(ret.priority, t.priority);

        if (ret.force == true) break;
    }

    return ret;
}


}