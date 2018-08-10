
/*
Program Name: Hallelujah, it's raining!
Author: Glenn Walter Oberlander Jr.
Date: 3.21.18
Version: 1.0
*/

/*
                   ***PROGRAM PURPOSE AND FUNCTION***
The program's purpose is to gather the user's input for rainfall and output:
1.) the total rainfall,
2.) the average monthly rainfall,
3.) the highest and lowest rainfall amounts with its corresponding month.
Program will reprompt user if given a negative number.
*/

#include <iostream>
#include <string> 
using namespace std;

const int MONTHS = 12;
string months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

double rainfallHolder[12]; 
double totalRainfall = 0.0;
double avgRainfall;

string highestMonth;
string lowestMonth;

int main()
{
   //prompts user for input. Stores input into rainfallHolder. Gathers total rainfall.
   for(int i = 0; i < MONTHS; i++)
   {
       cout << "Please enter rainfall for, " << months[i] << ": " << endl;
       cin >> rainfallHolder[i];
       //will reprompt user if negative input
       if(rainfallHolder[i] < 0)
       {
           cout << "That is an invalid value.\n";
           i--;
           continue;
       }
       totalRainfall += rainfallHolder[i];
   }
  

avgRainfall = totalRainfall / MONTHS;

//assigns variables to element 0 of array rainfallHolder
double highestValue = rainfallHolder[0];
double lowestValue = rainfallHolder[0];

   //assigns highest and lowest values and the months associated with that value.
   for(int i = 0; i < MONTHS; i++)
   {   
       if(rainfallHolder[i] > highestValue)
       {
           highestValue = rainfallHolder[i];
           highestMonth = months[i];
       }
   }

   //checks lowest rainfall, assigns lowest, and month associated with value
   for(int j = 0; j < MONTHS; j++)
   { 
       if(rainfallHolder[j] < lowestValue)
       {
           lowestValue = rainfallHolder[j];
           lowestMonth = months[j];
       }
   }

   //prints final outputs
   cout << "Total rainfall: " << totalRainfall << endl;
   cout << "Average monthly rainfall: " << avgRainfall << endl;
   cout << highestMonth << " was the highest month with " << highestValue << " units of rainfall\n";
   cout << lowestMonth << " was the lowest month with " << lowestValue << " units of rainfall\n";  
}