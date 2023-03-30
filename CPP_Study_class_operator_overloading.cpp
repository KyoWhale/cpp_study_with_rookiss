#include <iostream>
using namespace std;

// 연산자 오버로딩
// 우선 연산자 함수를 정의해야함
// 함수도 멤버함수 vs 전역함수가 존재하는 것처럼, 연산자 함수도 두 가지 방식으로 만들 수 있음

// 멤버 연산자 함수
// - a op b 형태에서 왼쪽으로 기준으로 실행됨 
// - a를 기준 피연산자라고 함
// - a가 클래스가 아니면 사용 못함

// 전역 연산자 함수
// - a op b 형태라면, a, b 모두 연산자 함수의 피연산자로 만들어줌
// - 대입 연산자는 전역 연산자로 못 만듬

// 복사 대입 연산자
// - 자기 자신의 참조 타입을 인자로 받는 것

// 모든 연산자가 오버로딩 되는 것은 아님 (::, ., .* 등)
// 모든 연산자가 다 항이 두 개인 것은 아님 (++, --)
// 전위형 (++a) operator++()
// 후위형 (a++) operator++(int)

class Position
{
public:
    Position()
    {
        cout << "base constructor" << endl;
        _x = 0;
        _y = 0;
    }
    Position(Position& other)
    {
        cout << "copy constructor" << endl;
        _x = other._x;
        _y = other._y;
    }
    //반환형 operator연산자(매개변수)
    Position operator+(const Position& arg)
    {
        Position pos;
        pos._x = _x + arg._x;
        pos._y = _y + arg._y;
        return pos;
    }
    Position operator+(int arg)
    {
        Position pos;
        pos._x = _x + arg;
        pos._y = _y + arg;
        return pos;
    }
    bool operator==(const Position& arg)
    {
        return _x == arg._x && _y == arg._y;
    }
    Position& operator=(int arg) // 반환형이 void가 아닌 Position&라면 체인형태로 된 대입 연산자까지도 가능
    {
        _x = arg;
        _y = arg;
        return *this;
    }
    // 복사 대입 연산자
    // 객체 자체가 복사되길 원할 때 사용
    // 동적할당에서 예제 추가
    Position& operator=(const Position& arg) // const는 강제사항은 아니지만 임시객체 참조 문제 때문에 붙여주는 것이 좋음
    {
        cout << "copy assignment operator" << endl;
        _x = arg._x;
        _y = arg._y;
        return *this;
    }

    Position& operator++()
    {
        _x += 1;
        _y += 1;
        cout << "front" << endl;
        return *this;
    }
    Position operator++(int)
    {
        Position ret = *this;
        _x += 1;
        _y += 1;
        cout << "back" << endl;
        return ret;
    }
public:
    int _x;
    int _y;
};

Position operator+(int a, const Position b)
{
    Position pos;
    pos._x = b._x + a;
    pos._y = b._y + a;
    return pos;
}

//'operator=' must be a member functionC/C++(341)
// void operator=(const Position& a, int arg)
// {
//     _x = arg;
//     _y = arg;
// }

int main() 
{
    Position pos;
    Position pos2 = pos;
    pos2 = pos;

    // Position pos;
    // pos._x = 0;
    // pos._y = 0;

    // Position pos2;
    // pos2._x = 0;
    // pos2._y = 0;

    // Position pos3 = pos + pos2; // 연산자 오버로딩을 안한 상태에서 불가능
    // Position pos4 = pos.operator+(pos2); // 위와 동일한 연산

    // Position pos5 = pos + 1; // 멤버 연산자 함수의 피연산자가 클래스라 가능 
    // // Position pos6 = 1 + pos; // 멤버 연산자 함수의 피연산자가 정수라 불가능

    // Position pos7;
    // pos7 = 1; // 멤버 연산자 함수= 를 사용하여 가능
    // // 전역 연산자 함수=로 만들게 되면 1 = pos7 같은 경우가 생길 수 있기 때문에 막아둠

    // Position pos8;
    // pos8 = (pos7 = 1); // 멤버 연산자 함수=의 반환형이 튀어나오고 그것이 pos8에 대입됨

    // pos = ++pos2;

    // = : Position& 줘
    // ++: Position 줄게
    // pos = pos2++; // 안 됨
    // = : const Position& 줘 : 어차피 참조 객체는 건들지 않을 것이니 Position을 줘도 돼
    // ++: 그럼 Position 줄게~
    // 결론 : const Position& <- Position
    // pos = pos2++; // =연산자함수의 매개변수에 const를 붙였기 때문에 됨
}