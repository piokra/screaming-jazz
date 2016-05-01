/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ScreamingJazzApp.h
 * Author: Pan Piotr
 *
 * Created on 30 April 2016, 22:16
 */

#ifndef SCREAMINGJAZZAPP_H
#define SCREAMINGJAZZAPP_H

#include <Poco/Util/ServerApplication.h>

using namespace Poco;
using namespace Poco::Util;
class ScreamingJazzApp : public ServerApplication
{
public:
    
    virtual const char* name() const;

    virtual void initialize(Application& app);

    virtual void reinitialize(Application& self);
    
    virtual void uninitialize();
    
    virtual void handleOption(const std::string& name, const std::string& value);

    virtual void defineOptions(OptionSet& options);

    virtual int main(const std::vector<std::string>& args);

protected:
    virtual void handleHelp(const std::string& name, const std::string& value);
private:
};

#endif /* SCREAMINGJAZZAPP_H */

