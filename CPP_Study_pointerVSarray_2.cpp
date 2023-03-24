#include <iostream>
using namespace std;

int main()
{
    // 주소를 담는 바구니
    // 진퉁은 저 멀리 어딘가에 있음
    // p 는 단지 그 곳으로 워프하는 포탈
    int* p;

    // 진짜베기, 원조데이터
    // 닭장처럼 데이터의 묶음(엄청 많고 거대함)
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // 상당히 많은 사람들이 배열 = 포인터라 착각함
    // '배열의 이름'은 배열의 시작 주소값을 가리키는 자료형*로 변환 가능
    p = arr;
    // 자료형 1차원 배열과 자료형* 포인터는 완전히 호환됨
    cout << p[0] << endl;
    cout << arr[0] << endl;
    cout << p[5] << endl;
    cout << arr[5] << endl;

    cout << *p << endl;
    cout << *arr << endl;
    cout << *(p+3) << endl;
    cout << *(arr+3) << endl;

    // 2차원 배열 vs 다중 포인터
    int arr2[2][2] = { { 1, 2 }, { 3, 4 } };
    int (*p2)[2] = arr2;
    cout << (*p2)[0] << endl;
    cout << (*p2)[1] << endl;
    cout << (*(p2+1))[0] << endl;
    cout << (*(p2+1))[1] << endl;

    cout << p2[0][0] << endl;
    cout << p2[0][1] << endl;
    cout << p2[1][0] << endl;
    cout << p2[1][1] << endl;

    // 주소가 항상 끝까지 유효한지 확인할 것
    // 힙을 다룰 때 더 자세히 설명함

    return 0;
}