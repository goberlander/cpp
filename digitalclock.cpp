#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outputFile; //output stream object created into outputFile
    outputFile.open("demofile.txt"); //names the file demofile.txt (I think)
    cout << "Now writing data to the file...";
    
    outputFile << "Beethoven\n";
    outputFile << "Mozart\n";
    outputFile << "Bach\n";
    outputFile << "Schubert\n";

    outputFile.close();
    cout << "Done.\n";



}