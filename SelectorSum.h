/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SelectorSum.h
 * Author: Pan Piotr
 *
 * Created on 02 May 2016, 01:33
 */

#ifndef SELECTORSUM_H
#define SELECTORSUM_H

#include "RequestSelectors.h"

namespace ScreamingJazz
{

class SelectorSum : public RequestSelectors
{
public:
    SelectorSum();
    SelectorSum(const SelectorSum& orig);
    virtual ~SelectorSum();
    
    RequestSelector::Selection choose(const HTTPServerRequest& request) const override;

private:

};

}
#endif /* SELECTORSUM_H */

