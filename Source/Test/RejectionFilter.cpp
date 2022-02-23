/// \file RejectionFilter.cpp
/// \author Ольга Рыжкова
#include <RJF/Default.hpp>
#include <CppUTest/TestHarness.h>
#include <RJF/TestFunctions.hpp>
#include <RJF/CUDA.hpp>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>


using namespace RRTC;
using namespace Ambiguity;



TEST_GROUP(RJFTestGroup)
{ 
};

TEST(RJFTestGroup, test)
{ 

   int m = 3;
   int n = 10000;

    Array X;
    RRTC::Ambiguity::ReadArray("byteArrayX.bin", X);

    Array Y;
    RRTC::Ambiguity::ReadArray("byteArrayY.bin", Y);

    Array expd;
    RRTC::Ambiguity::ReadArray("byteArrayY.bin", expd);

    RRTC::Ambiguity::DefaultRJF filter(0.9);

    filter.Execute(Y.data(), X.data(), m, n);
       
    float STDREIM = RRTC::Ambiguity::calculatingDeviation(m, n, Y.data(), expd.data());  
    double checking = 1E-5;
    DOUBLES_EQUAL(checking, STDREIM, checking); 
    
};





























