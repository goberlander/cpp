#include<iostream>
#include<string>
#include<cstring>
#include<ctype.h>


using namespace std;

int main()
{
    int stringLength = 0;
    char input[50];
    cout << "Enter a word and I will translate it to Morse code." << endl;
    cout << "-> ";
    cin.getline(input, 50);
    stringLength = strlen(input);
    for(int i = 0; i < stringLength; i++)
    {
        input[i] = toupper(input[i]);
    }
    for(int j = 0; j < stringLength; j++)
    {
        switch(input[j])
        {
        case 'A': cout << ".-" << endl; break;
        case 'B': cout << "-..." << endl; break;
        case 'C': cout << "-.-." << endl; break;
        case 'D': cout << "-.." << endl; break;
        case 'E': cout << "." << endl; break;
        case 'F': cout << "..-." << endl; break;
        case 'G': cout << "--." << endl; break;
        case 'H': cout << "...." << endl; break;
        case 'I': cout << ".." << endl; break;
        case 'J': cout << ".---" << endl; break;
        case 'K': cout << "-.-" << endl; break;
        case 'L': cout << ".-.."<< endl; break;
        case 'M': cout << "--" << endl; break;
        case 'N': cout << "-." << endl; break;
        case 'O': cout << "---" << endl; break;
        case 'P': cout << ".--." << endl; break;
        case 'Q': cout << "--.-" << endl; break;
        case 'R': cout << ".-." << endl; break;
        case 'S': cout << "..." << endl; break;
        case 'T': cout << "-" << endl; break;
        case 'U': cout << "..-" << endl; break;
        case 'V': cout << "...-" << endl; break;
        case 'W': cout << ".--" << endl; break;
        case 'X': cout << "-..-" << endl; break;
        case 'Y': cout << "-.--" << endl; break;
        case 'Z': cout << "--.." << endl; break;
        case '0': cout << "-----" << endl; break;
        case '1': cout << ".----" << endl; break;
        case '2': cout << "..---" << endl; break;
        case '3': cout << "...--" << endl; break;
        case '4': cout << "....-" << endl; break;
        case '5': cout << "....." << endl; break;
        case '6': cout << "-...." << endl; break;
        case '7': cout << "--..." << endl; break;
        case '8': cout << "---.." << endl; break;
        case '9': cout << "----." << endl; break;
        case ' ': cout << " " << endl; break;
        case ',': cout << "--..-- " << endl; break;
        case '.': cout << ".-.-.-" << endl; break;
        case '?': cout << "..--.." << endl; break;
        default: cout << "You've entered invalid characters."; return 0;
        }
    }
}