#include <iostream>
using namespace std;

void PassByValue(int x) // 메인 함수의 x 변수와 이 함수의 매개변수인 x는 다른 변수
{
    x++; // 함수의 지역변수인 매개변수 x의 값을 1 증가시킴
}

int main()
{
    int x = 10;
    cout << "Before : " << x << endl;
    PassByValue(x);
    cout << "After  : " << x << endl;
}
// 출력 결과
// Before : 10
// After  : 10