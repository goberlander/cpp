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


char gameboard[3][3] = {{'*','*','*'},{'*','*','*'},{'*','*','*'}};
void printGameboard(char gameboard[3][3]); // Will display the gameboard each turn

// Checks the gameboard for winners
bool checkBoard(char gameboard[3][3]);
bool checkAcross(char gameboard[3][3]);
bool checkDown(char gameboard[3][3]);
bool checkDiag(char gameboard[3][3]);

// This and the 3 other functions below validates the user's inputs if they are ints
void playerX(void); 
void playerO(void);
void validate_XRowInput(); 
void validate_XColumnInput();
void validate_ORowInput();
void validate_OColumnInput();

/*** COMPUTER FUNCTIONS ***/
void firstMove(); // fist computer move

// Will check for edge moves, and go down the specific tree
void edgeFunctionCall(); //will call the below functions in one swoop
void topEdge();
void rightEdge();
void bottomEdge();
void leftEdge();
void bottomLeftCorner();

int counter = 0, // For determing Cat's game
row,
column;

// Used to validate input
string rowInput = "";
string columnInput = "";

int main()
{
    cout << "Computer moves first\n";
    firstMove();
    while (counter <= 9)
    {            
        counter++;
        if(counter == 9)
        {
            cout << "Cat's game!\n";
            break;
        }
        // Prompts and validates playerO move
        playerO(); 
        printGameboard(gameboard);
        if(checkBoard(gameboard) == true)
        {
            cout << "Player O wins!" << endl;
            break;
        }
        counter++;    

         // COMP FUNCTIONS HERE
        cout << "Computer's turn\n";
        edgeFunctionCall();
        bottomLeftCorner();
        printGameboard(gameboard);
        // pick a move based on O's moves
        // validate move
        if(checkBoard(gameboard) == true)
        { 
            cout << "Computer wins!" << endl;
            break;
        }
        counter++;   
    }   
}
// Calls other functions to check the board for win
bool checkBoard(char gameboard[3][3])
{
    if(checkAcross(gameboard) == true)
        return true;
    else if(checkDown(gameboard) == true)
        return true;
    else if(checkDiag(gameboard) == true)
        return true;
    else
        return false;
}   
bool checkAcross(char gameboard[3][3])
{   
    if(gameboard[0][0] == 'X' && gameboard[0][1] == 'X' && gameboard[0][2] == 'X')
        return true; 
    else if(gameboard[1][0] == 'X' && gameboard[1][1] == 'X' && gameboard[1][2] == 'X')
        return true; 
    else if(gameboard[2][0] == 'X' && gameboard[2][1] == 'X' && gameboard[2][2] == 'X')
        return true;    
    else if(gameboard[0][0] == 'O' && gameboard[0][1] == 'O' && gameboard[0][2] == 'O')
        return true; 
    else if(gameboard[1][0] == 'O' && gameboard[1][1] == 'O' && gameboard[1][2] == 'O')
        return true; 
    else if(gameboard[2][0] == 'O' && gameboard[2][1] == 'O' && gameboard[2][2] == 'O')
        return true;
    else
        return false;   
}
bool checkDown(char gameboard[3][3])
{
   
    if(gameboard[0][0] == 'X' && gameboard[1][0] == 'X' && gameboard[2][0] == 'X')
        return true;
    else if(gameboard[0][1] == 'X' && gameboard[1][1] == 'X' && gameboard[2][1] == 'X')
        return true;
    else if(gameboard[0][2] == 'X' && gameboard[1][2] == 'X' && gameboard[2][2] == 'X')
        return true;
    else if(gameboard[0][0] == 'O' && gameboard[1][0] == 'O' && gameboard[2][0] == 'O')
        return true;
    else if(gameboard[0][1] == 'O' && gameboard[1][1] == 'O' && gameboard[2][1] == 'O')
        return true;
    else if(gameboard[0][2] == 'O' && gameboard[1][2] == 'O' && gameboard[2][2] == 'O')
        return true;
    else
        return false;
}
bool checkDiag(char gameboard[3][3])
{
    if(gameboard[0][0] == 'X' && gameboard[2][2] == 'X' && gameboard[1][1] == 'X')
        return true;
    else if(gameboard[1][1] == 'X' && gameboard[2][0] == 'X' && gameboard[0][2] == 'X')
        return true;
    else if(gameboard[0][0] == 'O' && gameboard[2][2] == 'O' && gameboard[1][1] == 'O')
        return true;
    else if(gameboard[1][1] == 'O' && gameboard[2][0] == 'O' && gameboard[0][2] == 'O')
        return true;
    else
        return false;
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
    else if(gameboard[row][column] == 'O')
    {
        cout << "You've already moved there\n";
        playerO();
    }
    else if(gameboard[row][column] == 'X')
    {
        cout << "Player X has already moved there.\n";
        playerO();
    }
    else
    {
        gameboard[row][column] = 'O';
    }
}
void printGameboard(char gameboard[3][3])
{
    for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << gameboard[i][j];
            }
            cout << endl;
        }
    return;  
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

void firstMove()
{
    gameboard[1][1] = 'X';
    printGameboard(gameboard); 
}

