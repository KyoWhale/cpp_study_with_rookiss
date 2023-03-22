#include <iostream>
using namespace std;

struct Player
{
    int hp;
    int damage;
};

// Player 구조체가 1000바이트짜리 대형 구조체라면
// 값 전달 : 1000바이트가 복사되는 구조
// 주소 전달 : Player*는 8바이트
// 참조 전달 : Player&는 8바이트

// 참조 전달
// 1) 값 전달처럼 편리하게 사용할 수 있음
// 2) 주소 전달처럼 주소값을 이용해 원본을 건들 수 있음
// 3) 포인터는 주소를 넘기니 원본이라는 것을 확실히 알 수 있는데, 참조는 모를 수 있음

// 참조 vs 주소
// 0) team by team
// 1) 구글 오픈소스 = 포인터
// 2) 언리얼 엔진 참조도 사용
// 3) 루키스
//  - 없는 경우도 고려해야한다면 포인터
//  - 바뀌지 않고 읽는 용도 const ref&
//  - 다른 사람이 포인터로 사용하고 있었으면 포인터로 사용(굳이 참조와 혼용해서 사용하진 않음)

//  - #define OUT을 하여 매개변수 앞에 써줌
//  - 결국 OUT은 아무것도 하지 않지만 힌트를 주기 때문에 좋음

// 포인터로 사용하던걸 참조로 넘겨주려면?
// 참조로 사용하던걸 포인터로 넘겨주려면?

// void CreatePlayer(Player& player);
void CreatePlayer(Player player);
void CreatePlayer(const Player* player);
void CreatePlayer(Player* const player);
void CreatePlayer(const Player* const player);

int main()
{
    Player player1;
    CreatePlayer(player1);

    Player player2;
    CreatePlayer(&player2);
}

// 1) 값 전달 방식
void CreatePlayer(Player player)
{
    

}

// 값 변경 불가
void CreatePlayer(const Player* player)
{
    Player temp;
    player = &temp; // 가능

    cout << player->hp; // 읽는 것은 가능
    // (*player).hp = 140; // 쓰는 것은 불가
    // player->damage = 40; // 쓰는 것은 불가
}

// 주소 변경 불가
void CreatePlayer(Player* const player)
{
    Player temp;
    // player = &temp; // 불가

    (*player).hp = 140; // 읽고 쓰기 가능
    player->damage = 40; // 읽고 쓰기 가능
}

// 위의 두 const를 합쳐서도 사용할 수 있음
void CreatePlayer(const Player* const player)
{
    Player temp;
    // player = &temp; // 불가

    cout << player->hp; // 읽는 것은 가능
    // player->hp = 140; // 불가
    // player->damage = 40; // 불가
}

// void CreatePlayer(Player& player)
// {
    
// }