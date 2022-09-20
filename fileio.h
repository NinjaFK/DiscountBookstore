#ifndef H_fileInfo
#define H_fileInfo

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "memberType.h"

using namespace std;

/**
 * @brief
 *
 */
class FileClass
{

public:
    ifstream inFile;
    ofstream outFile;
    bool fileError;

    FileClass(string file_name); //constructor with a single parameter
    ~FileClass(); //Destructor
};

//global functions
bool getNextField(string &line, int &index, string &subString);
unsigned int getMembersDataFromFile(ifstream &inFile, memberType storeMembers[500]);
void writeMembersDataToFile(ofstream &outFile, memberType storeMembers[500], unsigned int totalEntry);
#endif // H_fileInfo
