/// \file Data.hpp
/// \author Ольга Рыжкова
#ifndef RRTC_COMPLEX_HPP_
#define RRTC_COMPLEX_HPP_


namespace RRTC
{
    /// \struct Complex
    /// \brief Класс, реализующий комплесное числа.
    struct Complex
    {
        float re; ///< Вещественная часть.
        float im; ///< Мнимая часть
    };
    
    inline Complex operator -(const Complex& left, const Complex& right)
    {
        return {left.re - right.re, left.im - right.im};
    }

    inline Complex operator +(const Complex& left, const Complex& right)
    {
        return {left.re + right.re, left.im + right.im};
    }

    inline Complex operator *(const Complex& left, const float beta)
    {
        return {left.re * beta, left.im * beta};
    }

    inline Complex operator /(const Complex& left, const float beta)
    {
        return {left.re / beta, left.im / beta};
    }

    inline Complex operator *(const Complex& left, const Complex& right)
    {
        return {(left.re * right.re) - (left.im * right.im), (left.re * right.im) + (left.im * right.re)};
    }
}; //RRTC

#endif //RRTC_COMPLEX_HPP_