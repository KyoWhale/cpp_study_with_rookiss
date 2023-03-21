#include <iostream>
using namespace std;

const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

enum RSP
{
    ENUM_ROCK,
    ENUM_SCISSORS,
    ENUM_PAPER
};

int main() 
{
    // const int의 주소를 사용하지 않았으면 메모리에 올리지 않아도 되어서 컴파일러가 알아서 수 자체로 치환하여 메모리의 공간 활용을 아낌
    // enum은 수 자체로 바뀌기 때문에 메모리에 올라갈 일이 없어 메모리에서 효율적

    // #define 으로 상수도 만들 수 있고 수식을 포함한 어떠한 문장 자체를 만들 수 있다.
    // #define 으로 만든 상수 수식은 우선순위가 바뀔 수도 있기 때문에 #define 상수문은 가급적 자제하고 enum, const를 사용할 것

    srand(time(0)); // 현재 시간 값을 시드로 하여 랜덤 값이 나오도록 함
    // 랜덤값이 좀 더 랜덤이 되게끔 만들어주는 코드이므로 이해할 필요는 없음

    int userInput; // 유저의 입력을 받아 저장할 변수 userInput
    int computerInput; // 랜덤 값 저장하여 유저의 값이랑 비교할 변수 computerInput

    do 
    {
        cin >> userInput;
        computerInput = rand() % 3 + 1; // rand()로 나오는 값은 0 ~ 32767
        // 나온 랜덤값을 나머지 연산자를 통해 0, 1, 2로 제한하고 + 1을 해주면 1, 2, 3 중 하나가 출력됨

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
    } while (0 < userInput && userInput < 4); // 유저의 인풋이 1~3 사이일 때만 반복
}