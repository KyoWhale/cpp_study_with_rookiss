#include <iostream>
using namespace std;

int globalValue = 0;

void Func1()
{
    globalValue++;
}

void Func2(int localValue)
{
    localValue++;
}

int main()
{
    cout << "GlobalValue : " << globalValue << endl;
    Func1();
    cout << "GlobalValue : " << globalValue << endl;
    
    int localValue = 10; // 함수의 매개변수와 이름이 같다해서 같은 변수가 아님
    cout << "LocalValue : " << localValue << endl;
    Func2(localValue);
    cout << "LocallValue : " << localValue << endl;
}
