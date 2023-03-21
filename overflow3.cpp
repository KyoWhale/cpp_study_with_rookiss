#include <iostream>
using namespace std;

int main() 
{
    char c = CHAR_MIN;
    char d = CHAR_MIN;
    char e = c + d;
    cout << "  " << bitset<8>(c) << "\n";
    cout << "+ " << bitset<8>(d) << "\n";
    cout << "= " << bitset<8>(e) << "\n";
}
// 출력결과
//   10000000
// + 10000000
// = 00000000