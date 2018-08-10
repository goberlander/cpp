#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string TotalRain = ""; //Total rain in string - input from user
    double rain, RainSum = 0; //turn each input into double
    double AvgRain = 0; //average rain
    double Small; //smallest amount of rain
    double Big = 0; //largest amount of rain
    string BigMonth, SmallMonth =""; //holding the month of smalles/biggest rain
    string months[12] = {"January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};
    int i = 0; //counter
    double rainArray[12]; //array to hold rainfall amounts
    
while (i<12){
         cout << "Please enter the amount of rainfall for the month of " 
         << months[i] << endl;
         getline(cin, TotalRain);
    
         while(true){ //while loop to determine if input is a negative or non-double
            stringstream RainStream (TotalRain);
            if (RainStream >> rain && rain >= 0){ //determine if input is negative or char
               rainArray[i] = rain; //adding input into rainArray
               RainSum += rain; //Retrieve Total Rainfall
               if(rain > Big){//check if input is greater than last months rainfall
                       Big = rain; //if it was, assign Big the greater number
                       BigMonth = months[i]; //assign biggest month to BigMonth
               }//end if
               i++; // while loop counter
               break; 
            }  //end if
            cout << "Invalid number, please try again" << endl; //user entered an invalid number
            break;
         } //end while loop
}  //end while loop 

    cout << "Total amount of rain: " << RainSum << endl; //print total rainfall
    AvgRain = RainSum/12; //determine average rainfall
    cout << "Average Monthly Rainfall: " << AvgRain << endl; //print avg rainfall
    cout << "The Month with the Highest amount of Rainfall is: " << BigMonth << endl;//print highest rainfall
    
    Small = rainArray[0]; //initialize Small as the January rainfall input
    SmallMonth = months[0];  //initialize SmallMonth as January incase January is the lowest rainfall
for(int a = 0; a<12; a++){ //for loop to run through rainArray
        if(rainArray[a] < Small){ //if the previous months rainfall is less than Small, reassign Small
            Small = rainArray[a];
            SmallMonth = months[a];
            }//end if
}//end for loop
    cout << "The Month with the Smallest amount of Rainfall is: " << SmallMonth << endl; //print smallest rainfall
    
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
