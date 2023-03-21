#include <iostream>
using namespace std;

void func()
{
    int a = 20;
    cout << "func : " << a << endl; // func의 a 변수 값 출력
}

int main() 
{
    int a = 0;

    for (int i = 0; i < 3; i++) // i도 for문의 지역변수
    {
        int a = 20; // for 문 내에서 쓰이는 a 지역변수, main의 a랑 충돌하지 않음
        cout << "for : " << a << endl; // for의 a 변수 값 출력
    }
    func();
    cout << "main : " << a << endl; // main의 a 변수 값 출력
}
// 출력 결과
// for : 20 // for 문은 중괄호 내부를 반복하는 기능이고 3번 반복하도록 해서 결과가 3번 나옴
// for : 20
// for : 20
// func : 20
// main : 0