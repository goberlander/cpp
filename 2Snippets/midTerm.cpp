/*
Project Name: Tic-tac? Toe.
Author: Glenn Oberlander
Version: 1.0
Date: 4.8.2018

--PROGRAM FUNCTION/PURPOSE--
This program will play the game tic-tac-toe between two humans. It will validate their input to make sure that it is only 1, 2, 3, otherwise it will reprompt. Functions are setup to check a winner after each turn. If 9 moves are made without a win, it is a cat's game (tie).
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;


char gameBoard[3][3] = {{'*','*','*'},{'*','*','*'},{'*','*','*'}};
void printGameboard(char gameBoard[3][3]); // Will display the gameboard each turn

// Checks the gameboard for winners
bool checkBoard(char gameBoard[3][3]);
bool checkAcross(char gameBoard[3][3]);
bool checkDown(char gameBoard[3][3]);
bool checkDiag(char gameBoard[3][3]);

// This and the 3 other functions below validates the user's inputs if they are ints
void playerX(void); 
void playerO(void);
void validate_XRowInput(); 
void validate_XColumnInput();
void validate_ORowInput();
void validate_OColumnInput();

int counter = 0, // For determing Cat's game
row, 
column;

// Used to validate input
string rowInput = "";
string columnInput = "";

int main()
{
    while (counter <= 9)
    {
        // Prompts and validates playerX move
        playerX();
        printGameboard(gameBoard);      
        if(checkBoard(gameBoard) == true)
        { 
            cout << "Player X wins!" << endl;
            break;
        }
        counter++;
        if(counter == 9)
        {
            cout << "Cat's game!\n";
            break;
        }
        // Prompts and validates playerO move
        playerO(); 
        printGameboard(gameBoard);
        if(checkBoard(gameBoard) == true)
        {
            cout << "Player O wins!" << endl;
            break;
        }
        counter++;       
    }   
}
// Calls other functions to check the board for win
bool checkBoard(char gameBoard[3][3])
{
    if(checkAcross(gameBoard) == true)
        return true;
    else if(checkDown(gameBoard) == true)
        return true;
    else if(checkDiag(gameBoard) == true)
        return true;
    else
        return false;
}   
bool checkAcross(char gameBoard[3][3])
{   
    if(gameBoard[0][0] == gameBoard[0][1] && gameBoard[0][1] == gameBoard[0][2])
        return true; 
    else if(gameBoard[1][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[1][2] == 'X')
        return true; 
    else if(gameBoard[2][0] == 'X' && gameBoard[2][1] == 'X' && gameBoard[2][2] == 'X')
        return true;    
    else if(gameBoard[0][0] == 'O' && gameBoard[0][1] == 'O' && gameBoard[0][2] == 'O')
        return true; 
    else if(gameBoard[1][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[1][2] == 'O')
        return true; 
    else if(gameBoard[2][0] == 'O' && gameBoard[2][1] == 'O' && gameBoard[2][2] == 'O')
        return true;
    else
        return false;   
}
bool checkDown(char gameBoard[3][3])
{
   
    if(gameBoard[0][0] == 'X' && gameBoard[1][0] == 'X' && gameBoard[2][0] == 'X')
        return true;
    else if(gameBoard[0][1] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][1] == 'X')
        return true;
    else if(gameBoard[0][2] == 'X' && gameBoard[1][2] == 'X' && gameBoard[2][2] == 'X')
        return true;
    else if(gameBoard[0][0] == 'O' && gameBoard[1][0] == 'O' && gameBoard[2][0] == 'O')
        return true;
    else if(gameBoard[0][1] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][1] == 'O')
        return true;
    else if(gameBoard[0][2] == 'O' && gameBoard[1][2] == 'O' && gameBoard[2][2] == 'O')
        return true;
    else
        return false;
}
bool checkDiag(char gameBoard[3][3])
{
    if(gameBoard[0][0] == 'X' && gameBoard[2][2] == 'X' && gameBoard[1][1] == 'X')
        return true;
    else if(gameBoard[1][1] == 'X' && gameBoard[2][0] == 'X' && gameBoard[0][2] == 'X')
        return true;
    else if(gameBoard[0][0] == 'O' && gameBoard[2][2] == 'O' && gameBoard[1][1] == 'O')
        return true;
    else if(gameBoard[1][1] == 'O' && gameBoard[2][0] == 'O' && gameBoard[0][2] == 'O')
        return true;
    else
        return false;
}
// Prompts and validates playerX
void playerX()
{
    validate_XRowInput(); 
    validate_XColumnInput(); 
    // Validates input range
    if(row < 0 || row >= 3 || column < 0 || column >= 3)
    {
        cout << "Invalid input(s)\n";
        playerX();
    }
    else if(gameBoard[row][column] == 'X')
    {
        cout << "You've already moved there\n";
        playerX();
    }
    else if(gameBoard[row][column] == 'O')
    {
        cout << "Player O has already moved there.\n";
        playerX();
    }   
    else
    {
        gameBoard[row][column] = 'X';
    }
}
// Prompts and validates playerO
void playerO()
{
    validate_ORowInput();
    validate_OColumnInput();
    // validates input
    if(row < 0 || row >= 3 || column < 0 || column >= 3)
    {
        cout << "Invalid input(s)\n";
        playerO();
    }
    else if(gameBoard[row][column] == 'O')
    {
        cout << "You've already moved there\n";
        playerO();
    }
    else if(gameBoard[row][column] == 'X')
    {
        cout << "Player X has already moved there.\n";
        playerO();
    }
    else
    {
        gameBoard[row][column] = 'O';
    }
}
void printGameboard(char gameBoard[3][3])
{
    for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << gameBoard[i][j];
            }
            cout << endl;
        }
    return;  
}
void validate_XRowInput()
{
// This will loop forever until the user inputs the correct data type that is declared by 'row'
while(true)
    {
        cout << "Player X please enter 1, 2, 3 for row: ";
        getline(cin, rowInput);
        // This code converts from string to number safely.
        stringstream rowStream(rowInput);
        if (rowStream >> row)
            break;
        cout << "Invalid input(s)" << endl;
    }
    row--;
}
void validate_XColumnInput()
{
// This will loop forever until the user inputs the correct data type that is declared by 'row'
while(true)
    {
        cout << "Player X please enter 1, 2, 3 for column: ";
        getline(cin, columnInput);
        // This code converts from string to number safely.
        stringstream columnStream(columnInput);
        if (columnStream >> column)
            break;
        cout << "Invalid input(s)" << endl;
    }
    column--;
}

void validate_ORowInput()
{
while(true)
    {
        cout << "Player O please enter 1, 2, 3 for row: ";
        getline(cin, rowInput);
        // This code converts from string to number safely.
        stringstream rowStream(rowInput);
        if (rowStream >> row)
            break;
        cout << "Invalid input(s)" << endl;
    }
    row--;
}
void validate_OColumnInput()
{
while(true)
    {
        cout << "Player O please enter 1, 2, 3 for column: ";
        getline(cin, columnInput);
        // This code converts from string to number safely.
        stringstream columnStream(columnInput);
        if (columnStream >> column)
            break;
        cout << "Invalid input(s)" << endl;
    }
    column--;
}