/*
*
* 
Program Name: The Zerg
Program Version: 1.0
Author: Glenn Walter Oberlander Jr.
Date: 3.7.2018
Inputs to Program: None
Outputs from Program: Text
*
*
*/


/**This program will calculate the population increase of an organism based on a percentage**/

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    //variables to hold inputs and calculation
    int days;
    double startingPop;
    double percentInc, popPerDay;
    
    //prompt user for starting population
    do
    { 
        cout << "Enter the starting number of organisms: ";
        cin >> startingPop;
        if(startingPop < 2) //prompt user to re-enter correct value
            cout << "The starting number of organisms must be at least 2.\n";
    }while(startingPop < 2); //condition to keep re-prompting if user does not meet condition

    //prompt user for starting population
    do{
        cout << "Enter the average daily population increase (as a percentage): ";
        cin >> percentInc;
        if(percentInc <= 0)
            cout << "The average daily population increase must be a positive value.\n";
        percentInc /= 100; //convert percentage to a decimal
    }while(percentInc <= 0);

    //prompt user for days
    do{
        cout << "Enter the number of days they will multiply: ";
        cin >> days;
        if(days < 1) //if statement that catches wrong input
            cout << "The number of days must be at least 1.\n";
    } while(days < 1); //while condition that reprompts if wrong input

    cout << fixed << showpoint << setprecision(2); //sets output to 2 decimal places
    cout << "On day 1 the population size was " << startingPop << ".\n"; //outputs day 1
    popPerDay = startingPop; //sets up for loop with proper value
    
    //outputs the result of user's input
    for(int i = 2; i <= days; i++)
    {    
        popPerDay *= (1 + percentInc); //formula for output
        cout << "On day " << i << " the population size was " << popPerDay << ".\n";
    }
} 
    