/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AllSelector.cpp
 * Author: Pan Piotr
 * 
 * Created on 01 May 2016, 18:53
 */

#include "AllSelector.h"

namespace ScreamingJazz
{

AllSelector::AllSelector()
{
}

AllSelector::AllSelector(const AllSelector& orig)
{
}

AllSelector::~AllSelector()
{
}

RequestSelector::Selection AllSelector::choose(const HTTPServerRequest& request) const
{
    return {true, false, 0};
}


}