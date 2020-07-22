#include "vigenere_analysis.h"

VigenereAnalysis::VigenereAnalysis(std::string str, int keylen)
{
    this->cipherText = str;
}

VigenereAnalysis::VigenereAnalysis(std::string str, std::string key)
{
    this->cipherText = str;
    this->key = key;
    this->clearText = this->decode(this->cipherText);
}

std::string VigenereAnalysis::encode(std::string str)
{
    int i;
    std::string text = str;
    std::string decodedString;

    for (i = 0; i < text.size(); i++)
        text[i] = std::tolower(text[i]);

    for (i = 0; i < text.size(); i++)
    {
        int zText = text[i] - 97;
        int zKey = this->key[i % this->key.size()] - 97;
        int zNew = ((zText + zKey) % 26) + 97;
        decodedString.push_back(zNew);
    }

    return decodedString;
}

std::string VigenereAnalysis::decode(std::string str)
{
    int i;
    std::string text = str;
    std::string decodedString;

    for (i = 0; i < text.size(); i++)
        text[i] = std::tolower(text[i]);

    for (i = 0; i < text.size(); i++)
    {
        int zText = text[i] - 97;
        int zKey = this->key[i % this->key.size()] - 97;
        int zNew = (zKey > zText) ? (26 - (zKey - zText)) : ((zText - zKey) % 26);
        zNew += 97;
        decodedString.push_back(zNew);
    }

    return decodedString;
}

std::string VigenereAnalysis::CipherText()
{
    return this->cipherText;
}

std::string VigenereAnalysis::ClearText()
{
    return this->clearText;
}
