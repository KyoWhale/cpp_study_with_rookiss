#include <iostream>
using namespace std;

void SetNumber(int* a)
{
    *a = 1;
}

void SetMessage(const char* a)
{
    a = "Bye";
}

void SetMessage(const char** a)
{
    *a = "Bye Bye";
}

void SetMessage2(const char*& a)
{
    a = "Wow";
}

int main()
{
    int a = 0;
    SetNumber(&a);
    cout << a << endl;

    const char* msg = "Hello";
    SetMessage(msg);
    cout << msg << endl;
    // 주소 값을 들고 있는 바구니일 뿐이지 함수의 매개변수 포인터 안에 들어있는 주소를 바꿔도 어차피 main의 포인터 변수에 들어있는 값(주소)이 바뀌는건 아님
    
    // main
    // msg = "Hello"의 주소

    // SetMessage
    // a = "Hello"의 주소
    // a = "Bye"의 주소

    // main으로 돌아와도 a의 값을 바꾼 것이기 때문에 msg의 값은 바뀌지 않았음
    // msg = "Hello"의 주소

    // 그럼 어떻게 바꿔야하나?
    // 이중 포인터
    // 포인터의 의미 : 주소값을 담는 변수
    // 이중 포인터의 의미 : 주소값을 담는 변수의 주소값을 담는 변수
    const char** pp = &msg;
    cout << *pp << endl;
    *pp = "Bye";
    cout << *pp << endl;
    SetMessage(pp);

    // 삼중, 사중 포인터도 가능하지만 이중 포인터 이상으로 들어갈 일이 별로 없음

    // 이중포인터를 콜 바이 레퍼런스를 사용해서도 가능함
    SetMessage2(msg);

    return 0;
}