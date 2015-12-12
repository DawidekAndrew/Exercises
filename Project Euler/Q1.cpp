/*Problem 1 from Project Euler

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

Author: Andrew Dawidek
Date: December 11 2015*/

/*
NOTES
When using the % operator, in the case a % x where x is a constant, the compiler 
will typically use its fastest available algorithm to determine divisiblity where 
as if x is a variable division is inevitable. In this problem we have constants,
however arithmetic series were used instead becuase they give a O(1) result instead of O(n).
*/

#include <iostream>

int arithmeticSum(int n)
{
    return(0.5 * n * (n + 1));
}

int main(int argc, char** argv)
{
    const int a = 333;  // 999 / 3
    const int b = 199;  // 999 / 5
    const int c = 66;   // 999 / 15
    
    const int sum = 
        3 * arithmeticSum(a) +
        5 * arithmeticSum(b) -
        15 * arithmeticSum(c);
    
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
