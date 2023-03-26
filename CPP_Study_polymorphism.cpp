#include <iostream>
using namespace std;

// 다형성 : 겉은 같은데 기능이 다르게 동작
// 오버로딩 : 함수 중복 정의 = 함수 이름 재사용
// 오버라이딩 : 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의

// 바인딩
// 정적 바인딩 : 컴파일 시점에 결정
// 동적 바인딩 : 실행 시점에 결정

// 일반 함수는 정적 바인딩 사용
// 동적 바인딩을 원한다면 -> 가상 함수 사용(virtual function)

// 실제 객체가 어떤 타입인지 어떻게 알아서 맞는 클래스의 가상 함수를 호출하는지?
// - 가상 함수 테이블 (vftable)

// 순수 가상함수
// 몸체가 없는 가상함수, 자식 클래스에서 구현해야함
// virtual 반환형 함수이름(매개변수) = 0;
// 추상 클래스 : 순수 가상 함수가 1개 이상 포함되면 추상 클래스

class Player
{
public:
    void Move() { cout << "Move Player!" << endl; }
    // void Move(int a) { cout << "Move(int) Player!" << endl; } // 오버로딩
    virtual void VMove() { cout << "VMove Player!" << endl; }
    // virtual void VAttack() = 0; // 순수 가상 함수 정의
public:
    int _hp;
};

class Knight : public Player
{
public:
    void Move() { cout << "Move Knight!" << endl; }
    // 가상 함수는 재정의 하더라더 가상 함수
    virtual void VMove() { cout << "VMove Knight!" << endl; }
public:
    int _stamina;
};

class Mage : public Player
{
public:
    void Move() { cout << "Move Mage!" << endl; }
public:
    int _mp;
};

void MovePlayer(Player* player)
{
    player->Move();
}

void MoveKnight(Knight* knight)
{
    knight->Move();
}

void VMove(Player* player)
{
    player->VMove();
}

int main() 
{
    Player p;
    MovePlayer(&p); // 플레이어는 플레이어다? YES
    // MoveKnight(&p); // 플레이어는 기사다? NO

    Knight k;
    MoveKnight(&k); // 기사는 기사? YES
    MovePlayer(&k); // 기사는 플레이어다? YES

    // 최상위 클래스를 통해 하위 여러 가지쳐진 클래스들을 같은 함수로 관리할 수 있음
    // 재정의한 이유는 각 자식 클래스에서 원하는 구현이 있는데, 부모 클래스의 함수를 부르면 의미가 없어짐
    // 그래서 동적 바인딩을 사용
    VMove(&k); // 부모 클래스의 VMove가 아닌 자식 클래스의 VMove 호출
}