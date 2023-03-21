#include <iostream>
using namespace std;

int main() 
{

    // cout << "hello world" << endl;

    // 별찍기
    // 유저들이 어떤 정수를 입력하면
    // N*N개의 별을 찍었으면 좋겠어요!

    int input = 5;

    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // 별찍기
    // 유저들이 어떤 정수를 입력하면
    // 순차적으로 줄마다 증가하게 해주세요!

    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // 별찍기
    // 유저들이 어떤 정수를 입력하면
    // N개부터 시작해서 줄마다 1개씩 줄어드는 형태로!

    for (int i = input - 1; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // 구구단
    for (int i = 2; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << i << " X " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
}