#include <iostream>
using namespace std;
class Package
{
    private:
        int value;
    public:
        Package()
        { value = 7; cout << value << endl; }
        Package(int v)
        { value = v; cout << value << endl; }
        ~Package()
        { cout << value << endl; }
};
int main()
{
    Package obj1(4);
    Package obj2();
    Package obj3(2);
   /*  cout << endl << endl;
    cout << "obj1" << endl;
    Package obj1(4);
    cout << "obj2" << endl;
    Package obj2();
    cout << "obj3" << endl;
    Package obj3(2);
    cout << "return" << endl; */

return 0;
}