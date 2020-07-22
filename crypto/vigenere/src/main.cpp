#include <iostream>
#include <string>

#include "vigenere_analysis.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage:\n%s <vigenere encrypted string> <key>\n", argv[0]);
        return 1;
    }

    VigenereAnalysis v(argv[1], argv[2]);

    printf("%s\n", v.ClearText().c_str());

    return 0;
}
