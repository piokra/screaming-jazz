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

#include "OrderedSelectorProduct.h"
namespace ScreamingJazz
{

OrderedSelectorProduct::OrderedSelectorProduct()
{
}

OrderedSelectorProduct::OrderedSelectorProduct(const OrderedSelectorProduct& orig)
{
}

OrderedSelectorProduct::~OrderedSelectorProduct()
{
}

RequestSelector::Selection OrderedSelectorProduct::choose(const HTTPServerRequest& request) const
{
    Selec ret{true,false,100000};
    for(auto it = mSelectors.begin(); it!=mSelectors.end(); ++it)
    {
        
        auto t = (*it)->choose(request);
        ret.wants &= t.wants;
        ret.force |= t.force;
        ret.priority = min(ret.priority,t.priority);
    }
}

}