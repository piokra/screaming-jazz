/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Pan Piotr
 *
 * Created on 18 April 2016, 12:35
 */
#include <cstdlib>
#include <iostream>

#include "ScreamingJazzApp.h"
#include "SimpleFactories.h"
#include "PenisHandler.h"
using namespace std;
using namespace Poco;
using namespace Poco::Util;
using namespace ScreamingJazz;
int main(int argc, char** argv)
{
    ScreamingJazzApp sja;
    SimpleRequestHandlerFactory<PenisHandler, int> p(3);
    
    return sja.run(argc,argv);
}
