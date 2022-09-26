#include "memberType.h"
#include <iostream>

memberType::memberType()
{
    memberID = "sbc123";
    firstName = "fName";
    lastName = "lName";
    booksPurchased = 0;
    amountSpent = 0;
    booksDiscount = 0;
    lengthOfMembership = 0;
}

void memberType::setMemberInfo(string ID, string fName, string lName,
                               int bPurchased, double amount, double discount, int membership)
{
    memberID = ID;
    firstName = fName;
    lastName = lName;
    booksPurchased = bPurchased;
    amountSpent = amount;
    booksDiscount = discount;
    if (booksPurchased >= 4)
    {
        booksDiscount += 4;
    }
    lengthOfMembership = membership;
}
void memberType::setMemberID(string ID)
{
    memberID = ID;
}
void memberType::setName(string fName, string lName)
{
    firstName = fName;
    lastName = lName;
}

bool memberType::checkID(string ID)
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
bool memberType::checkBookCount(int booksCount)
{
    if (booksCount > 0)
    {
        return 1;
    }
    return 0;
}
bool memberType::checkAmountSpent(int booksCount, double amountSpent)
{
    if (booksCount <= 0 && amountSpent > 0)
    {
        return 0;
    }
    if (booksCount > 0 && amountSpent <= 0)
    {
        return 0;
    }
    return 1;
}
bool memberType::checkMembership(int membership)
{
    if (membership > 0)
    {
        return 1;
    }
    return 0;
}
bool memberType::checkDiscount(int discount)
{
    if (discount > 0)
    {
        return 1;
    }
    return 0;
}

string memberType::getID() const
{
    return memberID;
}
string memberType::getFirstName() const
{
    return firstName;
}
string memberType::getLastName() const
{
    return lastName;
}
int memberType::getBookCount() const
{
    return booksPurchased;
}
double memberType::getPurchaseBill() const
{
    return amountSpent;
}
int memberType::getLenghtOfMembership() const
{
    return lengthOfMembership;
}
double memberType::getDiscount() const
{
    return booksDiscount;
}
double memberType::getDiscountAmount() const
{
    return (amountSpent / 100) * booksDiscount;
}
double memberType::getFinalPrice() const
{
    return amountSpent - getDiscountAmount();
}

memberType::~memberType()
{
}