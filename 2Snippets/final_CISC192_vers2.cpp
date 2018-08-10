/*
Project Name: Compu-Toe
Author: Glenn Oberlander
Version: 2.0
Date: 5.17.2018

--PROGRAM FUNCTION/PURPOSE--
This program will play the game tic-tac-toe between a computer and a human. It will validate their input to make sure that it is only 1, 2, 3, otherwise it will reprompt. Functions are setup to check a winner after each turn. 
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
// These functions below validate the user's inputs
void playerO(void);
void validate_XRowInput(); 
void validate_XColumnInput();
void validate_ORowInput();
void validate_OColumnInput();
/*** COMPUTER FUNCTIONS ***/
void firstMove(); // fist computer move
void tieGame(); // Computer will call this if opponent makes a move to lead into a tie
// Will check for edge moves, then go down the specific tree
void edgeFunctionCall(); //will call the below functions in one swoop
void topEdge();
void rightEdge();
void bottomEdge();
void leftEdge();
/* CORNER TREES */ // Will check for edge moves, then go down the specific tree
void cornerFunctionCall();
void topLeftCorner();
void topRightCorner();
void bottomLeftCorner();
void bottomRightCorner();
int counter = 0, // For determing Cat's game
row, // Storing user's input
column;
// Used for validate input functions
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
        cout << "Computer's turn...\n";
        // Pick a move based on O's moves
        edgeFunctionCall();
        cornerFunctionCall();
        printGameboard(gameboard);
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

/* COMPUTER MOVES */
void firstMove() // First move for computer (middle, obvi)
{
    gameboard[1][1] = 'X';
    printGameboard(gameboard); 
}
void edgeFunctionCall() // Tidy's up the edge functions in Main
{
    topEdge();
    rightEdge();
    bottomEdge();
    leftEdge();
}

/* HELPFUL ACRONYMS
LE, RE, TE, BE = Left, Right, Top, Bottom Edges
TLC, BRC, BLC, TRC = Top Left, etc Corners*/
void topEdge() // If playerO's first move is TOP EDGE
{
    if(gameboard[0][1] == 'O') // TE
    {
        if(gameboard[1][2] != 'O' && gameboard[1][0] != 'O' && gameboard[2][2] != 'O' && gameboard[2][0] != 'X') // RE; also makes sure it is not triggerd by other moves.
        {
            //Computer's second move
            gameboard[2][2] = 'X'; // BRC;
            if(gameboard[0][0] == 'O') // TE; TLC
            {   
                // Comp's third move
                gameboard[0][2] = 'X'; // TRC
                // Computer's fourth move options to win
                if(gameboard[2][0] == 'O') // LE; TLC; BLC
                {
                    gameboard[1][2] = 'X'; // RE to win
                }
                else if(gameboard[1][2] == 'O') // LE; TLC; RE
                {
                    gameboard[2][0] = 'X'; // BLC to win
                }
            }
        }
    }
}
void rightEdge() // If playerO's first move is RIGHT EDGE
{
    if(gameboard[1][2] == 'O') // RE
    {
        if(gameboard[0][1] != 'O' && gameboard[1][0] != 'O' && gameboard[2][2] != 'X' && gameboard[2][0] != 'X') // TE; also makes sure it is not triggerd by other
        {
            //Computer's second move
            gameboard[0][0] = 'X'; // TLC
            if(gameboard[2][2] == 'O') // RE; BRC
            {    
                // Comp's third move
                gameboard[0][2] = 'X'; // TRC
                // Computer's fourth move options to win
                if(gameboard[2][0] == 'O') // RE; BRC; BLC
                {
                    gameboard[0][1] = 'X'; // TE
                }
                else if(gameboard[0][1] == 'O') // RE; BRC; TE
                {
                    gameboard[2][0] = 'X'; // BLC;
                }
            }          
        }             
    }
}
void bottomEdge() // If playerO's first move is BOTTOM EDGE
{
    if(gameboard[2][1] == 'O') // BE
    { 
        if(gameboard[1][0] != 'O' && gameboard[2][0] != 'O' && gameboard[0][0] != 'O') // LE; also makes sure it is not triggerd by other
        {
            // Computer's second move
            gameboard[0][0] = 'X'; // TLC; 
            if(gameboard[2][2] == 'O') // BE; BRC
            {
                // Comp's third move
                gameboard[2][0] = 'X'; // BLC (and to block)
                // Computer's fourth move options to win
                if(gameboard[0][2] == 'O') // BE; BRC; TRC
                {
                    gameboard[1][0] = 'X'; // LE
                }
                else if(gameboard[1][0] == 'O') // BE; BRC; LE
                {
                    gameboard[0][2] = 'X'; // TRC
                }
            }
        }
    }
}
void leftEdge() // If playerO's first move is LEFT EDGE
{
    if(gameboard[1][0] == 'O') // LE
    {
        if(gameboard[2][1] != 'O' && gameboard[0][2] != 'X' && gameboard[0][0] != 'X') // BE
        {
            //Computer's second move
            gameboard[2][2] = 'X'; // BRC; Comp's second move
            if(gameboard[0][0] == 'O') // LE; TLC
            {
                // Comp's third move
                gameboard[2][0] = 'X'; // BLC
                // Computer's fourth move options to win
                if(gameboard[0][2] == 'O') // LE; TLC; TRC
                {
                    gameboard[2][1] = 'X'; // BE to win
                }
                else if(gameboard[2][1] == 'O') // LE; TLC; BE
                {
                    gameboard[0][2] = 'X'; // TRC to win
                }
            }
        }
    }
}

