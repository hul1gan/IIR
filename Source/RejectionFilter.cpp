/// \file RejectionFilter.cpp
/// \author Ольга Рыжкова
#include <RJF/Default.hpp>



namespace RRTC
{
    namespace Ambiguity
    {
        DefaultRJF::DefaultRJF(float beta)
            :InterfaceRJF(beta){}


     
        void DefaultRJF::Execute(Complex* Y, const Complex* X, std::size_t M, std::size_t N)
        {
            for (std::size_t m = 0; m < M; ++m)
            {
                const Complex* x = (X + m * N);
                Complex* y = (Y + m * N);
                
                y[0] = {0, 0};
                
                for (std::size_t n = 1; n < N; ++n)
                {
                    y[n] = (x[n] - x[n - 1]) + y[n - 1] * beta;
                }
            }
        }

    } //Ambiguity
} //RRTC


