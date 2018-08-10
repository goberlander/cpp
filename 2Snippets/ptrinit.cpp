#include <iostream>

using namespace std;

int main()
{
    int *arrayPtr = nullptr;
    int array[] = {0, 1, 2, 3, 4};
    arrayPtr = array;
    int sum;
    sum += ++*array;
    cout << sum;
}