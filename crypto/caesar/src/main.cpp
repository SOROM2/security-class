#include <iostream>
#include <string>

#include "caesar_analysis.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage:\n%s <caesar ciphered string>\n", argv[0]);
        return 1;
    }

    std::string ct = argv[1];
    
    CaesarAnalysis c(ct);

    puts(c.ClearText().c_str());
}