void cornerFunctionCall()
{
    bottomLeftCorner();
    bottomRightCorner();
    topLeftCorner();
    topRightCorner();
}
void bottomLeftCorner() // If playerO's first move is BOTTOM LEFT
{
    /**FIRST MOVE for Player O: BLC**/
    if(gameboard[2][0] == 'O') // BLC
    {
        if(gameboard[0][0] != 'O' && gameboard[0][2] != 'O' && gameboard [2][2] != 'O') //if the other corners are empty (so to not trigger other corners)
        {
            //Comp's second move
            gameboard[0][2] = 'X'; // TRC
        }
    // WIN (1)
        if(gameboard[1][0] == 'O') // LE
        {
            //Computer's second move
            gameboard[0][0] = 'X'; // TLC
            // Comp's fourth move options
            if(gameboard[2][2] == 'O') // BRC
            {
                gameboard[0][1] = 'X'; // TE
            }
            else if(gameboard[0][1] == 'O') // TE
            {
                gameboard[2][2] = 'X'; // BRC
            }
        }
    // WIN (2)        
        else if(gameboard[0][1] == 'O') // TE
        {
            // Comp's third move
            gameboard[2][2] = 'X'; // BRC
            // Comp's fourth move options
            if(gameboard[1][2] == 'O') // RE
            {
                gameboard[0][0] = 'X'; // TLC
            }
            else if(gameboard[0][0] == 'O')
            {
                gameboard[1][2] = 'X';
            }
        }
    // WIN (3)
        else if(gameboard[2][1] == 'O') // BE
        {
            // Comp's third move
            gameboard[2][2] = 'X'; // BRC
            // Comp's fourth move options
            if(gameboard[1][2] == 'O') // RE
            {
                gameboard[0][0] = 'X'; // TLC
            }
            else if(gameboard[0][0] == 'O')
            {
                gameboard[1][2] = 'X'; // RE
            }
        }
    // WIN (4)
        else if(gameboard[1][2] == 'O') // RE
        {
            // Comp's third move
            gameboard[0][0] = 'X'; // TLC
            // Comp's fourth move options
            if(gameboard[2][2] == 'O') // BRC
            {
                gameboard[0][0] = 'X'; // TLC
            }
            else if(gameboard[0][0] == 'O')
            {
                gameboard[2][2] = 'X'; // RE
            }
        }
    // TIE 1
        else if(gameboard[0][0] == 'O')
        {
            gameboard[1][0] = 'X';
            tieGame();
        }
    // TIE 2
        else if(gameboard[2][2] == 'O')
        {
            gameboard[2][1] = 'X';
            tieGame();
        }
    }
}
void bottomRightCorner() // If playerO's first move is BOTTOM RIGHT
{
    /**FIRST MOVE for Player O: BLC**/
    if(gameboard[2][2] == 'O') // BRC
    {
        if(gameboard[0][0] != 'O' && gameboard[0][2] != 'O' && gameboard [2][0] != 'O') //if the other corners are empty (so to not trigger other corners)
        {
            //Comp's second move
            gameboard[0][0] = 'X'; // TLC
        }
    // WIN (1)
        if(gameboard[2][1] == 'O') // BE
        {
            // Comp's third move
            gameboard[2][0] = 'X'; // BLC
            // Comp's fourth move options
            if(gameboard[0][2] == 'O') // TRC
            {
                gameboard[1][0] = 'X'; // LE
            }
            else if(gameboard[1][0] == 'O') // LE
            {
                gameboard[0][2] = 'X'; // TRC
            }
        }
    // WIN (2)        
        else if(gameboard[1][2] == 'O') // RE 
        {
            // Comp's third move
            gameboard[0][2] = 'X'; // TRC
            // Comp's fourth move options
            if(gameboard[2][0] == 'O') // BLC
            {
                gameboard[0][1] = 'X'; // TE
            }
            else if(gameboard[0][1] == 'O') // TE
            {
                gameboard[2][0] = 'X'; // BLC
            }
        }
    // WIN (3)
        else if(gameboard[1][0] == 'O') // LE
        {
            // Comp's third move
            gameboard[0][2] = 'X'; // TRC
            // Comp's fourth move options
            if(gameboard[2][0] == 'O') // BLC
            {
                gameboard[0][1] = 'X'; // TE
            }
            else if(gameboard[0][1] == 'O') // TE
            {
                gameboard[2][0] = 'X'; // BLC
            }
        }
    // WIN (4)
        else if(gameboard[0][1] == 'O') // TE
        {
            // Comp's third move
            gameboard[2][0] = 'X'; // BLC
            // Comp's fourth move options
            if(gameboard[0][2] == 'O') // TRC
            {
                gameboard[1][0] = 'X'; // LE
            }
            else if(gameboard[1][0] == 'O') // LE
            {
                gameboard[0][2] = 'X'; // TRC
            }
        }
    // TIE (1)
        else if(gameboard[0][2] == 'O' && gameboard[2][2] != 'O') // DONE
        {
            gameboard[1][0] = 'X';
            tieGame();
        }
    // TIE (2)
        else if(gameboard[2][0] == 'O') // DONE
        {
            gameboard[2][1] = 'X';
            tieGame();
        }
    }
}
void topLeftCorner() // If playerO's first move is TOP LEFT
{
    /**FIRST MOVE for Player O: TLC**/
    if(gameboard[0][0] == 'O') // TLC
    {
        if(gameboard[2][2] != 'O' && gameboard[0][2] != 'O' && gameboard [2][0] != 'O') //if the other corners are empty (so to not trigger other corners)
        {
            //Comp's second move
            gameboard[2][2] = 'X'; // BRC
        }
    // WIN (1)
        if(gameboard[0][1] == 'O') // TE
        {
            // Comp's third move
            gameboard[0][2] = 'X'; // TRC
            // Comp's fourth move options
            if(gameboard[2][0] == 'O') // BLC
            {
                gameboard[1][2] = 'X'; // RE
            }
            else if(gameboard[1][2] == 'O') // RE
            {
                gameboard[2][0] = 'X'; // BLC
            }
        }
    // WIN (2)     
        else if(gameboard[1][0] == 'O') // LE
        {
            // Comp's third move
            gameboard[2][0] = 'X'; // BLC
            // Comp's fourth move options
            if(gameboard[2][1] == 'O') // BE
            {
                gameboard[0][2] = 'X'; // TRC
            }
            else if(gameboard[0][2] == 'O') // TRC
            {
                gameboard[2][1] = 'X'; // BE
            }
        }
    // WIN (3)
        else if(gameboard[1][2] == 'O') // RE
        {
            // Comp's third move
            gameboard[2][0] = 'X'; // BLC
            // Comp's fourth move options
            if(gameboard[2][1] == 'O') // BE
            {
                gameboard[0][2] = 'X'; // TRC
            }
            else if(gameboard[0][2] == 'O') // TRC
            {
                gameboard[2][1] = 'X'; // BE
            }
        }
    // WIN (4)
        else if(gameboard[2][1] == 'O') // BE
        {
            // Comp's third move
            gameboard[0][2] = 'X'; // TRC
            // Comp's fourth move options
            if(gameboard[1][2] == 'O') // RE
            {
                gameboard[2][0] = 'X'; // BLC
            }
            else if(gameboard[2][0] == 'O') // BLC  
            {
                gameboard[1][2] = 'X'; // RE
            }
        }
    // TIE (1)
        else if(gameboard[0][2] == 'O') // BLC
        {
            gameboard[0][1] = 'X'; // LE
            tieGame();
        }
    // TIE (2)
        else if(gameboard[2][0] == 'O')
        {
            gameboard[1][0] = 'X';
            tieGame();
        }
    }
}
void topRightCorner() // If playerO's first move is TOP RIGHT
{
    /**FIRST MOVE for Player O: TRC**/
    if(gameboard[0][2] == 'O') // TRC
    {
        if(gameboard[2][2] != 'O' && gameboard[0][0] != 'O' && gameboard [2][0] != 'O') //if the other corners are empty (so to not trigger other corners)
        {
            //Comp's second move
            gameboard[2][0] = 'X'; // BLC
        }
    // WIN (1)
        if(gameboard[0][1] == 'O') // TE
        {
            // Comp's third move
            gameboard[0][0] = 'X'; // TLC
            // Comp's fourth move options
            if(gameboard[1][0] == 'O') // LE
            {
                gameboard[2][2] = 'X'; // BRC
            }
            else if(gameboard[2][2] == 'O') // BRC
            {
                gameboard[1][0] = 'X'; // LE
            }
        }
    // WIN (2)     
        else if(gameboard[1][2] == 'O' && gameboard[0][0] != 'X') // RE
        {
            // Comp's third move
            gameboard[2][2] = 'X'; // BRC
            // Comp's fourth move options
            if(gameboard[2][1] == 'O') // BE
            {
                gameboard[0][0] = 'X'; // TLC
            }
            else if(gameboard[0][0] == 'O') // TLC
            {
                gameboard[2][1] = 'X'; // BE
            }
        }
    // WIN (3)
        else if(gameboard[1][0] == 'O') // LE
        {
            // Comp's third move
            gameboard[2][2] = 'X'; // BRC
            // Comp's fourth move options
            if(gameboard[2][1] == 'O') // BE
            {
                gameboard[0][0] = 'X'; // TLC
            }
            else if(gameboard[0][0] == 'O') // TLC
            {
                gameboard[2][1] = 'X'; // BE
            }
        }
    // WIN (4)
        else if(gameboard[2][1] == 'O') // BE
        {
            // Comp's third move
            gameboard[0][0] = 'X'; // TLC
            // Comp's fourth move options
            if(gameboard[1][0] == 'O') // LE
            {
                gameboard[2][2] = 'X'; // BRC
            }
            else if(gameboard[2][2] == 'O') // BRC  
            {
                gameboard[1][0] = 'X'; // LE
            }
        }
    // TIE (1)
        else if(gameboard[0][0] == 'O') // BLC
        {
            gameboard[0][1] = 'X'; // TE
            tieGame();
        }
    // TIE (2)
        else if(gameboard[2][2] == 'O') // BRC
        {
            gameboard[1][2] = 'X'; // RE
            tieGame();
        }
    }
}
void tieGame()
{
    printGameboard(gameboard);
    cout << "Sorry, but for the interest of time, the game would tie if we continue. Exiting game...\n";
    exit(EXIT_SUCCESS);
}