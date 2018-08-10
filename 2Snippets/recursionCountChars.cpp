#include <iostrem>
#include <string>
using namespace std;

int numChar(char, string, int)

int main()
{

}

int numChar (char search, string str, int subscript)
{
    if (subscript >= str.length())
    {
        // Base case: end of string is reached
        return 0;
    }
    else if (if str[subscript] == search)
    {
            // Recursive case: A matching character was found.
            // Return 1 plus the number of times the search
            // character appears in the rest of the string.
            return 1 + numChars(search, str, subscript+1);
    }
    else 
    {
        // Recursive case: A matching character was found.
        // Return 1 plus the number of times the search
        // character appears in the rest of the string.
        return numChars(search, str, subscript+1);
    }
}
