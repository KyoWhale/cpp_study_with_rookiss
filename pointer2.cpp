#include <iostream>
using namespace std;

int main() 
{
    cout << hex; // 출력값을 16진법으로 바꿔줌

    int num = 5;
    int* ptr = &num;

    __int64_t* ptr2 = (__int64_t*)ptr;
    *ptr2 = 0x0000AABBCCDDEEFF; //ptr2가 갖고 있는 주소의 값에 8바이트짜리 값을 대입
                                //ptr은 4바이트공간의 변수인데 그 넘어 주소까지 0000AABB가 씌워져서 위험함
    
    cout << *ptr << endl;       // ccddeeff
    *ptr = 0x0A0B0C0D;          //
    cout << *ptr << endl;       // a0b0c0d
    cout << *(ptr+1) << endl;   // aabb
}
// 출력 결과
// ccddeeff
// a0b0c0d
// aabb