/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   URISelector.h
 * Author: Pan Piotr
 *
 * Created on 09 May 2016, 12:13
 */

#ifndef URISELECTOR_H
#define URISELECTOR_H

#include "RequestSelector.h"
#include "TextSelector.h"
#include <Poco/Net/HTTPServerRequest.h>
#include <vector>
#include <memory>

using namespace std;
using namespace Poco;
using namespace Poco::Net;
namespace ScreamingJazz
{
class URISelector : public RequestSelector
{
    using TSPtr = unique_ptr<TextSelector>;
    struct SelectorCountPair
    {
        SelectorCountPair(TextSelector* ptr, int _usage) : selector(ptr), usage(_usage) { }
                
        TSPtr selector;
        int usage;
    };
public:
    URISelector();
    URISelector(int priority, bool force);
    URISelector(const URISelector& orig);
    virtual ~URISelector();
    
    void addNextSelector(TextSelector* ptr, int usage);
    RequestSelector::Selection choose(const HTTPServerRequest& request) const override;
protected:
    vector<string> seperateRequest(const HTTPServerRequest& request) const;
private:
    vector<SelectorCountPair> mSelectors;
    int mPriority;
    bool mForce;
};
}
#endif /* URISELECTOR_H */

