#include <iostream>

using namespace std;

int main()
{
    // int num1 = 5;
    // int *ptr = &num1; // Declares a pointer variable called, ptr; assigns it the address of num1 (where 5 is stored)
    // cout << ptr << endl;
    // cout << *ptr << endl;  
    
    
    // int *ptr = new int;
    // cout << *ptr << endl;
    int *numbers = new int[5];
    for(int i = 0; i <= 4; i++)
    {
        *(numbers + i) = i;
        cout << numbers[i] << endl; 
    }
        
}   