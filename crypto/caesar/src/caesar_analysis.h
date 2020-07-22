#ifndef CAESAR_ANALYSIS_H
#define CAESAR_ANALYSIS_H

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <limits>
#include <tuple>

#include "chisqr.h"

class CaesarAnalysis {
    private:
        std::string cipherText;
        std::string clearText;
        std::vector<std::tuple<std::string, double>> chiTable;
        ChiSqr chi;
        
        std::string encode(std::string str, int i);
    public:
        CaesarAnalysis(std::string str);
        std::string CipherText();
        std::string ClearText();
};

#endif
