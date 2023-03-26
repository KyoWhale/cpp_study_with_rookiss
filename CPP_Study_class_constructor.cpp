#include <iostream>
using namespace std;

// 암시적 생성자 : 컴파일러가 만들어주는 아무런 내용이 없는 기본 생성자
// 생성자를 하나라도 만들면 암시적 생성자는 만들어지지 않음
// 

class Knight
{
public:
    Knight()
    {
        cout << "Knight 기본 생성자 호출" << endl;
    }
    Knight(int hp)
    {
        cout << "Kinght(int) 생성자 호출" << endl;
    }
    Knight(const Knight& knight) // 복사 생성자, 똑같은 데이터를 지닌 객체가 생성되길 기대
    {
        hp = knight.hp;
        attack = knight.attack;
        posX = knight.posX;
        posY = knight.posY;
    }
    ~Knight()
    {
        cout << "Knight 소멸자 호출" << endl;
    }

    void Move(int y, int x); // 함수는 일반적으로 대문자로 쓰는 것이 규칙
    void Attack();
    void Die()
    {
        hp = 0; // this->hp = 0; 와 동일
        cout << "Die" << endl;
    }

public:
    // 멤버 변수인 것을 알려주는 이름 특징으로 접두사로 m_, mCamel, _ 등이 있음
    // ex) m_hp, mHp, _hp;
    int hp;
    int attack;
    int posY;
    int posX;
};

void Knight::Move(int y, int x)
{
    posY = y;
    posX = x;
    cout << "Move" << endl;
}

void Knight::Attack()
{
    cout << "Attack" << endl;
}

int main()
{
    Knight k1; // 클래스를 이용해 실제 객체를 만든다(instantiate), 메모리에 적재됨
    k1.hp = 100;
    k1.attack = 10;
    k1.posY = 0;
    k1.posX = 0;

    k1.Move(2,2);
    k1.Attack();
    k1.Die();

    Knight k2(k1);
}