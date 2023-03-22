#include <iostream>
using namespace std;

// 1) 주소 연산자
// 2) 산술 연산자
// 3) 간접 연산자
// 4) 간접 멤버 연산자

struct Player
{
    int hp;
    int damage;
};

int main()
{
    int number = 1;

    // 1) 주소 연산자 &
    // 해당 변수의 주소를 반환함
    // 더 정확히는 해당 변수 타입에 따라서 type*로 변환
    int* pointer = &number;

    // int*
    // - * : 포인터 타입이고 (8바이트) 주소를 담는 변수
    // - int : 주소를 따라가면 int(4바이트 정수형 변수)가 있다고 가정해라
    // 2) 산술 연산자 (+, -)
    // 포인터에서 +, -등 산술 연산으로 1을 더하거나 빼면
    // 한번에 type의 크기만큼 이동하라
    // 즉 1을 더하면 = 바구니 1개 이동시켜라
    // 3을 더하면 = 바구니 3개 이동시켜라
    // int64_t* 로 2를 더하면 8바이트 * 2 = 16 이동
    // 앞 뒤로 주소를 이동시키는 것이 위험하다했는데 왜 배우는가
    // 배열을 배우고나서 사용할 떄 좋음
    pointer = pointer + 1;
    pointer++;
    ++pointer;
    pointer += 1;

    // 3) 간접 연산자
    Player player;
    player.hp = 100;
    player.damage = 10;

    Player* playerPtr = &player;
    // *playerPtr.hp = 200 // 오류
    (*playerPtr).hp = 200;
    (*playerPtr).damage = 20;

    // 4) 간접 멤버 연산자
    playerPtr->hp = 200;
    playerPtr->damage = 200;
}