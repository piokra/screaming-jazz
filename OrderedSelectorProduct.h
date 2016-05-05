/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OrderedSelectorProduct.h
 * Author: Pan Piotr
 *
 * Created on 02 May 2016, 00:58
 */

#ifndef ORDEREDSELECTORPRODUCT_H
#define ORDEREDSELECTORPRODUCT_H

#include "RequestSelector.h"
#include <vector>
#include <memory>
namespace ScreamingJazz
{
using namespace std;
using namespace Poco;
using namespace Poco::Net;
class OrderedSelectorProduct : public RequestSelector
{
protected:
    using Selec = RequestSelector::Selection;
    using RSPtr = unique_ptr<RequestSelector>;
public:
    OrderedSelectorProduct();
    OrderedSelectorProduct(const OrderedSelectorProduct& orig);
    virtual ~OrderedSelectorProduct();
    
    RequestSelector::Selection choose(const HTTPServerRequest& request) const override;
    
private:
    vector<RSPtr> mSelectors;
};

}
#endif /* ORDEREDSELECTORPRODUCT_H */

