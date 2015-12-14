/*Problem 6 from Project Euler

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10) ^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and
the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <iostream>
#include <math.h>

int main(int argc, char** argv)
{
    const int n = 100;

    //sum of squares (calcualted with Faulhaber's formula for sum of powers)
    long a = ((2 * pow(n, 3)) + (3 * pow(n, 2) + n)) / 6;

    //square of sums (calculated with an arithmetic series)
    long b = pow(n * (n + 1) / 2, 2);
       
    int diff = b - a;
    std::cout << "Difference: " << diff << std::endl;

    return 0;
}
