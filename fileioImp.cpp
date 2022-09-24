#include <fileio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

FileClass::FileClass(string file_name)
{
    inFile.open(file_name);
}

FileClass::~FileClass()
{
    inFile.close();
}

bool getNextField(string &line, int &index, string &subString)
{
}
unsigned int getMembersDataFromFile(ifstream &inFile, memberType storeMembers[500])
{
    string line;
    string partLine;
    getline(inFile, line);
    stringstream ss(line);
}
void writeMembersDataToFile(ofstream &outFile, memberType storeMembers[500], unsigned int totalEntry)
{
    ofstream outfile("membersData_output.txt");
}