#include <iostream>

using namespace std;

int functionPtr(int *); // This declares a pointer to an int variable

int main()
{
    int x = 3; 
    functionPtr(&x); //sends the address of X to the function
}
// This points value to the address of x.
int functionPtr(int *value)
{
    cout << *value << endl;
    return 0;
}