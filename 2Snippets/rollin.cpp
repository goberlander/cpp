/* This program will generate two random numbers between 1 and 6.
Author: Glenn Oberlander
Date: 2/24/2018
Version: 1.0
*/


#include <iostream>
#include <cstdlib> //includes the rand and srand function
#include <ctime> //includes the time function

using namespace std;

int main()
{
    //Constants
    const int MIN_VALUE = 1; //min die value
    const int MAX_VALUE = 6; //max die value

    //Variables
    int die1; //hold the value of die 1 
    int die2; //hold the value of die 2

    unsigned seed = time(0); //unsigned since time is only positive

    //Seeds the random number generator
    srand(seed); 

    cout << "Rolling the dice..." << endl;
    die1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    die2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    cout << die1 << endl;
    cout << die2 << endl;

}
