#include <iostream>
using namespace std;

int a = 20;
void func()
{
    cout << "global : " << a << endl; // 전역변수 a 변수 값 출력
}

int main() 
{
    func();
    cout << "global : " << a << endl; // 전역변수의 a 변수 값 출력
    int a = 0;
    cout << "main : " << a << endl; // main의 a 변수 값 출력
}
// 출력 결과
// global : 20
// global : 20
// main : 0