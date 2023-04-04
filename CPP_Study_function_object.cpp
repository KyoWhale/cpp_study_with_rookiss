#include <iostream>
using namespace std;

void HelloWorld()
{
    cout << "Hello World" << endl;
}

void HelloWorld(int a)
{
    cout << "Hello World : " << a << endl;
}

class Knight
{
public:
    void AddHp(int addHp)
    {
        _hp += addHp;
    }
public:
    int _hp = 100;
};

class Functor
{
public:
    void operator()()
    {
        cout << "Functor Test" << endl;
        cout << _value << endl;
    }
    // 여러 무궁무진한 오버로딩 함수를 추가할 수 있음
    bool operator()(int num)
    {
        cout << "Functor Test" << endl;
        cout << num << ", " << _value << endl;
    }
private:
    int _value = 0;
};

class MoveTask
{
public:
    void operator()()
    {
        cout << "해당 좌표로 플레이어 이동" << endl;   
    }
public:
    int _playerId = 100;
    int _posX = 5;
    int _posY = 0;
};

int main()
{
    void (*pfunc)(void);
    pfunc = &HelloWorld;

    (*pfunc)();

    // 함수 포인터 단점
    // 1. 시그니처가 동일한 것만 가능함
    // 2. 상태를 가질 수 없음

    // 함수 객체
    // 함수처럼 동작하는 객체
    // () 연산자 오버로딩 해야함
    HelloWorld();

    Functor functor;
    functor();
    bool ret = functor(3);

    // MMO에서 함수 객체를 삿용하는 예시
    // 클라 <-> 서버
    // 서버 : 클라가 보내준 네트워크 패킷을 받아서 처리
    // ex) 클라 : 나 (5, 0) 좌표로 이동시켜줘
    // 펑터 함수를 만들고, 실행하는 시점 두 가지를 분리할 수 있음
    MoveTask task;
    task._playerId = 100;
    task._posX = 5;
    task._posY = 0;

    // 나중에 여유될 때 일감을 실행;
    task();
    // 이게 커맨드 패턴

    return 0;
}