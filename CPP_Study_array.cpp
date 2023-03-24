#include <iostream>
using namespace std;

struct StatInfo
{
    int hp = 0xAAAAAAAA;
    int attack = 0xBBBBBBBB;
    int defence = 0xCCCCCCCC;
};

int main()
{
    // 일일이 선언하기 힘듬
    StatInfo monster;
    StatInfo monster2;
    StatInfo monster3;

    // 자료형 배열이름[갯수];
    StatInfo monsters[10];

    // const
    const int monsterCount = 10;
    StatInfo monsters2[monsterCount];

    // 배열의 이름은 곧 배열의 시작 주소
    // 정확히는 시작 위치를 가르키는 자료형*
    auto WhoAmI = monsters;

    // 인덱스
    StatInfo* monsterPtr = monsters;
    monsterPtr->hp = 100;
    monsterPtr->attack = 10;
    monsterPtr->defence = 1;
    
    monsterPtr += 1;
    monsterPtr->hp = 200;
    monsterPtr->attack = 20;
    monsterPtr->defence = 2;
    
    // 참조로 건들기
    StatInfo& monsterRef = *(monsters + 2);
    monsterRef.hp = 200;
    monsterRef.attack = 20;
    monsterRef.defence = 2;

    // 일반 변수로 만들었을 때는 참조랑 다르다
    // temp 자체의 새 변수가 생겨서 temp가 바뀌는 것
    StatInfo temp = *(monsters + 2);
    temp.hp = 200;
    temp.attack = 20;
    temp.defence = 2;

    // 포인터를 활용한 배열 자동화
    for (int i = 0; i < monsterCount; i++)
    {
        StatInfo& monster = *(monsters + i);
        monster.hp = 100 * (i + 1);
        monster.attack = 10 * (i + 1);
        monster.defence = 1 * (i + 1);
    }

    // *(포인터+i) 는 너무 불편하고 가독성이 떨어진다
    // 인덱스에 접근하여 데이터를 사용할 수 있음
    // *(monsters + i) = monsters[i]

    monsters[0].hp = 110;
    monsters[0].attack = 11;
    monsters[0].defence = 1;

    int hp = monsters[0].hp;

    for (int i = 0; i < monsterCount; i++)
    {
        monsters[i].hp = 100 * (i + 1);
        monsters[i].attack = 10 * (i + 1);
        monsters[i].defence = (i + 1);
    }

    // 배열 초기화 문법 몇 가지
    int numbers[5] = {}; // 모두 0으로 초기화
    int numbers1[10] = { 1,2,3,4,5 }; // 나머지 값들은 0으로 초기화
    int numbers2[] = { 1, 2, 3, 41, 11, 456, 756 }; // 데이터 갯수만큼의 크기에 해당하는 배열로 만듬

    char helloStr[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << helloStr << endl;

    return 0;
}