#include <iostream>
using namespace std;

// class는 일종의 설계도, class를 정의한다해서 메모리에 적재되는 것이 아님
class Knight
{
public:
    void Move(int y, int x);
    void Attack();

    void Die()
    {
        hp = 0;
        cout << "Die" << endl;
    }

public:
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

void Move(Knight* knight, int y, int x)
{
    knight->posY = y;
    knight->posX = x;
}

int main()
{
    Knight k1; // 클래스를 이용해 실제 객체를 만든다(instantiate), 메모리에 적재됨
    k1.hp = 100;
    k1.attack = 10;
    k1.posY = 0;
    k1.posX = 0;

    Knight k2;
    k2.hp = 100;
    k2.attack = 15;
    k2.posY = 5;
    k2.posX = 5;

    // 여기까지라면 구조체와 크게 차이가 없지만
    // 아래처럼 그 클래스 객체의 함수를 부를 수 있음
    k1.Move(2,2);
    k1.Attack();
    k1.Die();

    // 메모리 상에는 실제 멤버변수의 크기만 잡혀있는 것을 볼 수 있음
    // 그렇기 때문에 k1, k2 각각의 크기는 4바이트 * 4개 변수 = 16바이트

    // 디스어셈블리에서는 아래 두 개의 구조가 그렇게 큰 차이가 없음
    // 그럼 왜 객체지향언어를 사용하는가? 클래스 내부에서 사용할 수 있는 기능이 많음
    k1.Move(1, 1);
    Move(&k1, 1, 1);
}