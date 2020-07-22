#ifndef CHISQR_H
#define CHISQR_H

#include <cctype>
#include <string>
#include <array>
#include <cmath>

class ChiSqr {
    private:
        std::array<double, 26> expected;
    
    public:
        ChiSqr()
        {
            this->expected = {
                0.08167, 0.01492, 0.02782, 0.04253,
                0.12702, 0.02228, 0.02015, 0.06094,
                0.06966, 0.00153, 0.00772, 0.04025,
                0.02406, 0.06749, 0.07507, 0.01929,
                0.00095, 0.05987, 0.06327, 0.09056,
                0.02758, 0.00978, 0.02360, 0.00150,
                0.01974, 0.00074};
        };

        double GetSqr(std::string str)
        {
            int i;
            std::string text = str;
            std::array<int, 26> counts;

            for (i = 0; i < counts.size(); i++)
                counts[i] = 0;

            for (i = 0; i < text.size(); i++)
                counts[text[i] - 97]++;
            int total = i;

            double sum = 0.0;
            for (i = 0; i < counts.size(); i++)
                sum += (std::pow((counts[i] - total * expected[i]), 2) / (total * expected[i]));
            
            return sum;
        };
};

#endif
