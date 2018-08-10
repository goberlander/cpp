#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main()
    {
        const int MAX_VALUE = 26;
        int randomNum1;
        int randomNum2; //stores random #
        int modulusRemainder;
        int modRem2; //stores the remaining amount
        
        unsigned seed = time(0);
        srand(seed);
        randomNum1 = rand(); //stores 1st random number seeded from srand
        randomNum2 = rand(); //stores 2nd random 
        
        cout << randomNum1 << endl; //prints out seeded random number
        modulusRemainder = randomNum1 % MAX_VALUE; //calculates 1st modulated remainder
        cout << modulusRemainder << endl; //prints out modulated of 1st RN
        modRem2 = randomNum2 % MAX_VALUE; //calculates 2nd mod remainder
        cout << modRem2 << endl; //prints out 2nd mod remainder

    }