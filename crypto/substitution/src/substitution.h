#ifndef SUBSTITUTION_H
#define SUBSTITUTION_H

#include <string>
#include <cctype>

class Substitution {
    private:
        std::string plainAlphabet;
        std::string subAlphabet;

        void lower(std::string& str);
    public:
        Substitution(std::string alphabet);
        std::string Encode(std::string plainText);
        std::string Decode(std::string cipherText);
};

#endif
