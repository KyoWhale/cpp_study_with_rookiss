#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 시퀀스 컨테이너
// 데이터가 삽입 순서대로 나열되는 형태
// vector list deque

// vector : 동적 배열
// [        ]

// list : 이중 연결 리스트
// [] <-> [] <-> [] <-> []

// deque : double-ended queue 데크
// [      ]
// [      ]
// [      ]

int main()
{
    {
        deque<int> dq;
        dq.push_back(1);
        // dq.capacity() // 없음

        dq.push_back(1);
        dq.push_front(2);
        cout << dq[0] << endl;
    }

    // vector와 마찬가지로 배열 기반 동작
    // 다만 메모리 할당 정책이 다름

    // vector
    // [1 1 1 2 2  ]

    // deque
    // [    3 3]
    // [1 1 1 2]
    // [2      ]

    vector<int> v(3, 1);
    deque<int> dq(3, 1);

    v.push_back(2);
    v.push_back(2);

    dq.push_back(2);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(3);

    // -deque 동작 원리
    // 중간 삽입/삭제 / 둘 다 나쁨
    // 처음/끝 삽입/삭제 둘 다 좋음
        // 양방향 추가 삭제가 좋음
    // 임의 접근 좋음
        // 배열 블록 + 그 블록에서의 오프셋 두 번의 빠른 접근을 통해 임의 접근을 함

    return 0;
}