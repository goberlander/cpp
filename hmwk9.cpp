/* 9.10: Reverse Array
- Write a function that accepts an int array and the array’s size as arguments. 

- The function should create a copy of the array, except that the element values should be reversed in the copy. 
- The function should return a pointer to the new array. 

- Demonstrate the function by using it in a main program that reads an integer N (that is not more than 50) from standard input and then reads N integers from a file named data into an array. 

- The program then passes the array to the your reverse array function, and prints the values of the new reversed array on standard output, one value per line. 

You may assume that the file data has at least N values.

Prompts And Output Labels. There are no prompts for the integer and no labels for the
reversed array that is printed out.

Input Validation. If the integer read in from standard input exceeds 50 or is less than 0
the program terminates silently. */

#include<iostream>
#include<fstream>
using namespace std;

int reverseArray(int dataArray[], int arraySize);
void printArray(int dataArray[], int arraySize);

int main()
{
    int dataArray[50];
    //dataArray = nullptr;
    
    int size;
    //feed integers from data file into array to fill it
    ifstream dataFile("data.txt");
    while(dataFile)
    {
        int data;
        dataFile >> data;
        if(false)
            break;
        dataArray[size++] = data;
    }
    size--;
    cout << "size before 1st for loop: " << size << endl;
    for(int j = 0; j < size; j++)
    {
            cout << dataArray[j] << endl;
    }
    reverseArray(dataArray, size);

    


    //terminate program if input is greater than 50 or less than 0


}

int reverseArray(int dataArray[], int arraySize)
{
    int arrayCopy[arraySize];
    cout << "arraySize: " << arraySize << endl;
    for(int i = 0, j = arraySize - 1; i < arraySize; i++, j--)
    {
        arrayCopy[i] = dataArray[j];
        cout << arrayCopy[i] << endl;
    }
    return arrayCopy[arraySize];
}

void printArray(int dataArray[], int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        cout << dataArray[i] << endl;
    }
}