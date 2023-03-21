#include <iostream>
using namespace std;

int main() 
{
    int value = rand(); // 게속 같은 값이 출력댐
    // 컴퓨터에는 랜덤이란 값이 없음
    // 난수생성기
    srand(time(0)); //seed rand (시드값)
    rand(); // 0~32767까지 값을 반환
    rand() % 3; // 0~2까지의 값이 나옴
    1 + rand() % 3; // 1~3까지의 값이 나옴

    const int SCISSORS = 1;
    const int ROCK = 2;
    const int PAPER = 3;

    int wins = 0;
    int total = 0;

    while (true)
    {
        cout << "가위(1) 바위(2) 보(3) : " << endl;
        cout << "> ";

        if (total == 0)
        {
            cout << "현재 승률 : 없음" << endl;
        }
        else
        {
            int winPoercentage = float(wins) / total * 100; // 정수 / 정수 = 정수라서 하나를 float로 바꿔주어 해야함

            cout << "" << endl;
        }

        // 컴퓨터 값
        int computerValue = 1 + rand() % 3;

        // 사용자 값
        int input;
        cin >> input;

        if (input == SCISSORS)
        {
            switch (computerValue)
            {
            case SCISSORS:
                cout << "비김" << endl;
                break;
            case ROCK:
                cout << "짐" << endl;
                break;
            case PAPER:
                cout << "이김" << endl;
                wins++;
                break;
            }
        }
        else if (input == ROCK)
        {
            switch (computerValue)
            {
            case SCISSORS:
                cout << "이김" << endl;
                wins++;
                break;
            case ROCK:
                cout << "비김" << endl;
                break;
            case PAPER:
                cout << "짐" << endl;
                break;
            }
        }
        else if (input == PAPER)
        {
            switch (computerValue)
            {
            case SCISSORS:
                cout << "짐" << endl;
                break;
            case ROCK:
                cout << "이김" << endl;
                wins++;
                break;
            case PAPER:
                cout << "비김" << endl;
                break;
            }
        }
        else
        {
            break;
        }

        total++;
    }
}