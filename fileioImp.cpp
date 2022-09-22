#include <fileio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

FileClass::FileClass(string file_name)
{
}

FileClass::~FileClass()
{
}

bool getNextField(string &line, int &index, string &subString)
{
}
unsigned int getMembersDataFromFile(ifstream &inFile, memberType storeMembers[500])
{
}
void writeMembersDataToFile(ofstream &outFile, memberType storeMembers[500], unsigned int totalEntry)
{
}