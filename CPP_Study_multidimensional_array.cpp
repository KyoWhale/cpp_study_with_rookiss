#include <iostream>
using namespace std;

// 다중 포인터는 잘 안 쓰지만
// 다차원 배열은 꽤 사용함

int main()
{
    int a[10] = { 1, 2, 3 };

    int first[5] = { 4, 2, 3, 4, 1 };
    int second[5] = { 1, 1, 5, 2, 2 };

    // 한 번에 여러 값을 관리할 수 있었지만
    // 배열이 여러개 있을 때는 어떻게 하나
    // 다차원 배열을 사용하면 됨

    int apartment[2][5] = { { 1, 1, 5, 2, 2 }, { 4, 2, 3, 4, 1 }, };
    // aparrment[0~1][0~4]의 범위를 가짐
    for (int floor = 0; floor < 2; floor++)
    {
        for (int room = 0; room < 5; room++)
        {
            int num = apartment[floor][room];
            cout << num << " ";
        }
        cout << endl;
    }

    // 1차원으로도 똑같이 만들 수 있고, 어셈블리 상에서 차이가 없음
    int apartment1D[10] = { 1, 1, 5, 2, 2, 4, 2, 3, 4, 1 };
    for (int floor = 0; floor < 2; floor++)
    {
        for (int room = 0; room < 5; room++)
        {
            int num = apartment1D[(floor * 5) + room];
            cout << num << " ";
        }
        cout << endl;
    }

    // 2차원 배열의 사용 예) 2D 로그라이크 맵
    int map[5][5] = 
    {
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
    };

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            int info = map[y][x];
            cout << info << " ";
        }
        cout << endl;
    }
}