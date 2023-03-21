#include <iostream>
using namespace std;

void Print1(int a = 10)
{
    cout << a << endl;
}

void Print2(int a = 1, int b = 2)
{
    cout << a << ", " << b << endl;
}

void Print3(int a = -1, int b = -2, int c = -3)
{
    cout << a << ", " << b << ", " << c << endl;
}

int main()
{
    Print1();
    Print1(0);

    Print2(10);
    Print2(10, 20);

    Print3(3);
    Print3(3, 4);
    Print3(3, 4, 5);
}
// 출력 결과
// 10
// 0
// 10, 2
// 10, 20
// 3, -2, -3
// 3, 4, -3
// 3, 4, 5