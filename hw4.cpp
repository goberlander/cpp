/*
Program: Speed of Sound
Author: Glenn Walter Oberlander Jr
Date: 02/28/2018
Version: 1.0
*/

/*
This program will calculate the speed of sound (in seconds) based on the medium the user 
chooses and the distance (in feet) they input.*/


#include <iostream> 
#include <iomanip> //allows the use of cin object
using namespace std;

int choice; //holds user's choice
double travelTime,          //holds the calculated time it takes for sound to travel
inputDistance,              //the distance the user puts in
oneAir = 1100.0000,         //assigned values to the mediums
twoWater = 4900.0000, 
threeSteel = 16400.0000;
string choiceName;          //used for output statement to say the type of medium used
int main()
{
    //prompts user
    cout << "Choose one of these mediums: \n";
    cout << "1. Air\n";
    cout << "2. Water\n";
    cout << "3. Steel\n";
    cout << "Choice:\n";
    cin >> choice; //holds input

    //will assign according to which choice user makes; validates user input
    switch(choice)
    {
        case 1: choice = oneAir; choiceName = "Air";
        break;
        case 2: choice = twoWater; choiceName = "Water";
        break;
        case 3: choice = threeSteel; choiceName = "Steel";
        break;
        default: cout << "The valid choices are 1 through 3. Run the program again and select one of those.\n";
        return 0;
    }
    
    //prompts user to enter distance
    cout << "Enter the distance(feet):\n";
    cin >> inputDistance; //holds input
    //validates user input, exits program if wrong
    if(inputDistance < 0)
    {
        cout << "Distance must be greater than zero.\n";
        return 0;
    }
    
    travelTime = inputDistance / choice; //calculation from users input
    //final statement that puts it all together
    cout << "A sound wave takes " << setprecision(4) << fixed << travelTime << " seconds to travel " << inputDistance << " feet in " << choiceName << ".\n";

}
