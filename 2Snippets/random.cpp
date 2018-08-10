#include <iostream>
using namespace std;



int main()
{
    int *arrayPtr = nullptr;
    int myArray[3] = {5, 7, 17};
    arrayPtr = myArray; // Assigns the array's address to arrayPtr
    cout << *arrayPtr << endl; //prints 5
    cout << arrayPtr << endl; // 0x61ff0c
    cout << ++arrayPtr << endl; // 0x61ff10 (address of 2nd element)
    cout << *arrayPtr << endl; // 7 (2nd element)
    cout << ++*arrayPtr << endl; // 8 (increased the value of the 2nd element)
    cout << arrayPtr << endl; // 0x61ff10 (address of 2nd element)
    cout << *(arrayPtr + 1) << endl; // 17 (prints the 3rd element)
    cout << ++*arrayPtr << endl; // 9 (we're still on the 2nd element, so it increased the value that arrayPtr is pointing to)
    cout << *(++arrayPtr) << endl; // 17 (element 3)
    cout << ++(*arrayPtr) << endl; // 18 (increase value at element 3)
    for(int i = 0; i < 3; i++)
    {
        cout << myArray[i] << ", "; // 5, 9, 18 (end result of myArray)
    }
    
}
