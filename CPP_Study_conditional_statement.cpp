#include <iostream>
using namespace std;

int main() 
{
    int hp = 100;
    int damage = 100;
    hp -= damage;
    bool isDead = (hp <= 0);

    // if( 조건 ), if (조건) 등의 코딩스타일이 있는데 후자를 많이씀
    if (isDead) // 0이 아니면 참으로 간주, 0이면 거짓
        cout << "몬스터를 처치했습니다." << endl;
    
    // !isDead, isDead == false 등의 코딩스타일이 있는데 하나만 있을 땐 전자도 괜찮지만 후자가 가독성에 좋음
    if (isDead == false)
        cout << "몬스터가 반격했습니다." << endl;

    if (isDead)
        cout << "몬스터를 처치했습니다." << endl;
    else
        cout << "몬스터가 반격했습니다." << endl;


    if (isDead)
        cout << "몬스터를 처치했습니다." << endl;
        cout << "몬스터를 처치했습니다." << endl; // 한 줄만 되므로 안 됨

    if (isDead) // 한 줄이면 브라켓이 없어도 되지만 회사 스타일에 따를 것
    {

    }
    else
    {
        // if else문을 중첩을 사용할 수 있음
        // 어지간해서는 중첩을 하지 않고 간략하게 하는 것이 좋음
        // if else if else 문을 사용할 것
        if (hp <= 20)
            cout << "몬스터가 도망가고 있습니다." << endl;
        else
            cout << "몬스터가 반격했습니다." << endl;
    }

    if (isDead)
    {

    }
    else if (hp <= 20)
    {

    }
    else
    {

    }

    const int ROCK = 0;
    const int PAPER = 1;
    const int SCISSORS = 2;

    int input = 40;

    if (input == ROCK)
        cout << "바위를 냈습니다" << endl;
    else if (input == PAPER)
        cout << "보를 냈습니다" << endl;
    else if (input == SCISSORS)
        cout << "가위를 냈습니다" << endl;
    else
        cout << "??" << endl;
    // 조건이 많아질수록 else if를 너무 많이 써야함

    switch (input) // 정수 계열만 넣을 수 있다
    {
    case ROCK:
        cout << "바위를 냈습니다" << endl;
        break; // break를 만나는 지점까지 가야 탈출함
    case PAPER:
        cout << "보를 냈습니다" << endl;
        break;
    case SCISSORS:
        cout << "가위를 냈습니다" << endl;
        break;
    default:
        cout << "??" << endl;
        break;
    }
}