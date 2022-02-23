/// \file TestFunctions.cpp
/// \author Ольга Рыжкова
#include <RJF/TestFunctions.hpp>

namespace RRTC
{   
    namespace Ambiguity
    {
        float calculatingDeviation(int m, int n, RRTC::Complex* Y, RRTC::Complex* expd)
        {
            RRTC::Complex arithmeticMean = {0, 0};
            size_t lenghtSignals = m * n;

            for(int i = 0; i < m; i++)
            {
                RRTC::Complex* y = (Y + i * n);
                RRTC::Complex* expdY = (expd + i * n);
                RRTC::Complex* DifarithmeticMean = (expd + i * n);

                for(int k = 0; k < n; k++)
                {
                    DifarithmeticMean[k] = y[k] - expdY[k];
                    arithmeticMean = arithmeticMean + DifarithmeticMean[k];
                }
            }
                arithmeticMean = arithmeticMean / lenghtSignals;
                RRTC::Complex Dispersion = {0, 0};

                for(int i = 0; i < m; i++)
                {
                    RRTC::Complex* DifarithmeticMean = (expd + i * n);

                    for(int k = 0; k < n; k++)
                    {
                        Dispersion = Dispersion + (DifarithmeticMean[k] - arithmeticMean) * (DifarithmeticMean[k] - arithmeticMean);
                    }
                }
                double stdReIm = sqrt((Dispersion.im + Dispersion.re) / (lenghtSignals - 1));
                return stdReIm;
        }


        void ReadArray(const std::string& filename, Array& array)
        {
            std::fstream in;
            in.open(filename, std::fstream::binary | std::fstream::in);
            int size = 0;
            in.seekg (0, std::ios::end);
            size = in.tellg();
            in.seekg (0, std::ios::beg);
            array.reserve(size / sizeof(RRTC::Complex));
            in.read(reinterpret_cast<char*>(array.data()), size);
            in.close();
        }
    } //Ambiguity
} //RRTC






