#include <iostream>
using namespace std;

int returnRecursion(int [], int, int);
//int specificNumberCount(int [], int, int)

int main()
{
    const int ARRAY_SIZE = 5;
    int recurseCount = 0;
    int array[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    recurseCount = returnRecursion(array, ARRAY_SIZE, recurseCount);
    cout << recurseCount << endl;
}

int recursionCount(int array[], int ARRAY_SIZE, int count)
{
    //static int recurseCount = 0;
    if(count >= ARRAY_SIZE) // Base case. Count has become equal to the size of the array.
    {
        return 0;
    }
    else
        return recursionCount(array, ARRAY_SIZE, count+1);
}

//int specificNumber