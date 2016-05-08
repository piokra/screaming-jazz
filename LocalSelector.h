/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LocalSelector.h
 * Author: Pan Piotr
 *
 * Created on 08 May 2016, 11:12
 */

#ifndef LOCALSELECTOR_H
#define LOCALSELECTOR_H

#include "RequestSelector.h"

using namespace Poco;
using namespace Poco::Net;
using namespace std;
using namespace ScreamingJazz;

class LocalSelector : public RequestSelector
{
public:
    LocalSelector();
    LocalSelector(const LocalSelector& orig);
    virtual ~LocalSelector();
    
    RequestSelector::Selection choose(const HTTPServerRequest& request) const override;

private:

};

#endif /* LOCALSELECTOR_H */

