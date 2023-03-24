#include <iostream>
using namespace std;

// 로또 번호 생성기
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Sort(int numbers[], int count)
{
    for (int i = 0; i < count; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < count; j++)
        {
            if (numbers[minIndex] > numbers[j])
            {
                minIndex = j;
            }
        }

        Swap(numbers[minIndex], numbers[i]);
    }
}

void ChooseLotto(int numbers[])
{
    srand((unsigned)time(0));

    int lottos[6] = { };

    int currentLottoCount = 0;
    while (currentLottoCount <= 5)
    {
        int generatedNum = rand() % 45 + 1;
        bool isDuplicated = false;

        for (int i = 0; i < currentLottoCount; i++)
        {
            if (lottos[i] == generatedNum)
            {
                isDuplicated = true;
                break;
            }
        }

        if (isDuplicated)
        {
            continue;
        }

        lottos[currentLottoCount++] = generatedNum;
    }

    Sort(lottos, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << lottos[i] << " ";
        numbers[i] = lottos[i];
    }
    cout << endl;
}

int main()
{
    // 1) 스왑 함수 만들기
    int a = 1;
    int b = 2;
    Swap(a, b);
    cout << a << " " << b << endl;

    // 2) 정렬 함수 만들기 ( 작은 숫자가 먼저 오도록 정렬 )
    int numbers[6] = { 1, 42, 3, 15, 5, 6};
    Sort(numbers, sizeof(numbers)/ sizeof(int));
    for (int i = 0; i < sizeof(numbers)/ sizeof(int); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // 3) 로또 번호 생성
    ChooseLotto(numbers);
    
    return 0;
}