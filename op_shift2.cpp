#include <iostream>
using namespace std;

int main() {
    int a = 2;
    int b = 3;

    a += b;
    cout << "+= : " << a << ", " << b << endl;
    a -= b;
    cout << "-= : " << a << ", " << b << endl;
    a *= b;
    cout << "*= : " << a << ", " << b << endl;
    a /= b;
    cout << "/= : " << a << ", " << b << endl;
    a %= b;
    cout << "%= : " << a << ", " << b << endl;
    a &= b;
    cout << "&= : " << a << ", " << b << endl;
    a |= b;
    cout << "|= : " << a << ", " << b << endl;
    a ^= b;
    cout << "^= : " << a << ", " << b << endl;
    a <<= b;
    cout << "<<=: " << a << ", " << b << endl;
    a >>= b;
    cout << ">>=: " << a << ", " << b << endl;
}
// 출력결과
// += : 5, 3
// -= : 2, 3
// *= : 6, 3
// /= : 2, 3
// %= : 2, 3
// &= : 2, 3
// |= : 3, 3
// ^= : 0, 3
// <<=: 0, 3
// >>=: 0, 3