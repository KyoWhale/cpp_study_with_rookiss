#include <iostream>
using namespace std;

// 메모리 구조 복습
// - 실행할 코드가 저장되는 영역 -> 코드 영역
// - 전역 정적 변수 -> 데이터 영역
// 지역 변수 / 매개 변수 -> 스택 영역

// 지금까지 그럭 저럭 만들었는데 왜 필요할까?
//
// 실제 상황)
// - MMORPG 동접 1명 ~ 5만명, 몬스터 1마리 ~ 500만 마리
// - 몬스터 생성 이벤트 -> 5분동안 몬스터가 10배 많이 나옴

// - 스택 영역
// 함수가 끝나면 같이 정리되는 불안정한 메모리
// 잠시 함수의 매개변수 넘긴다거나 하는 용도로는 ok
// - 메모리 영역
// 프로그램이 실행되는 도중에는 무조건 사용되는

// 희망사항
// - 필요할 때만 사용하고, 필요 없으면 반납할 수 있는
// - 그러면서도 (스택과 다르게) 우리가 생성 / 소멸 시점을 관리할 수 있는
// - 그런 아름다운 메모리 없나 -> 힙
// 동적할당과 연관된 함수 / 연산자 : malloc <-> free, new <-> delete, new[] <-> delete[]

// malloc
// - 할당할 메모리 크기를 건네준다
// - 메ah리 할당 후 시작 주소를 가르키는 포인터를 반환해준다 (메모리 부족 NULL)

// free
// - malloc (혹은 calloc or realloc) 을 통해 할당된 영역을 해제
// - 힙 관리자가 할당/미할당 여부를 구분해서 관리

// new / delete
// - C++에 추가됨
// - malloc / free 함수! new /delete는 연산자

class Monster
{
public:
    int _hp;
    int _x;
    int _y;
};

// Monster monster[500 * 10000]; // 

int main()
{
    Monster monster[500 * 10000]; // 스택 오버풀로우, 스택은 이렇게 어마어마하게 많은 데이터를 담기 위해 있는게 아님
    // 함수들끼리 인자를 전달하고 주고받는 용도

    // 유저 영역 [메모장] [롤] [곰플레이어]
    // ----------------------------------
    // 커널 영역 (Windows 등의 핵심 코드)

    // 유저 영역) 운영체제에서 제공하는 API 호출
    // 커널 영역) 메모리 할당해서 건내줌
    // 유저 영역) 잘 쓸게요~

    // C++ 에서는 기본적으로 CRT(C런타임 라이브러리)의 [힙 관리자]를 통해 힙 영역 사용
    // 단, 정말 원한다면 우리가 직접 API를 통해 힙을 생성하고 관리할 수도 있음(MMORPG 서버 메모리 풀링)


    // void* ??
    // *가 있으니까 포인터는 포인터 (주소를 담는 바구니)
    // 타고 가면  void 아무것도 없다? => NO
    // 타고 가면 void 뭐가 있는지 모르니까 너가 적당히 변환해서 사용해라
    void* pointer = malloc(sizeof(Monster));
    Monster* m1 = (Monster*)pointer;
    m1->_hp = 100;
    m1->_x = 1;
    m1->_y = 2;

    // [12][pointer]
    free(pointer); // 동적할당할때 할당하는 곳 앞 부분에 몇 바이트인지 적어둠 / 또는 테이블을 사용해서 관리
    // free를 하지 않으면 메모리 누수
    
    // double free
    // - 크래시만 나고 끝남

    // use-after-free
    // 반납했는데, 사용
    // - 프로그래머 입장 : 망함
    // - 해커 : 네이스

    // pointer 크기 4로 해놓고 _x, _y 등의 뒤쪽을 쓰다보면?
    // heap overflow
    // - 유효한 힙 범위를 초과해서 사용하는 문제

    Monster* m2 = new Monster;
    m2->_hp = 100;
    m2->_x = 1;
    m2->_y = 2;
    delete m2;


    Monster* m3 = new Monster[9];
    delete[] m3;

    return 0;
}