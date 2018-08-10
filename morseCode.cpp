#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<ctype.h>

void promptUser();
void processInput(char funcInput[], int stringLength);

using namespace std;

int main()
{
    cout << "Enter a word and I will translate it to Morse code." << endl;
    cout << "-> ";
    promptUser();// function to prompt user
    // function iterate through string, print associated morse code
}

void promptUser()
{
    char input[50];
    cin.getline(input, 50);
    int stringLength = strlen(input);
    processInput(input, stringLength);
}

void processInput(char funcInput[], int stringLength)
{
    for(int i = 0; i < stringLength; i++)
    {
        toupper(funcInput[i]);
        cout << funcInput[i];
    }
    cout << endl;
    for(int i = 0; i < stringLength; i++)
    {
        switch(funcInput[i])
        {
        case 'A': cout << ".-"; break;
        case 'B': cout << "-..."; break;
        case 'C': cout << "-.-."; break;
        case 'D': cout << "-.."; break;
        case 'E': cout << "."; break;
        case 'F': cout << "..-."; break;
        case 'G': cout << "--."; break;
        case 'H': cout << "...."; break;
        case 'I': cout << ".."; break;
        case 'J': cout << ".---"; break;
        case 'K': cout << "-.-"; break;
        case 'L': cout << ".-.."; break;
        case 'M': cout << "--"; break;
        case 'N': cout << "-."; break;
        case 'O': cout << "---"; break;
        case 'P': cout << ".--."; break;
        case 'Q': cout << "--.-"; break;
        case 'R': cout << ".-."; break;
        case 'S': cout << "..."; break;
        case 'T': cout << "-"; break;
        case 'U': cout << "..-"; break;
        case 'V': cout << "...-"; break;
        case 'W': cout << ".--"; break;
        case 'X': cout << "-..-"; break;
        case 'Y': cout << "-.--"; break;
        case 'Z': cout << "--.."; break;
        case '0': cout << "-----"; break;
        case '1': cout << ".----"; break;
        case '2': cout << "..---"; break;
        case '3': cout << "...--"; break;
        case '4': cout << "....-"; break;
        case '5': cout << "....."; break;
        case '6': cout << "-...."; break;
        case '7': cout << "--..."; break;
        case '8': cout << "---.."; break;
        case '9': cout << "----."; break;
        case ' ': cout << " "; break;
        case ',': cout << "--..-- "; break;
        case '.': cout << ".-.-.-"; break;
        case '?': cout << "..--.."; break;
        default: cout << "You've entered invalid characters.";
        }
    }
}