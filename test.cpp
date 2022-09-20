#include <iostream>

int main(int args, char *argv[])
{
    std::cout << args << '\n';
    for (int i = 0; i < args; i++)
    {
        std::cout << argv[i] << '\n';
    }
    std::ifstream infile;
    infile.open(argv[1]);
    return 0;
}
