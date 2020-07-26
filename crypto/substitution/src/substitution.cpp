#include "substitution.h"

Substitution::Substitution(std::string alphabet)
{
    int i;
    this->plainAlphabet = "abcdefghijklmnopqrstuvwxyz";
    this->subAlphabet = alphabet;

    this->lower(this->subAlphabet);
}

std::string Substitution::Encode(std::string plainText)
{
    int i;
    std::string newString = plainText;
    
    this->lower(newString);

    for (i = 0; i < newString.size(); i++)
    {
        if (newString[i] != ' ')
            newString[i] = this->subAlphabet[newString[i] - 97];
    }

    return newString;
}

std::string Substitution::Decode(std::string cipherText)
{
    int i;
    int j;
    std::string newString = cipherText;

    this->lower(newString);

    for (i = 0; i < newString.size(); i++)
    {

        if (newString[i] != ' ')
        {
            for (j = 0; j < this->subAlphabet.size(); j++)
            {
                if (this->subAlphabet[j] != newString[i])
                    continue;
                else
                    break;
            }

            newString[i] = this->plainAlphabet[j];
        }
    }

    return newString;
}

void Substitution::lower(std::string& str)
{
    int i;
    for (i = 0; i < str.size(); i++)
        str[i] = std::tolower(str[i]);
}
