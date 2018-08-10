/*
Program: Classic!
Author: Glenn
Date: 5.11.18

This program is about getting more familiar with classes. This will store numbers in the array, etc */

#include <iostream>
using namespace std;

class Array
{
    private:
        float *flt_arr;
        int array_size;
    public:
        Array(int);
        void storeNumber(int, float);
        float getNumber(int);
        float getHighest();
        float getLowest();
        float average();
        ~Array();
};
Array::Array(int SIZE) 
{
    flt_arr = new float[SIZE];
    array_size = SIZE;
    for(int i = 0; i < array_size; i++)
    {
        flt_arr[i] = 0.0;
    }
}
void Array::storeNumber(int elePos, float value) 
    {
        flt_arr[elePos] = value;
    }
float Array::getNumber(int elePos)
    {
        float value = flt_arr[elePos];
        return value;
    }
float Array::getHighest()
    {
        float highest;
        highest = flt_arr[0];
        for(int i = 0; i < array_size; i++)
        {
            if(flt_arr[i] > highest)
                highest = flt_arr[i];
            else
                continue;
        }
        return highest;
    }
float Array::getLowest()
    {
        float lowest;
        lowest = flt_arr[0];
        for(int i = 0; i < array_size; i++)
        {
            if(flt_arr[i] < lowest)
            {
                lowest = flt_arr[i];
            }
            else
                continue;
        }
        return lowest;
    }
float Array::average()
    {
        float average = 0.0;
        float sum = 0.0;
        for (int i = 0; i < array_size; i++)
        {
            sum += flt_arr[i];
            average = sum / array_size;
        }
        return average;
    }
Array::~Array()
    {
        delete [] flt_arr;
    }
int main()
{
    const int SIZE = 5;
    Array numbers(SIZE); // Initialize Class Array with the object numbers and pass the parameter SIZE to the constructor
    
    /* These fill flt_arr*/
    numbers.storeNumber(0, 1.4);
    numbers.storeNumber(1, 2.3);
    numbers.storeNumber(2, 3.13);
    numbers.storeNumber(3, 6.66);
    numbers.storeNumber(4, 7.711);

    numbers.getNumber(3); // Demonstrates what getnumber does
    numbers.getHighest(); // Gets highest value in array
    numbers.getLowest(); // Gets lowest value in array
    numbers.average(); // Returns the average
    ~Array(); // deletes allocated memory
}