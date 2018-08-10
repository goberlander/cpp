/* This will perform a factorial: n!. 5! = 5 x 4 x 3 x 2 x 1 */
#include <iostream>
using namespace std;

int factorial(int);

int main()
{
    int number = 10;
    factorial(number);
    cout << factorial(number) << endl;
}

int factorial(int n)
{
    if (n==0)
        return 1;
    else
        return n * factorial(n-1);
}