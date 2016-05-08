/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LocalSelector.cpp
 * Author: Pan Piotr
 * 
 * Created on 08 May 2016, 11:12
 */

#include "LocalSelector.h"

LocalSelector::LocalSelector()
{
}

LocalSelector::LocalSelector(const LocalSelector& orig)
{
}

LocalSelector::~LocalSelector()
{
}

RequestSelector::Selection LocalSelector::choose(const HTTPServerRequest& request) const
{
    if (request.clientAddress().host().isLoopback() || request.clientAddress().host().isSiteLocal())
    {
        return {true, false, 1};
    }
        
    return {false,false,0};   
}
