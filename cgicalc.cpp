#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    const double CRATE_COST = 0.23;
    const double CUST_CHARGE = 0.5;

    double volume, length, width, height; //to get volume of box from user and store that value
    double profit, totalCost, totalPrice; //money made

    // Set the desired output formatting for numbers.
    cout << setprecision(2) << fixed << showpoint; //didn't have this

    cout << "Length: ";
    cin >> length;
    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;
    volume = length * width * height;
    cout << "Volume = " << volume << endl;

    totalCost = CRATE_COST * volume;
    totalPrice = CUST_CHARGE * volume;
    profit = totalPrice - totalCost;
    cout << "The cost of crate = " << totalCost << endl;
    cout << "The price of crate = " << totalPrice << endl;
    cout << "Profit made = " << profit << endl;
    return 0;

    


}