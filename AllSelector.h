/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AllSelector.h
 * Author: Pan Piotr
 *
 * Created on 01 May 2016, 18:53
 */

#ifndef ALLSELECTOR_H
#define ALLSELECTOR_H

#include "RequestSelector.h"

namespace ScreamingJazz
{

class AllSelector : public RequestSelector
{
public:
    AllSelector();
    AllSelector(int priority);
    AllSelector(const AllSelector& orig);
    virtual ~AllSelector();
    
    RequestSelector::Selection choose(const HTTPServerRequest& request) const override;

    
private:
    int mPriority = 0;
};

}
#endif /* ALLSELECTOR_H */

