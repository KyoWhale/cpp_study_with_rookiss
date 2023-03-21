#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    do
    {
        cout << a << endl;
        a++;
    } while (a < 5);

    do
    {

        a++;
    } while (a < 5);

    cout << a << endl;
}
// 출력 결과
// 0
// 1
// 2
// 3
// 4
// 5
// 6