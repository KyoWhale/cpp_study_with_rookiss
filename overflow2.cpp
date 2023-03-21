#include <iostream>
using namespace std;

int main() 
{
    cout << "char, 8bit\n";
    char c = CHAR_MIN;
    cout << dec << "Before - 1 : " << int(c) << "\t\t" << bitset<8>(c) << "\n";
    c = c - 1;
    cout << dec << "After  - 1 : " << int(c) << "\t\t" << bitset<8>(c) << "\n\n";
    
    c = CHAR_MAX;
    cout << dec << "Before + 1 : " << int(c) << "\t\t" << bitset<8>(c) << "\n";
    c = c + 1;
    cout << dec << "After  + 1 : " << int(c) << "\t\t" << bitset<8>(c) << "\n\n";

    cout << "short, 16bit\n";
    short s = SHRT_MIN;
    cout << dec << "Before - 1 : " << s << "\t\t" << bitset<16>(s) << "\n";
    s = s - 1;
    cout << dec << "After  - 1 : " << s << "\t\t" << bitset<16>(s) << "\n\n";

    s = SHRT_MAX;
    cout << dec << "Before + 1 : " << s << "\t\t" << bitset<16>(s) << "\n";
    s = s + 1;
    cout << dec << "After  + 1 : " << s << "\t\t" << bitset<16>(s) << "\n\n";

    cout << "int, 32bit\n";
    int i = INT_MIN;
    cout << dec << "Before - 1 : " << i << "\t" << bitset<32>(i) << "\n";
    i = i - 1;
    cout << dec << "After  - 1 : " << i << "\t\t" << bitset<32>(i) << "\n\n";

    i = INT_MAX;
    cout << dec << "Before + 1 : " << i << "\t\t" << bitset<32>(i) << "\n";
    i = i + 1;
    cout << dec << "After  + 1 : " << i << "\t" << bitset<32>(i) << "\n\n";
}
/* 출력결과
char, 8bit
Before - 1 : -128		10000000
After  - 1 : 127		01111111

Before + 1 : 127		01111111
After  + 1 : -128		10000000

short, 16bit
Before - 1 : -32768		1000000000000000
After  - 1 : 32767		0111111111111111

Before + 1 : 32767		0111111111111111
After  + 1 : -32768		1000000000000000

int, 32bit
Before - 1 : -2147483648	10000000000000000000000000000000
After  - 1 : 2147483647		01111111111111111111111111111111
*/