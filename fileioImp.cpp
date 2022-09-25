#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include "memberType.h"
#include "fileio.h"
using namespace std;

FileClass::FileClass(string file_name)
{
    inFile.open(file_name);
}

FileClass::~FileClass()
{
    inFile.close();
}

unsigned int getMembersDataFromFile(ifstream &inFile, memberType storeMembers[500])
{
    string line;
    string partLine;
    string memberID;
    string firstName;
    string lastName;
    int booksPurchased;
    double amountSpent;
    double booksDiscount;
    int lengthOfMembership;
    int count;
    getline(inFile, line);
    stringstream ss(line);
    while (getline(inFile, line))
    {
        cout << "line: " << line << '\n';
        storeMembers[count] = memberType();
        ss >> memberID;
        ss >> firstName;
        ss >> lastName;
        ss >> booksPurchased;
        ss >> amountSpent;
        ss >> booksDiscount;
        ss >> lengthOfMembership;
        storeMembers[count].setMemberInfo(memberID,
                                          firstName,
                                          lastName,
                                          booksPurchased,
                                          amountSpent,
                                          booksDiscount,
                                          lengthOfMembership);
        count++;
        getline(inFile, line);
    }
    for (int i = 0; i < 3; i++)
    {
        cout << storeMembers[i].getID() << endl;
    }

    return count;
}
/*
void writeMembersDataToFile(ofstream &outFile, memberType storeMembers[500], unsigned int totalEntry)
{
    ofstream outfile("membersData_output.txt");
}
*/