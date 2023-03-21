#include <iostream>
using namespace std;

void Func1();
void Func2();
void Func3();

void Func1()
{
    cout << "Call Func1" << endl;
    Func2();
    cout << "End Func1" << endl;
}

void Func2()
{
    cout << "Call Func2" << endl;
    Func3();
    cout << "End Func2" << endl;
}

void Func3()
{
    cout << "Call Func3" << endl;
    cout << "Do Stuff in Func3" << endl;
    cout << "End Func3" << endl;
}

int main()
{
    Func1();
}
// 출력 결과
// Call Func1
// Call Func2
// Call Func3
// Do Stuff in Func3
// End Func3
// End Func2
// End Func1