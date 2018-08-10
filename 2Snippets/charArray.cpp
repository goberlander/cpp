#include <iostream>
#include <cstring>
using namespace std;
int main()
{
char string1[10] = "Johnathan";    
char string2[] = "Doe";    
strncpy(string1, string2, 5);    
cout << string1 << endl; // Outputs "Doe".
for(int i = 0; i < strlen(string1); i++)
    cout << string1[i] << endl;
}