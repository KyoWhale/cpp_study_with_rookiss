#include <iostream>
using namespace std;

// 함수 사진
// 인풋과 아웃풋이 있는 간단한 기계
// 경우에 따라, 인풋, 아웃풋이 없을 수 있음
// 코드를 재사용하기 쉽게 기능별로 나누기 위함

// 반환타입 함수이름(매개변수의자료형 매개변수이름)
// {
//     문장1;
//     문장2;
//     return 반환타입의변수 혹은 값
// }

void PrintHelloWorld()
{
    cout << "Hello World" << endl;
}

void PrintNumber(int num)
{
    cout << "Print : " << num << endl;
    return;
}

int MultiplyBy2(int num)
{
    int temp = num * 2;
    return temp;
    // return num * 2;
}

int MultiplyBy(int a, int b)
{
    return a * b;
}

int main()
{
    PrintHelloWorld();

    int a = 10;
    PrintNumber(a);
    PrintNumber(20);

    int b = MultiplyBy2(a);
    cout << "b : " << b << endl;

    int c = MultiplyBy(a, b);
    cout << "c : " << c << endl;

    return 0;
}