/*
    Name: Brian, 5008139573, 1005, 2
    Description: Discount bookstore
    Input: membersdata.txt
    Output: membersdata_output.txt
*/
#include "memberType.h"
#include <iostream>
// class constuctor
memberType::memberType()
{
    // sets default values
    memberID = "sbc123";
    firstName = "fName";
    lastName = "lName";
    booksPurchased = 0;
    amountSpent = 0;
    booksDiscount = 0;
    lengthOfMembership = 0;
}
// sets private vars using passed parameters
// also does logic for adding discount
// if booksPurchased is more than 4
void memberType::setMemberInfo(string ID, string fName, string lName,
                               int bPurchased, double amount,
                               double discount, int membership)
{
    // sets data from parameters
    memberID = ID;
    firstName = fName;
    lastName = lName;
    booksPurchased = bPurchased;
    amountSpent = amount;
    booksDiscount = discount;
    // checks if books purchased is more
    // than 4 then adds discount if true
    if (booksPurchased >= 4)
    {
        // doesnt set because it could be a value
        booksDiscount += 4;
    }
    lengthOfMembership = membership;
}
// sets memberid using passed parameter
void memberType::setMemberID(string ID)
{
    memberID = ID;
}
// sets name using passed parameter
void memberType::setName(string fName, string lName)
{
    firstName = fName;
    lastName = lName;
}
// checks if Id is vaild
// so is three letters
// and three letteres on the end
bool memberType::checkID(string ID)
{
    // checks if size is only 6
    if (ID.size() != 6)
    {
        return 0;
    }
    // checks if first three are letters
    for (int i = 0; i < 3; i++)
    {
        // uses ascii to compare numbers
        // if its between 65 and 90
        // or 97 and 122 for lowercase
        // it returns true
        if (ID[i] < 65 || (ID[i] > 90 && ID[i] < 97) || ID[i] > 122)
        {
            return 0;
        }
    }
    // checks if last three are numbers
    for (int i = 3; i < 6; i++)
    {
        // if its between 48 and 57
        // returns a true
        if (ID[i] < 48 || ID[i] > 57)
        {
            return 0;
        }
    }
    return 1;
}
// checks if book count is not negative
bool memberType::checkBookCount(int booksCount)
{
    if (booksCount >= 0)
    {
        return 1;
    }
    return 0;
}
// checks if amountspent is correct
bool memberType::checkAmountSpent(int booksCount, double amountSpent)
{
    // checks if book count is 0
    // amount spent has to be greater than 0
    if (booksCount <= 0 && amountSpent > 0)
    {
        return 0;
    }
    // checks when book count is greater
    // amountspent has to be greater than 0
    if (booksCount > 0 && amountSpent <= 0)
    {
        return 0;
    }
    return 1;
}
// checks if membership is not negative
bool memberType::checkMembership(int membership)
{
    if (membership >= 0)
    {
        return 1;
    }
    return 0;
}
// checks if discount is not negative
bool memberType::checkDiscount(int discount)
{
    if (discount >= 0)
    {
        return 1;
    }
    return 0;
}
// returns ID
string memberType::getID() const
{
    return memberID;
}
// returns first name
string memberType::getFirstName() const
{
    return firstName;
}
// returns last name
string memberType::getLastName() const
{
    return lastName;
}
// returns bookspurchesed
int memberType::getBookCount() const
{
    return booksPurchased;
}
// returns amountspent
double memberType::getPurchaseBill() const
{
    return amountSpent;
}
// returns lengthofmembership
int memberType::getLenghtOfMembership() const
{
    return lengthOfMembership;
}
// returns booksdiscount
double memberType::getDiscount() const
{
    return booksDiscount;
}
// returns discount amount
double memberType::getDiscountAmount() const
{
    // it divides it so it can
    // be multiplied by discount
    return (amountSpent / 100) * booksDiscount;
}
// returns getfinalprice
double memberType::getFinalPrice() const
{
    // final price is amount minus
    // discounted amount
    return amountSpent - getDiscountAmount();
}
// gives memory back
memberType::~memberType()
{
}