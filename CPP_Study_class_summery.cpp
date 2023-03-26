#include <iostream>
using namespace std;

// struct VS class
// 

// static 변수, static 함수
// static : 정적, 고정된

class Marine
{
public:
    // 체력은 수시로 변할 수 있으니 각 객체가 가져야함
    int _hp; 
    // 모든 마린이 공격 수치가 같기에 static
    // 클래스만의 전역변수와 같은 느낌
    static int s_attack; // 설계도 상으로만 존재

    void TakeDamage(int damage)
    {
        _hp -= damage;
    }

    static void Upgrade()
    {
        s_attack = 10;
        // _hp = 100; // 
    }
};

// 초기화하면 .data
// 초기화 안 하면 .bss
int Marine::s_attack = 5;

int GenerateId()
{
    static int s_id = 1; // 지역 정적 변수
    return s_id++;
}

int main() 
{
    Marine m1;
    m1._hp = 50;
    // m1의 피는 50
    // m1의 공격력 10

    Marine m2;
    m2._hp = 50;
    m2.TakeDamage(10);
    // m2의 피가 10 깎여 40
    // m2의 공격력도 10

    Marine::Upgrade();
    // m1, m2의 모두의 공격력이 증가됨
}