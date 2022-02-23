/// \file RJFcuda.cu
/// \author Ольга Рыжкова
#include <RJF/Default.hpp>
#include <RJF/Interface.hpp>
#include <RJF/Data.hpp>
#include <RJF/CUDA.hpp>


namespace Device
{
    using Complex = RRTC::Complex;

     __device__ Complex Plus(const Complex& left, const Complex& right)
     {
          return {left.re + right.re, left.im + right.im};
     } 

     __device__ Complex Minus(const Complex& left, const Complex& right)
     {
          return {left.re - right.re, left.im - right.im};
     } 

     __device__ Complex Mult(const Complex& left, const float k2)
     {
          return {left.re * k2, left.im * k2};
     } 


    __global__ void RJF(Complex* Y, const Complex* X, std::size_t M, std::size_t N, float beta)
    {
        int idx = blockIdx.x * blockDim.x + threadIdx.x;
        if (idx < M)
        {
            const RRTC::Complex* x = (X + idx * N);
            RRTC::Complex* y = (Y + idx * N);
            
            y[0] = {0, 0};
            
            for (std::size_t n = 1; n < N; ++n)
            {         
                 y[n] = Plus(Mult(y[n - 1], beta), Minus(x[n], x[n - 1]));
            }   
        }
    }    
} //Device

namespace RRTC
{
    namespace Ambiguity
    {
        void CudaRJF::Execute(Complex* Y, const Complex* X, std::size_t M, std::size_t N)
        {
            Device::RJF<<<std::ceil((double(M) * N)/128), 128>>>(Y, X, M, N, this-> beta);
        }
    } //Ambiguity
} //RRTC







