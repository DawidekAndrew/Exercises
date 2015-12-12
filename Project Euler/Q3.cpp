/*Problem 3 from Project Euler

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

Author: Andrew Dawidek
Date: December 12 2015*/

/*
NOTES
This problem is just prime factor decomposition.
*/

#include <iostream>

int main(int argc, char** argv)
{
    long long num = 600851475143;
    long factor = 2;

    while(factor < num)
    {
        if (num % factor == 0)
        {
            num /= factor;
        }
        else
        {
            ++factor;
        }
    }

    std::cout << "Largest Prime Factor: " << num << std::endl;
    return 0;
}
