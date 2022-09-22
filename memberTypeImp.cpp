#include <memberType.h>
#include <iostream>

void memberType::setMemberInfo(string ID, string fName, string lName,
                               int bPurchased, double amount, double discount, int membership)
{
    memberID = ID;
    firstName = fName;
    lastName = lName;
    booksPurchased = bPurchased;
    amountSpent = amount;
    booksDiscount = discount;
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

bool memberType::checkID(string)
{
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
    if (booksCount < 0 && amountSpent > 0)
    {
        return 0;
    }
    if (booksCount > 0 && amountSpent < 0)
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
    return booksDiscount;
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