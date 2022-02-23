/// \file RejectionFilter.hpp
/// \author Ольга Рыжкова
#ifndef RRTC_AMBIGUITY_REJECTIONFILTER_HPP_
#define RRTC_AMBIGUITY_REJECTIONFILTER_HPP_

#include <RJF/Data.hpp>
#include <RJF/Interface.hpp>

#include <cstring>


namespace RRTC
{   
    namespace Ambiguity
    {
        class DefaultRJF : public InterfaceRJF
        {
        public:
             DefaultRJF(float beta);
            ~DefaultRJF( ) override = default;

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

#endif // RRTC_AMBIGUITY_REJECTIONFILTER_HPP_

