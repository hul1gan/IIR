/// \file CUDATest.cu
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

TEST_GROUP(RJFTestGroup)
{ 

};

TEST(RJFTestGroup, testcuda)
{ 
    int m = 1024;
    int n = 100;

    Array X;
    RRTC::Ambiguity::ReadArray("byteArrayX.bin", X);

    Array Y;
    RRTC::Ambiguity::ReadArray("byteArrayY.bin", Y);

    Array expd;
    RRTC::Ambiguity::ReadArray("byteArrayY.bin", expd);
 
    int size = n * m * sizeof(RRTC::Complex);
     
    RRTC::Complex * dX = nullptr;
    RRTC::Complex * dY = nullptr;
     
    cudaMalloc(&dX, size);
    cudaMalloc(&dY, size);
     
    cudaMemcpy(dX, X.data(), size, cudaMemcpyHostToDevice);

    RRTC::Ambiguity::CudaRJF filter(0.9);
    
    auto begin = std::chrono::steady_clock::now();
    filter.Execute(dY, dX, m, n);
    auto end = std::chrono::steady_clock::now();

       auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
       std::cout << "The time: " << elapsed_ms.count() << " ";

    cudaMemcpy(Y.data(), dY, size, cudaMemcpyDeviceToHost);

    float STDREIM = RRTC::Ambiguity::calculatingDeviation(m, n, Y.data(), expd.data());

    double checking = 1E-5;

    DOUBLES_EQUAL(0, STDREIM, checking); 

    cudaFree(dX);
    cudaFree(dY);
}
