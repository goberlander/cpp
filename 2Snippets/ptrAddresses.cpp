#include <iostream>
using namespace std;
int main()
{
int *ptr;
ptr += 10;

cout << ptr;
}

// When int data type ptr is stored at these addresses
// 0x401a1b: ptr or ptr += 0;
// 0x401a1f: ptr += 1
// 0x401a23: ptr += 2
// 0x401a27: ptr += 3
// 0x401a2b: ptr += 4
// 0x401a2f: ptr += 5
// 0x401a33: ptr += 6
// 0x401a37: ptr += 7
// 0x401a3b: ptr += 8
// 0x401a3f: ptr += 9
// 0x401a43: ptr += 10