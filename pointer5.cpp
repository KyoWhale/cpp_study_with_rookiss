#include <iostream>
using namespace std;

void TestArgumentAddr(int* ptr)
{
    cout << &ptr << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
}

int main()
{
    int num = 5;
    int* ptr = &num;

    cout << &ptr << endl;
    cout << ptr << endl;
    cout << *ptr << "\n\n";
    
    TestArgumentAddr(ptr);
}
// 출력 결과
// 0x16bb6f250
// 0x16bb6f25c
// 5

// 0x16bb6f228
// 0x16bb6f25c
// 5