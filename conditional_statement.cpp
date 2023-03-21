#include <iostream>
using namespace std;

int main() {
    bool isTrue = true;
    if (isTrue)
    {
        cout << "true" << endl;
    }

    isTrue = false;
    if (isTrue)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    int a = 4;
    if (a == 1)
    {
        cout << "a = 1" << endl;
    }
    else if (a == 2)
    {
        cout << "a = 2" << endl;
    }
    else if (a == 3)
    {
        cout << "a = 3" << endl;
    }
    else
    {
        cout << "a is not 1,2,3" << endl;
    }

    switch (a)
    {
    case 1:
        cout << "a = 1" << endl;
        break;
    
    default:
        break;
    }
}
// 출력 결과
// true
// false
// a is not 1,2,3