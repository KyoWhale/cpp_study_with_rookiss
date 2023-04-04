#include <iostream>
using namespace std;

void Print(int a)
{
    cout << a << endl;
}

void Print(float a)
{
    cout << a << endl;
}

// 템플릿 함수
template<typename T>
void Print(T value)
{
    cout << value << endl;
}

// T를 여러곳에 사용 가능
template<typename T>
T Add(T a, T b)
{
    return a + b;
}

// 여러가지 다른 타입의 사용
template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
    cout << a << " " << b << endl;
}

class Knight
{
public:

public:
    int _hp = 100;
};

ostream& operator<<(ostream& os, const Knight& k)
{
    os << k._hp;
    return os;
}

// 템플릿 특수화
template<>
void Print(Knight a)
{
    cout << "Knight !!!!!!!!!" << endl;
    cout << a._hp << endl;
}

int main()
{
    // 템플릿 : 함수나 클래스를 찍어내는 툴
    // 1. 함수 템플릿
    // 2. 클래스 템플릿

    Print(50);
    Print(10.1f);
    // 오버로딩을 하면 되긴하지만, 번거로움

    Print("asd"); // template 함수로 호출됨
    Print<int>(50.0f); // 명시적으로 템플릿에 자료형을 지정하고 호출

    cout << Add(5, 7) << endl;
    cout << Add(12.4f, 34.3f) << endl;

    Print(5, "Hi");

    Knight k1;
    // Print(k1); // 기사한테는 << 연산자에 대한 연산이 안됨으로 연산자 오버로딩해야함
    Print(k1);

    return 0;
}