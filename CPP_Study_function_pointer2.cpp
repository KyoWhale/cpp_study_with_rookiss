#include <iostream>
using namespace std;

// typedef의 진실
// typedef 왼쪽 오른값 -> 오른쪽
// 정확히는 왼쪽  오른쪽 기준이 아니라
// [선언문법]에서 typedef을 앞에다 붙이는 쪽

typedef int INTEGER;
typedef int* POINTER;
typedef int FUNC(int, int);
typedef int ARRAY[20];

class Knight
{
public:
    int GetHp(int, int)
    {
        cout << "GetHp" << endl;
        return _hp;
    }
public:
    int _hp = 100;
};

int Test(int a, int b)
{
    cout << "Test" << endl;
    return a+b;
}

int main()
{
    // *가 아닌 일반은 잘 사용하지 않음
    FUNC func;
    // 

    FUNC* fn; // 이렇게 사용해도 되지만
    typedef int (*PFUNC)(int, int); //를 선언하고 이를 쓰는 것도 있음, 이것을 추천
    PFUNC pfn;
    pfn = &Test;
    pfn(1,2);

    // 위 문법은 전역, 정적 함수만 담을 수 있음(호출 규약이 동일한 것들)

    Knight k1;
    k1.GetHp(1, 1);

    typedef int(Knight::*PMEMFUNC)(int, int); // 멤버 함수 포인터
    PMEMFUNC mfn;

    // mfn = Knight::GetHp; // 멤버 함수는 &를 붙여주어야함
    mfn = &Knight::GetHp;
    // k1.mfn(1, 1); // 이런식으로 쓰면 멤버 함수처럼 인식될 수 있기에 아래처럼 써야함
    (k1.*mfn)(1, 1);

    Knight* k2 = new Knight();

    ((*k2).*mfn)(1,1); // 아래랑 동일
    (k2->*mfn)(1,1); // 위와 동일

    delete k2;

    return 0;
}