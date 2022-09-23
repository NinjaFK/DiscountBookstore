#include <iostream>
using namespace std;

/*
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
*/

bool checkID(string ID)
{
    if (ID.size() != 6)
    {
        return 0;
    }
    for (int i = 0; i < 3; i++)
    {
        if (ID[i] < 65 || (ID[i] > 90 && ID[i] < 97) || ID[i] > 122)
        {
            return 0;
        }
    }
    for (int i = 3; i < 6; i++)
    {
        if (ID[i] < 48 || ID[i] > 57)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    cout << checkID("apc123") << endl;
    return 0;
}