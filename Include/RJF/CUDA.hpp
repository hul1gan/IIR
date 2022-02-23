/// \file RJFcuda.hpp
/// \author Ольга Рыжкова
#ifndef RRTC_AMBIGUITY_CUDA_HPP_
#define RRTC_AMBIGUITY_CUDA_HPP_

#include <RJF/Data.hpp>
#include <RJF/Interface.hpp>


namespace RRTC
{
    namespace Ambiguity
    {
        class CudaRJF : public InterfaceRJF
        {
        public:
             CudaRJF(float beta);
            ~CudaRJF( ) override = default;

            /// \brief Функция реализующая необходимые вычисления.
            /// \param[out] Y - матрица выходного сигнала.
            /// \param[in] X - матрица входного сигнала.
            /// \param[in] M - число каналов (строк).
            /// \param[in] N - число отсчётов (столбцов).
            ///
            /// \note Указатели Y и X хранят в себе адреса на память доступную устройству.
            void Execute(Complex* Y, const Complex* X, std::size_t M, std::size_t N) override;
        };
    } //Ambiguity
} //RRTC

#endif //RRTC_AMBIGUITY_CUDA_HPP_