#include <iostream>
using namespace std;

class Player
{
public:
    Player()
    {
        cout << "Player 생성자 호출" << endl;
    }
    Player(int hp)
    {
        _hp = hp;
    }
    ~Player()
    {
        cout << "Player 소멸자 호출" << endl;
    }
    void Move() { cout << "Player Move 호출" << endl; }
    void Attack() { cout << "Player Attack 호출" << endl; }
    void Die() { cout << "Player Die 호출" << endl; }
public:
    int _hp;
    int _attack;
    int _defence;
};

class Knight : public Player
{
public:
    Knight()
    /*
        선처리 영역
        Knight 생성자 안에서 부모 생성자를 부른 후 자기 생성자 호출됨
        어셈블리를 보면 이 부분에서 부모 생성자가 호출됨
    */
    {
        cout << "Knight 생성자 호출" << endl;
    }

    Knight(int stamina) : Player(100) // 부모의 기본 생성자가 아닌 int 매개변수의 기타 생성자를 호출하게함
    {
        _stamina = stamina;
    }

    ~Knight()
    {
        cout << "Knight 소멸자 호출" << endl;
    }
    /*
        후처리 영역
        Player의 소멸자가 호출됨
    */

    // 재정의
    void Move() { cout << "Knight Move 호출" << endl; }
public:
    int _stamina;
};

class Mage : public Player
{

};

int main() 
{
    Knight k;
    k._hp = 100;
    k._attack = 10;
    k._defence = 1;
    k._stamina = 10;
    k.Move();
    k.Player::Move(); // 잘 사용하지 않지만 재정의된 함수의 부모 함수도 호출할 수 있음
}