/*
    Name: Brian, 5008139573, 1005, 2
    Description: Discount bookstore
    Input: membersdata.txt
    Output: membersdata_output.txt
*/
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
    // Opens file with file_name
    inFile.open(file_name);
    // checks if file is vaild then prints if its not
    if (!inFile)
    {
        cout << "################################"
             << "###########################"
             << '\n'
             << "Error : Input file not present : "
             << file_name << '\n'
             << "#################################"
             << "##########################"
             << '\n';
        inFile.close();
    }
    // opens the the output file
    outFile.open("membersData_output.txt");
}
// deconstucts by closing
// both files
FileClass::~FileClass()
{
    // close both files
    inFile.close();
    outFile.close();
}
// returns unsigned int of
// many members that are read
unsigned int getMembersDataFromFile(ifstream &inFile,
                                    memberType storeMembers[500])
{
    if (!inFile.is_open())
    {
        return 0;
    }
    // creates all vars needed to put into
    //  storeMembers
    string line;
    string memberID = "";
    string firstName = "";
    string lastName = "";
    int booksPurchased = 0;
    double amountSpent = 0.0;
    double booksDiscount = 0.0;
    int lengthOfMembership = 0;
    // count is what gets returned
    int count = 0;
    // gets rid of first line
    getline(inFile, line);
    stringstream ss(line);
    // while loop while the next line is vaild
    while (getline(inFile, line))
    {
        // creates memberType object into storemembers
        storeMembers[count] = memberType();
        // sets ss to line and puts
        // data in to each var
        // stringstream also typecasts
        // so doing this is easier
        ss.str(line);
        ss >> memberID;
        ss >> firstName;
        ss >> lastName;
        ss >> booksPurchased;
        ss >> amountSpent;
        ss >> lengthOfMembership;
        ss >> booksDiscount;
        // puts data from var to array of memberType
        storeMembers[count].setMemberInfo(memberID, firstName,
                                          lastName, booksPurchased,
                                          amountSpent, booksDiscount,
                                          lengthOfMembership);
        count++;
    }
    return count;
}
// writes to outputfile using amount
// from getMembersDataFromFile and
// addeds extra data like amount of books
// vaild members and money
void writeMembersDataToFile(ofstream &outFile,
                            memberType sm[500], unsigned int totalEntry)
{
    if (totalEntry == 0)
    {
        return;
    }
    // creates var for vaild amount, books, total money
    int vaild = 0;
    int books = 0;
    double total = 0.0;
    // prints first line of file
    outFile << "ID"
            << " firstName"
            << " lastName"
            << " bookCount"
            << " purchaseBill"
            << " LengthofMemberShip"
            << " discountPercentage"
            << " discountedAmount"
            << " finalPrice" << '\n';

    // for loop that prints all data to outfile
    for (int i = 0; i < int(totalEntry); i++)
    {
        // prints out file
        // with precision set to 2
        // also uses fixed to not
        // use scienctific notation
        // and adds a space in between
        outFile << setprecision(2) << fixed
                << sm[i].getID() << " " << sm[i].getFirstName() << " "
                << sm[i].getLastName() << " "
                << sm[i].getBookCount() << " "
                << sm[i].getPurchaseBill() << " "
                << sm[i].getLenghtOfMembership() << " "
                << sm[i].getDiscount() << " ";
        // checks for invalid id
        if (!sm[i].checkID(sm[i].getID()))
        {
            outFile << "invalid ID" << '\n';
        }
        // checks for invalid BookCount
        else if (!sm[i].checkBookCount(sm[i].getBookCount()))
        {
            outFile << "invalid Book purchased count" << '\n';
        }
        // checks for invalid AmountSpent
        // this takes two inputs
        else if (!sm[i].checkAmountSpent(sm[i].getBookCount(),
                                         sm[i].getPurchaseBill()))
        {
            outFile << "invalid purchaseBill" << '\n';
        }
        // checks for invalid Membership
        else if (!sm[i].checkMembership(sm[i].getLenghtOfMembership()))
        {
            outFile << "invalid Length Of Membership" << '\n';
        }
        // checks for invalid Discount
        else if (!sm[i].checkDiscount(sm[i].getDiscount()))
        {
            outFile << "invalid discountPercentage" << '\n';
        }
        // if passing all checks it does
        // disamount and final price
        else
        {
            // adding values every time is vaild
            vaild++;
            books += sm[i].getBookCount();
            total += sm[i].getFinalPrice();
            outFile << sm[i].getDiscountAmount()
                    << " " << sm[i].getFinalPrice() << '\n';
        }
    }
    // prints extra data
    // and the dasses and plus
    outFile << '\n'
            << '\n'
            << "------------+------------+------------+"
            << "------------+------------+------------"
            << "+------------+------------+" << '\n';
    outFile << "Total entries from file : " << totalEntry << '\n';
    outFile << "Valid entries : " << vaild << '\n';
    outFile << "Total books Sold : " << books << '\n';
    outFile << "TotalSaleAmount : " << total << '\n';
    outFile << "------------+------------+------------+"
            << "------------+------------+------------"
            << "+------------+------------+" << '\n';
}