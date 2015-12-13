/*Problem 4 from Project Euler

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

Author: Andrew Dawidek
Date: December 12 2015*/

/*
NOTES
Start from the highest products and work back until the first palindrome is found.
The following products are in a decending order:
n * n             = n^2
(n - 1) * n       = n^2 - n
(n - 1) * (n - 1) = n^2 - 2n + 1
(n - 2) * n =     = n^2 - 2n
(n - 2) * (n - 1) = n^2 - 3n + 2
(n - 3) * n       = n^2 - 3n
(n - 2) * (n - 2) = n^2 - 4n + 4
(n - 3) * (n - 1) = n^2 - 4n + 3 
(n - 4) * n       = n^2 - 4n
(n - 3) * (n - 2) = n^2 - 5n + 6
(n - 4) * (n - 1) = n^2 - 5n + 4
(n - 5) * n       = n^2 - 5n

Looking at the linear terms you get the following:

coefficient       sum of (in order of how they appear above)
****************************************
0                   0 + 0
1                   1 + 0
2                   1 + 1, 2 + 0
3                   2 + 1, 3 + 0
4                   2 + 2, 3 + 1, 4 + 0
5                   3 + 2, 4 + 1, 5 + 0

For each coefficient, the first pair of operands start at ceiling(n/2) and floor(n/2) respectively while the first operand
is increment and the second is decremented in each subsequent pair.
*/

#include <iostream>

// There are probably better ways of reversing a number
bool isPalendrome(const int num) 
{
    int n = num;
    int rev = 0;

    while (n)
    {
        rev *= 10;
        rev += n % 10;
        n /= 10;
    }
    
    return(rev == num);
}

int main(int argc, char** argv)
{
    const int n = 999;  // max multiplicand

    int prod = 0;       // product of multiplication
    int c = 0;          // linear term coefficient
    int x, y;           // floor and ceiling of linear term coefficient divided by 2

    // no condition needed for this while loop because there is guaranteed to be a palindrome
    while(true)
    {
        x = (c + 1) / 2;    // ceiling of division by 2
        y = c / 2;          // floor of division by 2
        for(int i = x; i <= c; ++i)
        {
            prod = (n - x) * (n - y);
            if(isPalendrome(prod))
            {
                std::cout << "Largest Palindrome: " << prod << std::endl;
                return 0;
            }
            ++x;
            --y;
        }
        ++c;
    }

    return 0;
}
