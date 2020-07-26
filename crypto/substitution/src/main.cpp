#include <iostream>
#include <string>

#include "substitution.h"

long openFile(char* path, std::string& contents)
{
    FILE* file;
    long size;
    int c;

    file = std::fopen(path, "r");
    
    if (!file)
    {
        fprintf(stderr, "%s could not be opened.\n", path);
        return -1L;
    }

    std::fseek(file, 0L, SEEK_END);
    size = std::ftell(file);
    std::rewind(file);

    while ((c = std::fgetc(file)) != EOF)
    {
        contents.push_back(c);
    }

    std::fclose(file);

    return size;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage:\n%s <message file> <key file>\n", argv[0]);
        return 1;
    }

    std::string message;
    std::string alphabet;

    if (openFile(argv[1], message) == -1)
        return 1;

    if (openFile(argv[2], alphabet) == -1)
        return 1;

    Substitution s(alphabet);
    std::string decoded = s.Decode(message);  

    std::cout << decoded << std::endl;

    return 0;
}


