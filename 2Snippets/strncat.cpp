#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    /* char string1[10] = "Johnathan";
    char string2[] = "Doe";
    strncpy(string1, string2, 4);
    cout << string1 << endl; */
    char string1[] = "John was a cool guy.";
    char string2[] = "cool";
    strstr(string1, string2); // string1 is searched for with the index of string2.
    cout << string2 << endl;
}