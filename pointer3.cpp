#include <iostream>
using namespace std;

int main() 
{
    cout << hex; // 출력값을 16진법으로 바꿔줌

    short sh = 123;
    short* sPtr = &sh;
    cout << sPtr << ", " << sPtr + 1 << endl;

    int64_t lo = 123789LL;
    int64_t *lPtr = &lo;
    cout << lPtr << ", " << lPtr + 1 << endl;
}
// 출력 결과
// 0x16b02b24e, 0x16b02b250 // 4e에서 2바이트 넘은 50 // 4f 50
// 0x16b02b238, 0x16b02b240 // 38에서 8바이트 넘은 40 // 39 3a 3b 3c 3d 3e 3f 40