#include <iostream>
using namespace std;

enum RSP
{
    ROCK,
    SCISSORS,
    PAPER
};

int main() 
{
    srand(time(0)); // 현재 시간 값을 시드로 하여 랜덤 값이 나오도록 함
    // 랜덤값이 좀 더 랜덤이 되게끔 만들어주는 코드이므로 이해할 필요는 없음

    RSP userInput; // 유저의 입력을 받아 저장할 변수 userInput
    RSP computerInput; // 랜덤 값 저장하여 유저의 값이랑 비교할 변수 computerInput

    do 
    {
        int input;
        cin >> input; // 정수값을 입력받아
        userInput = (RSP)input; // 유저인풋으로 형변환하여 넣어줌
        computerInput = (RSP)(rand() % 3); // rand()로 나오는 값은 0 ~ 32767
        // 나온 랜덤값을 나머지 연산자를 통해 0, 1, 2로 제한함

        if (userInput == ROCK) // 유저의 인풋이 바위이면서
        {
            if (computerInput == ROCK) // 컴퓨터의 랜덤값이 바위면
            {
                cout << "draw" << endl; // 비겼다를 출력
            }
            else if (computerInput == SCISSORS) // 컴퓨터의 랜덤값이 가위면
            {
                cout << "win" << endl;  // 이겼다를 출력
            }
            else if (computerInput == PAPER) // 컴퓨터의 랜덤값이 보면
            {
                cout << "lose" << endl; // 졌다를 출력
            }
            // 마지막은 else if 가 아닌 else로 하여도 되지만, 혹시 모를 컴퓨터의 다른 값이나 가독성 면에서 마지막 조건이 PAPER 라는 것을 확실히 보여주기 위해 else if 사용
        }
        else if (userInput == SCISSORS) // 이하 위와 동일한 논리로 흐름
        {
            if (computerInput == ROCK)
            {
                cout << "lose" << endl;
            }
            else if (computerInput == SCISSORS)
            {
                cout << "draw" << endl;
            }
            else if (computerInput == PAPER)
            {
                cout << "win" << endl;
            }
        }
        else if (userInput == PAPER)
        {
            if (computerInput == ROCK)
            {
                cout << "win" << endl;
            }
            else if (computerInput == SCISSORS)
            {
                cout << "lose" << endl;
            }
            else if (computerInput == PAPER)
            {
                cout << "draw" << endl;
            }
        }
    } while (0 <= (int)userInput && (int)userInput < 3); // 유저의 인풋이 0~2 사이일 때만 반복
}