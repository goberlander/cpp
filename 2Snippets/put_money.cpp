#include <locale>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    long double mon = 4000.00;
    cout.imbue(locale("en_US.utf8"));
    cout << put_money(mon);
}