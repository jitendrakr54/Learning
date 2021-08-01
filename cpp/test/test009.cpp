#include <algorithm>
#include <iostream>

bool isCardValid(std::string &card) {
    int length = card.length();
    int sum = 0;
    bool isSecond = false;

    for(int i = length-1; i>=0; i--) {
        int d = card[i] - '0';
        if(isSecond) {
            d = d*2;
        }
        sum += d/10;
        sum += d%10;

        isSecond = !isSecond;
    }
    std::cout<<sum<<" "<<length<<"\n";
    return (sum % 10 == 0);
}

const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;
 
// Returns true if
// given year is valid.
bool isLeap(int year)
{
// Return true if year
// is a multiple pf 4 and
// not multiple of 100.
// OR year is multiple of 400.
return (((year % 4 == 0) &&
         (year % 100 != 0)) ||
         (year % 400 == 0));
}

bool isValidDate(int d, int m, int y)
{
    // If year, month and day
    // are not in given range
    if (y > MAX_VALID_YR ||
        y < MIN_VALID_YR)
    return false;
    if (m < 1 || m > 12)
    return false;
    if (d < 1 || d > 31)
    return false;
 
    // Handle February month
    // with leap year
    if (m == 2)
    {
        if (isLeap(y))
        return (d <= 29);
        else
        return (d <= 28);
    }
 
    // Months of April, June,
    // Sept and Nov must have
    // number of days less than
    // or equal to 30.
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);
 
    return true;
}

int main() {
    std::string card = "461180010006747";
    4 6 1 1 8 0 0 1 0 0 0 6 7 4 7
    4  3  1  2  8  0  0  2  0  0  0  3  7   8 7
    std::cout<<isCardValid(card);
    return 0;
}