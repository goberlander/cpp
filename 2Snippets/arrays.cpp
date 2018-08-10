/*const int AGES = 10;
int youngAdults[AGES] = {5, 7, 8, 14, 15, 17, 18, 19, 21, 23};

//array2
float temps[] = {14.7, 16.3, 18.43, 21.09, 17.9, 18.76, 26.7};

//array3

char alpha[] = {'J', 'B', 'L', 'A', '*', '$', 'H', 'M'};
*/

#include <iostream>
#include <iomanip> //for setprecision
using namespace std;

int main()
{
int tests[5] = {79,82,91,77,84};

for (int count = 0; count < 7; count++)

    {

    cout << tests[count] << endl;

    }

}


/* ARRAY EXAMPLES
int main()
{
    int values[] = {2, 6, 10, 14};
    cout << values[1]++;
    //this prints out 6, then increases it by 1, making element 1 7.
    //another cout << values[1] would print 7
}

{
    int values[] = {2, 6, 10, 14};
    cout << values[2];
    //this prints 10
}

{
    int values[] = {2, 6, 10, 14};
    cout << ++values[0];
    //this prints 3. It increases the value at element 0 by 1.
}

{
    int values[] = {2, 6, 10, 14};
    int x = 2;
    cout << values[++x];
    //this prints 14 because it increases x (3) then outputs that value
}

{ //this prints out 0. This is considered a global array because it is initialized within main.
    int nums[5] = {1, 2, 3};
    cout << nums[3];
}
*/