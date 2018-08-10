#include <iostream>
using namespace std;

char gameBoard[9] = {'*','*','*','*','*','*','*','*','*'};

int main()
{

    for(int i = 0; i < 3; i++)
        {
            cout << gameBoard[i];
            for(int j = 0; j < 2; j++)
            {
                cout << gameBoard[j];
            }
 
            cout << endl;
        }
}

/* OUTPUTS
Glenns-MBP:cpp glennoberlander$ g++ -o forTest forTest.cpp
Glenns-MBP:cpp glennoberlander$ ./forTest
***
***
***
Glenns-MBP:cpp glennoberlander$  */