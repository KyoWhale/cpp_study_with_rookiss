#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            cout << "i : 0" << endl;
        }
        else if (i == 1)
        {
            cout << "i : " << i << endl;
        }
        else if (i == 2)
        {
            cout << "i : 2" << endl;
            continue;
            cout << "after continue" << endl;
        }
        else
        {
            break;
        }
        cout << "Hello World" << endl;
    }
}
// 출력 결과
// i : 0
// Hello World
// i : 1
// Hello World
// i : 2