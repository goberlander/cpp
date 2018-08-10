/*
Program Name: isPrime or not isPrime, that is the question.
Author: Glenn Walter Oberlander Jr.
Date: 3.14.2018
Version: 1.0
*/

/** PROGRAM PURPOSE AND WHAT IT DOES **/
/*
This program will test if the user's input is a prime number. 
It will output the result. 
If user enter's 0 or a number less than 1, it will continue to prompt user for input.
*/

#include <iostream>

using namespace std;

bool isPrime(long int number); //prototype declaring function

int main()
{
    int userInput;
    //will prompt user once, if wrong input, continue to prompt.
    do{

    cout << "Enter a number and I'll tell you whether it is prime: ";
    cin >> userInput;
    //if input is negative
    if(userInput <= 1)
        cout << "You've eneterd 1, 0 or a negative number. Try again...\n";

    }while(userInput <= 1); //if input is less than or equal to 1
    
    //calls isPrime funciton, with conditions
    if(isPrime(userInput) == true)
    {
        cout << userInput << " is prime" << endl;
    }
    else
    {
        cout << userInput << " is NOT prime" << endl;
    }
    
}


/* PRIME FUNCTION */
bool isPrime(long int number)
{
    //checks if it's 2 or 3 to quickly return
    if(number == 2 || number == 3 || number == 5 || number == 7)
        return true;
    //checks if it's divisible by 2 or 3    
    else if(number % 2 == 0 || number % 3 == 0)
        return false;
    
    /* HOW isPrime WORKS *
    - start at 5 because 2 and 3 are already checked, and 4 is a composite #.
    - iterate to the number entered (you could do the sqrt of the number to shorten the steps)
    - increase by 6 each time because, starting from 5... 
        - +1 will give you 6 (even), 
        - +2 evaluates 7, but then 9 (composite)
        - +3 evalutes 8 (even)
        - +4 evaluates 9 (divisible by 3)
        - +5 evaluates 10 (even)
        - +6 evaluates 11 (prime), 17 (prime). It is part of the Primality Test.
    */
    for(int i = 5; i <= number; i += 6)
    {
        //modulates iterated # to the number and number + 2, if divisible, return false
        if(number % i == 0 || number % (i + 2) == 0)
            return false;
        else
            return true;
    }
return 0;
}
