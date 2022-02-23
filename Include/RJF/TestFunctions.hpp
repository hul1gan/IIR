/// \file TestFunctions.hpp
/// \author Ольга Рыжкова
#ifndef TESTFUNCTIONS_HPP_
#define TESTFUNCTIONS_HPP_

#include <RJF/Data.hpp>
#include <CppUTest/TestHarness.h>

#include <vector>
#include <cmath>
#include <fstream>

using Array = std::vector<RRTC::Complex>;

namespace RRTC
{	
	namespace Ambiguity
    {
		float calculatingDeviation(int m, int n, RRTC::Complex* Y, RRTC::Complex* expd);
		void ReadArray(const std::string& filename, Array& array);
	}
}

#endif //TESTFUNCTIONS_HPP_