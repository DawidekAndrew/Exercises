/*Problem 5 from Project Euler

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Author: Andrew Dawidek
Date: December 12 2015*/

/*
NOTES
Consider the numbers 1 to 8
1 is prime so multiply by 1 (if you really feel like it)
2 is prime so multiply by 2
3 is prime so multiply by 3
4 is not prime. It can be broken down into 2 * 2. Since the product is divisible by 2, only multiply by 2
5 is prime so multiply by 5
6 is not prime. It can be broken down into 2 * 3, both of which have already been acounted for so no multiplication
7 is prime so multiply by 7
8 is not prime. It can be broken down into 2 * 4. Since the product is now divisible by 4, only multiply by 2.

The trick to the algorithm is that whenever a new non-prime number x is found (that is not already a factor of the current product),
it is guaranteed that the product only needs to be multiplied by a SINGLE prime factor of x to make the product now divisible 
by x.

When checking if some number n is prime, you only need to check all multiples up to its
square root. This is because if n is not prime, then it has some factors a and b. If a and b were both
greater than the square root of n, then a * b would be greater than n. This means at least one
of the factors is <= n.
*/

#include <iostream>
#include <cmath>
#include <array>

int main(int argc, char** argv)
{
    const int n = 20;
    long prod = 1;

    std::array<bool, n + 1> isPrime;
    isPrime.fill(true);

    int root = std::sqrt(n); //floored root

    // find prime factors
    for (int i = 2; i <= root; ++i)
    {
        for (int x = 2 * i; x <= n; x += i)
        {
            isPrime[x] = false;
        }
    }

    for (int i = 2; i < n; ++i)
    {
        if(isPrime[i])
        {
            prod *= i;
        }
        else if(prod % i)
        {
            int x = i;
            for (int j = 2; j < i; ++j)
            {
                if (!(x % j))
                {
                    x /= j;
                    prod *= j;
                    break;
                }
            }
        }
    }

    std::cout << "Product: " << prod << std::endl;

    return 0;
}
