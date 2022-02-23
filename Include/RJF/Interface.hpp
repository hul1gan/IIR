/// \file Interface.hpp
/// \author Ольга Рыжкова
#ifndef RRTC_AMBIGUITY_INTERFACE_HPP_
#define RRTC_AMBIGUITY_INTERFACE_HPP_

#include <RJF/Data.hpp>

#include <cstring>


namespace RRTC
{	
	namespace Ambiguity
    {
    	/// \class Interface
        /// \Класс-интерфейс для переопределения функции Execute
		class InterfaceRJF 
		{
		public:
            InterfaceRJF(float beta);
        
            virtual ~InterfaceRJF( ) = default;

			/// \brief Функция реализующая необходимые вычисления.
            /// \param[out] Y - матрица выходного сигнала.
            /// \param[in] X - матрица входного сигнала.
            /// \param[in] M - число каналов (строк).
            /// \param[in] N - число отсчётов (столбцов).
            ///
            /// \note Указатели Y и X хранят в себе адреса на память доступную устройству.
	    	virtual void Execute(RRTC::Complex* Y, const RRTC::Complex* X, std::size_t M, std::size_t N) = 0;

        protected:
            float beta;
		}; 
   } // Ambiguity
} // RRTC

#endif //RRTC_AMBIGUITY_INTERFACE_HPP_
