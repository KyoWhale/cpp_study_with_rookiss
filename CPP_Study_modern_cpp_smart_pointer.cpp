#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 스마트 포인터
class Knight
{
public:
    Knight() { cout << "생성자" << endl; }
    ~Knight() { cout << "소멸자" << endl; }
    void Attack()
    {
        if (_target)
        {
            _target->_hp -= _damage;
        }
    }
public:
    int _hp = 100;
    int _damage = 10;
    Knight* _target = nullptr;
};

int main()
{
    Knight* k1 = new Knight();
    Knight* k2 = new Knight();

    k1->_target = k2;

    delete k2; // k2가 로그아웃했다고 가정

    k1->Attack();

    // 스마트 포인터
    // shared_ptr, weak_ptr, unique_ptr

    // shared_ptr
    // - 순환 문제가 있음

    return 0;
}