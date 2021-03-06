/*Problem 2 from Project Euler

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

Author: Andrew Dawidek
Date: December 12 2015*/

/*
NOTES
Every third number in the Fibonacci sequence is even so no divisibility checks required.
*/

#include <iostream>

int main(int argc, char** argv)
{
    long sum = 2;
    int f1 = 1;
    int f2 = 2;
    
    int temp;
    while(true)
    {
        for(int i = 0; i < 3; ++i)
        {
            temp = f2;
            f2 += f1;
            f1 = temp;
        }

        if (f2 < 4000000)
        {
            sum += f2;
        }
        else
        {
            break;
        }
    }

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
