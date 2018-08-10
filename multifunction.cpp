#include <iostream>
using namespace std;

void displayNumbers(int, int, int); //declares prototype for function

int main()
{
    int x = 3, y = 4, z = 9;
    displayNumbers(x, y, z);
}

void displayNumbers(int num1, int num2, int num3)
{
    cout << num1 << endl << num2 << endl << num3 << endl;
}