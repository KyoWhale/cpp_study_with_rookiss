#include <iostream>
using namespace std;

// 1) static_cast
// 2) dynamic_cast
// 3) const_cast
// 4) reinterpret_cast

class Dog
{

};

class Player
{
public:
    virtual ~Player() {}
};

class Knight : public Player
{

};

class Archer : public Player
{

};

void PrintName(char* str)
{
    cout << str << endl;
}

int main()
{
    // static_cast : 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용
    // 1) int <-> float
    // 2) Player* -> Knight* (다운 캐스팅) << 단, 안정성 보장 못함
    {
        int hp = 100;
        int maxHp = 200;
        float ratio = (float)hp / maxHp;
        float ratio2 = static_cast<float>(hp) / maxHp;

        Player* p = new Knight();
        Knight* k = (Knight*)p;

        Knight* k2 = new Knight();
        Player* p2 = k2;
        
        Knight* k3 = static_cast<Knight*>(p);
    }

    // dynamic cast : 상속 관계에서의 안전 형변환
    // RTTI (Runtime Type Information)
    // 다형성을 활용하는 방식
    // - virtual이 하나라도 있어야함, 객체의 메모리에 가상 함수 테이블 주소가 기입됨
    // - 만약 잘못된 타입으로 캐스팅을 했으면 nullptr 반환
    // - static_cast보다는 느리지만, 원본이 모를 때 사용
    {
        Player* p = new Knight();
        Knight* k1 = dynamic_cast<Knight*>(p);
    }

    // const_cast : const를 붙이거나 떼거나
    PrintName((char*)"Rookiss");
    PrintName(const_cast<char*>("Rookiss"));

    // reinterpret_cast
    // 're-interpret' : 다시 - 간주하다 / 생각하다
    // 가장 위험하고 강력한 형태의 캐스팅
    // - 포인터랑 전혀 관계 없는 다른 타입 변환 등
    Knight* k2 = new Knight();
    long address = (long)k2;
    long address2 = reinterpret_cast<long>(k2);

    Dog* dog = reinterpret_cast<Dog*>(k2);

    void* p = malloc(1000);
    Dog* dog2 = reinterpret_cast<Dog*>(p);

    // 결론
    // c 스타일의 타입 변환은 잊어버릴 것

    return 0;
}