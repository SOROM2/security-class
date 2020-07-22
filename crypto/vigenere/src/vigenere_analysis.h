#ifndef VIGENERE_ANALYSIS_H
#define VIGENERE_ANALYSIS_H

#include <iostream>
#include <string>
#include <cctype>

class VigenereAnalysis {
    private:
        std::string cipherText;
        std::string clearText;
        std::string key;

        std::string encode(std::string str);
        std::string decode(std::string str);
    public:
        VigenereAnalysis(std::string str, int keylen);
        VigenereAnalysis(std::string str, std::string key);

        std::string CipherText();
        std::string ClearText();
};

#endif
