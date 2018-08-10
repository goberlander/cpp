/*
Program Name: Appointed
Author: Glenn Walter Oberlander Jr.
Date: 4/20/2018
*/

/*This program will stream data from a file, fill it into an array of no greater than 50 (or less than 0), then will reverse the array and print it out.*/

#include<iostream>
#include<fstream>
using namespace std;

int *reverseArray(int dataArray[], int arraySize);

int main()
{
    int dataArray[50]; // Sets the max size of Array
    int data; // To hold file stream from data.txt
    int size; 
    // Stream integers from data.txt into array to fill it, then breaks if it reaches the end
    ifstream dataFile("data.txt");
    while(dataFile)
    {
        dataFile >> data;
        if(false)
            break;
        dataArray[size++] = data;
    }
    size--; 
    /* Not sure why, but I needed it to compensate for reading the data file. It made the array plus one too large. I messed with all different ways to adjust it, but this worked the best.*/
    
    // Exit the code if file greater than 50 or less than 0
    if(data > 50 || data < 0)
            return 0;
    reverseArray(dataArray, size);
}
int *reverseArray(int dataArray[], int arraySize)
{
    int *arrayCopy = nullptr; // Declares pointer to int variable
    arrayCopy = new int [arraySize]; // Creates a block of memory the size of the array.
    // Reverse the array
    for(int i = 0, j = arraySize - 1; i < arraySize; i++, j--)
    {
        arrayCopy[i] = dataArray[j];
    }
    return arrayCopy; // Return pointer array
}