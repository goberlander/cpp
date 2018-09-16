#include <iostream>
using namespace std;

/* This program will recursively do a binary search on an array of 100 digits.
It will ask the user for a number to search for. */

int binarySearch(int *, int, int, int);
void fillArray(int *, int);

int main()
{
    int input; // To hold user's input
    const int SIZE = 100; // Size of array
    int *arrPtr = new int[SIZE]; // Declare a pointer named, arrPtr; assign it the address of the dynamically allocated memory to hold the array of 100 ints.
    
    // Fill an array with 100 numbers.
    fillArray(arrPtr, SIZE);

    // Prompt the user for a value to search for.
    cout << "Enter a number to search for: ";
    cin >> input;
    int results = binarySearch(arrPtr, 0, SIZE - 1, input); // SIZE - 1 is the last element in the array.
    if (results)
    {
        cout << "Your value was found!\n";
    }
    else
        cout << "Your value was not found. :( \n";
    delete [] arrPtr;
    arrPtr = nullptr;
}

// Fill the array with 100 digits.
void fillArray(int *arrPtr, int size)
{
    int value = 1;
    for (int i = 0; i < size; i++)
    {
        *(arrPtr + i) = value++;
        cout << *(arrPtr);
        cout << value;
    }
}
// Recursively search through the array to find a number.
int binarySearch(int *ptr, int first, int last, int value)
{
    int middle; // Declares variable for midpoint of search

    // This is from the book, not sure why this needs to be in here... Oh I guess last is SIZE - 1, so if SIZE is 1, last = 1 - 1 which is 0, so first (0) is !> last but equal, so it would return 1, it's basically a safety check.
    if(first > last)  
    {
        return -1;
    }
    middle = (first + last) / 2; // First + last = 0 + SIZE - 1, then divided by 2, in this case, is 50. Because, SIZE is 100 (# of elements), but the positioning is 0 - 99. 0, 1, 2, 3, 4, is half way of 10. So, [49] is the 50th position out of 100 elements
    if (*(ptr + middle) == value)
        return value;
    if (*(ptr + middle) < value)
    {
        return binarySearch(ptr, middle+1, last, value); // Middle + 1 is a new first position. It is half-of-array+1
    }
    else
        return binarySearch(ptr, first, middle - 1, value); // Middle - 1 is the new last position. It is half-
}

