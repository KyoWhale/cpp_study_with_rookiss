#include <iostream>
using namespace std;

void SetHP(int* hp)
{
    *hp = 100;
}

int main()
{
    // 일반 변수는 함수에서 원본 수정을 하고 싶은 경우 할 수 없음

    int* ptr; // 바구니는 바구니
    // [주소를 저장하는 바구니]
    // 참고) 포인터라는 바구니는 8바이트 고정크기
    // 변수를 선언할 때의 * = 주소를 담는 변수를 선언하라
    // 변수를 사용할 때의 * = 담긴 주소로 이동하라
    // ex) int* ptr = 0x00000000; // 주소를 담는 ptr 변수

    int num = 5;
    ptr = &num;

    // 사용법
    int value1 = *ptr;
    *ptr = 2;

    // NULL, nullptr
    // ptr = nullptr;

    // Type을 붙이는 이유

    // 타입 불일치
    __int64_t* ptr2 = (__int64_t*)ptr;
    *ptr2 = 0x0000AABBCCDDEEFF; //ptr2가 갖고 있는 주소의 값에 8바이트짜리 값을 대입
    //ptr은 4바이트공간의 변수인데 그 넘어까지 0000AABB가 씌워져서 위험함
    *ptr = 0x0A0B0C0D;
    cout << hex;
    cout << *ptr << endl;
    cout << *(ptr+1) << endl;

    int hp = 1;
    cout << "hp : " << hp << endl;
    SetHP(&hp);
    cout << "hp : " << hp << endl;
}