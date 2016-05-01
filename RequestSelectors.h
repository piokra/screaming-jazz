/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RequestSelectors.h
 * Author: Pan Piotr
 *
 * Created on 02 May 2016, 01:19
 */

#ifndef REQUESTSELECTORS_H
#define REQUESTSELECTORS_H

#include "RequestSelector.h"
#include <vector>
#include <memory>
namespace ScreamingJazz
{
using namespace std;

class RequestSelectors : public RequestSelector
{
protected:
    using Selec = RequestSelector::Selection;
    using RSPtr = unique_ptr<RequestSelector>;
public:

    void add(RequestSelector* selector)
    {
        mSelectors.push_back(RSPtr(selector));
    }

    void operator+=(RequestSelector* selector)
    {
        add(selector);
    }

    const vector<RSPtr>& getSelectors() const
    {
        return mSelectors;
    }
private:
    vector<RSPtr> mSelectors;
};
}
#endif /* REQUESTSELECTORS_H */

