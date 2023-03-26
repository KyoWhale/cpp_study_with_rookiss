#include <iostream>
using namespace std;

class Knight
{
public:
    Knight()
    {
        cout << "Knight 기본 생성자 호출" << endl;
    }
    // explicit 은 암시적 형변환을 막아주기 때문에 명시적으로만 사용하게 만듬
    explicit Knight(int hp) // 인자 1개만을 받는 기타 생성자를 타입 변환 생성자라고 부르기도 함
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
    Knight k1;
    Knight k2(k1); // 복사 생성자
    Knight k3 = k1; // 복사 생성자
    Knight k4; // 복사 생성자 아님
    k4 = k1; // 복사

    Knight k5;
    k5 = (Knight)1; // ?? 타입 변환 생성자인 Knight(int hp)가 호출됨
    // explicit이 붙은 기타 생성자로 인해 암시적 형변환이 안 됨
}