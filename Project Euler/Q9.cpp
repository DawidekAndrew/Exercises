/*Problem 9 from Project Euler
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc
*/


/*
NOTES:
1) a + b + c = n => c = n - b - a
2) a^2 + b^2 = c ^2

sub 1 in 2
a^2 + b^2       = (n - b - a) ^2
                = n^2 - 2na - 2nb + a^2 + b^2 + 2ab
n^2             = 2na + 2nb - 2ab
(n^2) / 2)      = na + nb - ab 
(n^2) / 2) - na = b(n - a)
b               = (((n^2) / 2) - na) / (n - a)

This substitution and isolation changes the probem from O(n^2) to O(n) 
since given 'a', 'b' and 'c' can be solved in constant time. The solution
also avoids having to compute square roots.

Don't need to check a or b == 0 since a, b and c must all be unique
*/
#include <iostream>

int main(int argc, char** argv)
{ 
    const long long n = 1000;  
    
    int a;
    int b;
    int c;

    for(a = 1; a < n; ++a)
    {
        b = ((n * n / 2) - (n * a)) / (n - a);
        c = n - b - a;

        if (((a * a) + (b * b) == (c * c)) 
            && (a != b)
            && (a != c)
            && (b != c))
        {
            break;
        }
    }

    int product = a * b * c;
    std::cout << "ABC Product: " << product << std::endl;

    return 0;
}
