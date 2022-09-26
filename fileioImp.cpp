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
    outFile.close();
}

unsigned int getMembersDataFromFile(ifstream &inFile, memberType storeMembers[500])
{
    string line;
    string memberID = "";
    string firstName = "";
    string lastName = "";
    int booksPurchased = 0;
    double amountSpent = 0.0;
    double booksDiscount = 0.0;
    int lengthOfMembership = 0;
    int count = 0;
    getline(inFile, line);
    stringstream ss(line);
    while (getline(inFile, line))
    {
        storeMembers[count] = memberType();
        ss.str(line);
        ss >> memberID;
        ss >> firstName;
        ss >> lastName;
        ss >> booksPurchased;
        ss >> amountSpent;
        ss >> lengthOfMembership;
        ss >> booksDiscount;
        storeMembers[count].setMemberInfo(memberID, firstName, lastName, booksPurchased, amountSpent, booksDiscount, lengthOfMembership);
        count++;
    }
    return count;
}

void writeMembersDataToFile(ofstream &outFile, memberType storeMembers[500], unsigned int totalEntry)
{
    // ofstream outfile("membersData_output.txt");
    // totalEntry = 1;
}