void edgeFunctionCall()
{
    topEdge();
    rightEdge();
    bottomEdge();
    leftEdge();
}
// These still need the else statements.
void topEdge()
{
    if(gameboard[0][1] == 'O') // TE
    {
        cout << "top edge pre if entered\n";
        if(gameboard[1][2] != 'O') // RE
        {
            gameboard[2][2] = 'X'; // BRC
        }
    }     
    if(gameboard[0][1] == 'O' && gameboard[0][0] == 'O') // TE; TLC
    { 
        cout << "top edge main if entered\n";
        {
            gameboard[0][2] = 'X'; // TRC
        }
        if(gameboard[0][1] == 'O' && gameboard[0][0] == 'O' && gameboard[2][0] == 'O' && gameboard[0][2]) // LE; TLC; BLC
            {
                gameboard[1][2] = 'X'; // RE to win
            }
        else if(gameboard[0][1] == 'O' && gameboard[0][0] == 'O' && gameboard[1][2] == 'O') // LE; TLC; RE
            {
                gameboard[2][0] = 'X'; // BLC to win
            }
    }
     /*    else
            gameboard[2][0] = 'X'; */ // BLC to win if they don't move BLC
}
void rightEdge()
{
    if(gameboard[1][2] == 'O') // RE
    {
        cout << "right pre main if entered\n";
        if(gameboard[0][1] != 'O') // TE
        {
            gameboard[0][0] = 'X'; // TLC
        }
    }
    if(gameboard[1][2] == 'O' && gameboard[2][2] == 'O') // RE; BRC
    {    
        cout << "right edge main if entered\n";
        {
            gameboard[0][2] = 'X'; // TRC
        }
        if(gameboard[1][2] == 'O' && gameboard[2][2] == 'O' && gameboard[2][0] == 'O') // RE; BRC; BLC
            {
                gameboard[0][1] = 'X'; // TE
            }
        else if(gameboard[1][2] == 'O' && gameboard[2][2] == 'O' && gameboard[0][1] == 'O') // RE; BRC; TE
            {
                gameboard[2][0] = 'X'; // BLC;
            }
        /* else
            gameboard[2][2] = 'X'; */ // BRC to win if they don't move BRC
    }
}
void bottomEdge()
{
    if(gameboard[2][1] == 'O') // BE
    {
        cout << "bottom edge pre if entered\n";
        if(gameboard[1][0] != 'O') // LE
        {
            gameboard[0][0] = 'X'; // TLC
        }
    }
    if(gameboard[2][1] == 'O' && gameboard[2][2] == 'O') // BE; BRC
    {
        cout << "bottom edge main if entered\n";
        {
            gameboard[2][0] = 'X'; // BLC (and to block)
        }
        if(gameboard[2][1] == 'O' && gameboard[2][2] == 'O' && gameboard[0][2] == 'O') // BE; BRC; TRC
            {
                gameboard[1][0] = 'X'; // LE
            }
        else if(gameboard[2][1] == 'O' && gameboard[2][2] == 'O' && gameboard[1][0] == 'O') // BE; BRC; LE
            {
                gameboard[0][2] = 'X'; // TRC
            }
        /* else
            gameboard[2][2] = 'X';  */// BRC to win of they don't move BRC
    }
}
void leftEdge()
{
    if(gameboard[1][0] == 'O') // LE
    {
        cout << "left edge pre if entered\n";
        if(gameboard[2][1] != 'O' && gameboard[0][2] != 'X') // BE
        {
            gameboard[2][2] = 'X'; // BRC
        }
    }
    if(gameboard[1][0] == 'O' && gameboard[0][0] == 'O') // LE; TLC
    {
        cout << "left edge main if entered\n";
        {
            gameboard[2][0] = 'X'; // BLC
        }
        if(gameboard[1][0] == 'O' && gameboard[0][0] == 'O' && gameboard[0][2] == 'O') // LE; TLC; TRC
            {
                gameboard[2][1] = 'X'; // BE to win
            }
        else if(gameboard[1][0] == 'O' && gameboard[0][0] == 'O' && gameboard[2][1] == 'O') // LE; TLC; BE
            {
                gameboard[0][2] = 'X'; // TRC to win
            }
       /*  else
            gameboard[2][0] = 'X'; */ // BLC to win if they don't move BLC
    }
}

void bottomLeftCorner() // If playerO's first move is bottom left
{
    if(gameboard[2][0] == 'O') // BLC
    {
        {
            if(gameboard[0][0] != 'O' && gameboard[0][2] != 'O' && gameboard [2][2] != 'O') //if the other corners are empty
            {
                gameboard[0][2] = 'X'; // TRC
            }
        }
        if(gameboard[1][0] == 'O') // LE
        {
            cout << "bottom left corner if entered\n";
            {
                gameboard[0][0] = 'X'; // TLC
            }
            if(gameboard[2][2] == 'O') // BRC
                {
                    gameboard[0][1] = 'X'; // TE
                }
            else if(gameboard[0][1] == 'O') // TE
                {
                    gameboard[2][2] = 'X'; // BRC
                }
        }
    }

}