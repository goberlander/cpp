/* C++ 11 provides a specialized version of the for loop
that, in many circumstances, simplifies array processing.

The range-based for loop is a loop that iterates once for
each element in an array.

Each time the loop iterates, it copies an element from the
array to a built-in variable, known as the range variable.

The range-based for loop automatically knows the
number of elements in an array.

You do not have to use a counter variable.

You do not have to worry about stepping outside the bounds of
the array. */

#include <iostream>

using namespace std;

int main()
{
    int numbers[] = {10, 20, 30, 40, 50};
    for(int val : numbers)
        cout << val << endl;
}