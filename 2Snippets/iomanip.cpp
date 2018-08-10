#include <iostream>
#include <iomanip> //used for setprecision
using namespace std;

int main()
{
    const double COST_PER_CUBIC_FOOT = .23;
    const double CHARGE_PER_CUBIC_FOOT = .5;

    double length, width, height, volume, cost, charge, profit;

    cout << setprecision(2) << fixed << showpoint;

    cout << "Enter the crates length: " << endl;
    cin >> length;
    cout << "... The width: " << endl;
    cin >> width;
    cout << "... The height: " << endl;
    cin >> height;

    volume = length * width * height;
    cost = volume * COST_PER_CUBIC_FOOT;
    charge = volume * CHARGE_PER_CUBIC_FOOT;
    profit = charge - cost;
}