/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OrderedSelectorProduct.cpp
 * Author: Pan Piotr
 * 
 * Created on 02 May 2016, 00:58
 */

#include "SelectorProduct.h"
namespace ScreamingJazz
{

SelectorProduct::SelectorProduct()
{
}

SelectorProduct::SelectorProduct(const SelectorProduct& orig)
{
}

SelectorProduct::~SelectorProduct()
{
}

RequestSelector::Selection SelectorProduct::choose(const HTTPServerRequest& request) const
{
    Selec ret{true, false, 100000};
    for (auto it = getSelectors().begin(); it != getSelectors().end(); ++it)
    {
        
        auto t = (*it)->choose(request);
        ret.wants &= t.wants;
        ret.force |= t.force;
        ret.priority = min(ret.priority, t.priority);

        if (ret.wants == false) break;
    }

    return ret;
}



}