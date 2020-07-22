#include "caesar_analysis.h"

CaesarAnalysis::CaesarAnalysis(std::string str)
{
    int i;
    this->cipherText = str;

    std::tuple<std::string, double> tmpTuple;
    std::string tmpString;
    double tmpDouble;

    for (i = 0; i < 26; i++)
    {
        tmpString = this->encode(str, i);
        tmpDouble = this->chi.GetSqr(tmpString);
        tmpTuple = std::make_tuple(tmpString, tmpDouble);
        chiTable.push_back(tmpTuple);
    }

    double min = std::numeric_limits<double>::max();
    int iMin = -1;
    for (i = 0; i < chiTable.size(); i++)
    {
        if (std::get<1>(chiTable[i]) < min) 
        {
            min = std::get<1>(chiTable[i]);
            iMin = i;
        }
    }

    this->clearText = std::get<0>(chiTable[iMin]);
}

std::string CaesarAnalysis::encode(std::string str, int shift)
{
    int i;
    std::string text;
    std::string shiftedString;
    
    for (i = 0; i < str.size(); i++)
    {
        text.push_back(std::tolower(str[i]));
    }

    for (i = 0; i < text.size(); i++)
    {
        shiftedString.push_back((((text[i] - 97) + shift) % 26) + 97);
    }

    return shiftedString;
}

std::string CaesarAnalysis::CipherText()
{
    return this->cipherText;
}

std::string CaesarAnalysis::ClearText()
{
    return this->clearText;
}
