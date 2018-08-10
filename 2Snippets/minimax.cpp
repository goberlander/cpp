#include<iostream>
#include<string>

using namespace std;

char gameboard[9] = {'*','*','*','*','*','*','*','*','*'};
void printGameboard(gameboard);


int main()
{
   
}


void printGameboard(gameboard[])
{
    //print gameboard
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << gameboard[j]; 
        }
        cout << endl;
    }
}