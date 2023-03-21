#include <iostream>
using namespace std;

void func()
{
    static int a = 0;
    a++;
    cout << a << endl;
}

int main() 
{
    static int a = 0;
    a++;
    cout << a << endl;
    func();
    func();
}
// 출력결과
// 1
// 1
// 2