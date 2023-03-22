#include <iostream>
using namespace std;

struct A
{
    int x;
};

int main()
{
    A st1 = { 3 };
    A* st2 = &st1;

    cout << (*st2).x << endl;
    cout << st2->x << endl;

    (*st2).x = 7;
    cout << st1.x << endl;
    st2->x = 10;
    cout << st1.x << endl;
}
// 출력 결과
// 3
// 3
// 7
// 10