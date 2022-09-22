#include <iostream>
using namespace std;

int main(int args, char *argv[])
{
    cout << args << '\n';
    for (int i = 0; i < args; i++)
    {
        cout << argv[i] << '\n';
    }
    ifstream infile;
    infile.open(argv[1]);
    return 0;
}
