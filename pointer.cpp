#include <iostream>
using namespace std;

void test()
{
    int x = 10;
    int y = 20;
    int z = 30;
    cout << &x <<  endl;
    cout << &y <<  endl;
    cout << &z <<  endl;
}

int main() 
{
    int a = 10;
    short ch;
    int b = 20;
    double d;
    int c = 30;
    cout << &a <<  endl;
    cout << &ch << endl;
    cout << &b <<  endl;
    cout << &d <<  endl;
    cout << &c <<  endl;
}
// 출력 결과
// 0x16b85324c
// 0x16b853248
// 0x16b853244
// 0x16b85320c
// 0x16b853208
// 0x16b853204