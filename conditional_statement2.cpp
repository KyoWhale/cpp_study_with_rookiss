#include <iostream>
using namespace std;

int main() {
    int a = 4;

    switch (a)
    {
    case 1:
        cout << "a = 1" << endl;
        break;
    case 2:
        cout << "a = 2" << endl;
        break;
    case 3:
        cout << "a = 3" << endl;
        break;
    default:
        cout << "a is not one of 1,2,3" << endl;
        break;
    }

    a = 1;

    switch (a)
    {
    case 0:
        break;
    case 1:
    case 2:
        cout << "a = 1 or a = 2" << endl;
        break;
    case 3:
        cout << "a = 3" << endl;
        break;
    default:
        cout << "a is not one of 1,2,3" << endl;
        break;
    }
}
// 출력 결과
// a is not one of 1,2,3
// a = 1 or a = 2