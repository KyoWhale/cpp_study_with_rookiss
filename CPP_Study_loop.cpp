#include <iostream>
using namespace std;

int main() 
{
    // if else는 유용하지만 특정 조건까지 계속 반복해야하는 상황은 처리 못함
    // ex) 게임을 끌때까지 계속 게임을 실행하라
    // ex) 목적지에 도달할때까지 계속 이동하라

    // while (조건식)
    // {
    //     명령문;
    // }

    int count = 0;

    while (count < 5)
    {
        cout << "Hello World" << endl;
        count++; // 없으면 무한루프가 걸림
        // 반복문을 한번 돌아도 count의 값이 변하지 않았기 때문에
    }

    // do while 문은 잘 사용하진 않지만 읽을 줄은 알아야함
    // 무조건 한 번은 실행할 수 있음
    count = 0;
    do
    {
        cout << "Hello World" << endl;
        count++; // 없으면 무한루프가 걸림
    } while (count < 5);

    // 1.초기화
    // while (2.조건)
    // { 3.증감 }

    // for (초기식; 조건식; 제어식)
    // { 문장 }

    // 순서 처음
    // 1. 초기식
    // 2. 조건식 // 조건에 맞지 않으면 빠져나옴
    // 3. 문장
    // 4. 제어식
    // 이후 반복은
    // 2->3->4
    for (int count = 0; count < 5; count++)
    {
        cout << "Hello World" << endl;
    }

    // 정해진 반복 횟수가 있다면 for, 식이 빠진 것을 보기 편함
    // 딱히 뭘 쓰던 상관 없음

    // continue, break;
    // break = 반복문을 다 돌지 않아도 빠져나올 수 있는 키워드
    // - 하나의 반복문만 빠져나감
    // continue = 현재의 남아있는 문장을 버리고 다음 반복문장을 실행하러 이동

    int round = 1;
    int hp = 100;
    int damage = 10;

    while (true)
    {
        hp -= damage;
        if (hp < 0)
            hp = 0; // 음수 체력을 0으로 보정

        cout << "Round " << round << " 믄스터 체력 " << hp << endl;

        if (hp == 0)
        {
            cout << "몬스터 처치" <<endl;
            break;
        }

        if (round == 5)
        {
            cout << "제한 라운드 종료" << endl;
            break;
        }

        round++;
    }

    // 1~10 사이의 홀수만 출력
    for (int count = 1; count <= 10; count++)
    {
        bool isEven = (count % 2) == 0;
        // 방식1
        if (isEven)
            continue;
        cout << count <<endl;
        // 방식2
        // if (isEven == false)
        //     cout << count << endl;
    }
}