#include <iostream>
using namespace std;

// 왜 초기화할까
// - 버그 예방에 중요
// - 포인터 등 주소값이 연루되어 있을 경우

// 초기화 방법
// - 생성자 내에서
// - 초기화 리스트
// - C++11 문법

// 초기화 리스트
// - 상속 관계에서 원하는 부모 생성자 호출할 때 필요
// - 생성자 내에서 초기화 vs 초기화 리스트
// - 일반 변수는 큰 차이 없음
// - 멤버 타입이 클래스일 때 차이가 남

class Inventory
{
public:
    Inventory() { cout << "Inventory" << endl; }
    Inventory(int size) { cout << "Inventory(int)" << endl; _size = size;}
    ~Inventory() { cout << "~Inventory" << endl; }
public:
    int _size = 10;
};

class Player
{
public:
    Player() { }
    Player(int id) { }
};

// Is-A : Knight Is A Player? Yes -> 상속 관계
// Has-A : Knight Has A Inventory? Yes -> 포함 관계

class Knight : public Player
{
public: 
    // Knight() : Player(1), _hp(100)
    // // 인벤토리의 기본 생성자가 호출될 것임
    // {
    //     _hp = 100;
    //     _inventory = Inventory(20); // 인벤토리가 한 번 더 생성
    // }
    Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100) // 초기화 리스트에 인벤토리, hp&, const hp를 추가
    // 인벤토리의 기타 생성자가 호출될 것임
    {
        _hp = 100;
    }
public:
    int _hp;
    Inventory _inventory;

    int& _hpRef;
    const int _hpConst;
};

int main() 
{
    
}