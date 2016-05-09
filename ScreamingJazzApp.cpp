/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ScreamingJazzApp.cpp
 * Author: Pan Piotr
 * 
 * Created on 30 April 2016, 22:16
 */

//debug
#define __cplusplus 400000L
#include "ScreamingJazzApp.h"
#include <Poco/Util/Option.h>
#include <Poco/Util/OptionCallback.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/ServerSocket.h>
#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include "SimpleFactories.h"
#include "PenisHandler.h"
#include "SelectorRequestHandlerFactory.h"
#include "AllSelector.h"
#include "LocalSelector.h"
#include "TextOutputHandler.h"
#include "URISelector.h"
using SJ = ScreamingJazzApp;
using SJCallback = OptionCallback<ScreamingJazzApp>;

using namespace std;
using namespace Poco;
using namespace Poco::Net;
using namespace ScreamingJazz;
const char* ScreamingJazzApp::name() const
{
    return "Screaming Jazz";
}

void ScreamingJazzApp::defineOptions(OptionSet& options)
{
    Option help("help", "h", "Displays halp");
    help.required(false)
            .repeatable(false)
            .callback(SJCallback(this, &SJ::handleHelp));
    options.addOption(help);
}

void ScreamingJazzApp::handleOption(const std::string& name, const std::string& value)
{
    cout << name << " " << value << endl;
    terminate();
}

void ScreamingJazzApp::handleHelp(const std::string& name, const std::string& value)
{
    cout << "Herpuru" << name << " " << value << endl;
}

void ScreamingJazzApp::initialize(Application& app)
{
    Application::initialize(app);
}

void ScreamingJazzApp::reinitialize(Application& self)
{
    Application::reinitialize(self);
}

void ScreamingJazzApp::uninitialize()
{
    Application::uninitialize();
}

int ScreamingJazzApp::main(const std::vector<std::string>& args)
{
    cout << "Hello boys" << endl;
    Poco::UInt16 port = 9999;
    HTTPServerParams* pParams = new HTTPServerParams;
    pParams->setMaxQueued(100);
    pParams->setMaxThreads(16);
    ServerSocket svs(port); // set-up a server socket
    
    auto handler = new SelectorRequestHandlerFactory();
    handler->addSelectorAndFactory(new URISelector(), new SimpleRequestHandlerFactory<TextOutputHandler, string>("Hello m8"));
    handler->addSelectorAndFactory(new AllSelector(), new SimpleRequestHandlerFactory<PenisHandler>());
    handler->addSelectorAndFactory(new LocalSelector(), new SimpleRequestHandlerFactory<TextOutputHandler, string>("Hello boys"));
    HTTPServer srv(handler, svs, pParams);
    // start the HTTPServer
    srv.start();
    waitForTerminationRequest();
    // Stop the HTTPServer
    srv.stop();
    cout << "Good bye" << endl;
}
