#include <iostream>

using namespace std;

void getDimensions(int);
void getDimensions(int, int);
void getDimensions(int, double);
void getDimensions(double, double);


int main()
{

}

OR

int square(int);
double square(double);

int main()
{
    int userInt;
    double userFloat;
    cout << square(userInt) << endl << square(userFloat);
}

int square(int number)
{
    return number * number;
}

double square(double number)
{
    return number * number;
}