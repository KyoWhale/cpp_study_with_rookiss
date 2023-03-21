#include <iostream>
using namespace std;

int main() 
{
    cout << hex; // cout으로 출력되는 값들을 16진수로 나타내겠다.

    int a = 0x01020304;

    // char 옆에 *는 포인터 자료형을 나타내고 나중에 배운다.
    char* a1 = (char*)&a;       // a의 주소 중 첫번째 바이트의 주소를 char 단위로 가져옴
    char* a2 = (char*)&a + 1;   // a의 주소 중 첫번째 바이트의 주소를 char 단위로 가져오고 char 단위만큼 하나 건너뜀
    char* a3 = (char*)&a + 2;   // a의 주소 중 첫번째 바이트의 주소를 char 단위로 가져오고 char 단위만큼 둘 건너뜀
    char* a4 = (char*)&a + 3;   // a의 주소 중 첫번째 바이트의 주소를 char 단위로 가져오고 char 단위만큼 셋 건너뜀

    cout << *a1 << *a2 << *a3 << *a4 << endl; // 그 주소 안에 있는 값들을 낮은 주소에 있는 값부터 하나씩 출력한다.
}
// 출력결과
// x04x03x02x01

// int a = 0x12345678; // 16진수로 8자리인데, 16진수 한 자리는 2진수로는 4자리다 = 0001 0010 0011 0100 0101 0110 0111 1000

//     char c1 = (a & 0x000000ff) >> 0;
//     char c2 = (a & 0x0000ff00) >> 8;
//     char c3 = (a & 0x00ff0000) >> 16;
//     char c4 = (a & 0xff000000) >> 24;

//     cout << int(c1) << int(c2) << int(c3) << int(c4) << endl;