#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;


char gameBoard[3][3] = {{'*','*','*'},{'*','*','*'},{'*','*','*'}};


bool checkBoard(char gameBoard[3][3]);
void playerX();
void playerO();
void printGameboard(char gameBoard[3][3]);
bool checkAcross(char gameBoard[3][3]);
bool checkDown(char gameBoard[3][3]);
bool checkDiag(char gameBoard[3][3]);

int counter = 0, row = 0, column = 0;
string rowInput = "";
string columnInput = "";

int main()
{
    while (counter <= 9)
    {
        while(true)
        {
            cout << "Player X, please enter 1, 2, 3 for row: ";
            getline(cin, rowInput);
            stringstream rowStream(rowInput);
           /*  if (rowStream >> row)
                    break;
            cout << "Invalid input(s)" << endl;
            playerX();  */
        
            cout << "Player X, please enter 1, 2, 3 for column: ";
            getline(cin, columnInput);    
            stringstream columnStream(columnInput);
                if(rowStream >> row || columnStream >> column)
                    break;
            cout << "Invalid input(s)" << endl;
            //playerX();
        }
        cout << row << endl;
        cout << column << endl;
        
        // Prompts and validates playerX input
        //playerX();
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
        
        // Prompts and validates playerO input
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
// calls other functions to check the board for win
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
    for(int i; i < 9; i++)
    {
        for(int j; j < i; j++)
        {
            if(gameBoard[i][j] == 'X' || gameBoard[i][j] == 'O')
            {
                if(gameBoard[0][0] == gameBoard[0][1] && gameBoard[0][1] == gameBoard[0][2])
                {   
                    cout << "condition 1 entered"; 
                    return true;
                } 
                else if(gameBoard[1][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[1][2])
                    {   
                    cout << "condition 1 entered"; 
                    return true;
                } 
                else if(gameBoard[2][0] == gameBoard[2][1] && gameBoard[2][1] == gameBoard[2][2])
                    {   
                    cout << "condition 1 entered"; 
                    return true;
                }
                else
                    return false;
            }    
            else
                return false;
        }   
    }
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
   

        
        /* cout << "Now please enter 1, 2, 3 for column: ";
        cin >> column;
        column--; */

    // Validates input
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
    cout << "Player O please enter 1, 2, 3 for row: "; // Has to be 1, 2, 3 tho
    cin >> row;
    row--;
    cout << "Now please enter 1, 2, 3 for column: ";
    cin >> column;
    column--;
    
    // validates input
    if(row < 0 || row >= 3 || column < 0 || column >= 3)
    {
        cout << "Invalid input(s)\n";
        playerO();
    }
    else if(cin.fail())
    {
        cin.clear();
        cin.ignore();
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
