#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // STL (Standard Template Library)
    // 프로그래밍 할 때 필요한 자료구조/알고리즘을
    // 템플릿으로 제공하는 라이브러리

    // 컨테이너 : 데이터를 저장하는 객체 ( 자료구조 Data structure )

    // vector (동적 배열)
    // - 동작 원리 (size/capacity)
    // - 중간 삽입 / 삭제
    // - 처음 / 끝, 삽입 / 삭제
    // - 임의 접근

    // size : 실제 사용 데이터 개수
    // capacity : 여어분을 포함한 용량 개수

    // 배열
    // - 길이가 늘어나거나 줄어들 수 없음

    // 동적 배열
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    const int size = v.size();
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << endl;
    }
    // 어떤 마법을 부렸길래 배열을 유동적으로 사용한 것인가

    // 1) 여유분을 두고 메모리를 할당
    // 1-1) 여유분은 얼만큼이 적당할까?

    // 2) 여유분까지 꽉 찼으면, 메모리를 증설한다
    // 2-1) 증설은 얼만큼 해야할까?

    // 3) 기존의 데이터를 어떻게 처리할까?

    // size, capacity(1.5배 ~ 2배 정도씩 증가, )
    for (int i = 0; i < 1000; i++)
    {
        v.push_back(100);
        cout << v.size() << " " << v.capacity() << endl;
    }

    // 현재 용량이 꽉차서 capacity를 늘려야할 때 이동해야하는 비용이 들지만, 그만큼 용량이 배로 늘어나기 때문에 이동의 횟수가 점점 줄어듬
    // 어느정도 크기의 윤곽을 안다면 capacity를 처음에 그만큼 잡고 시작할 수 있음
    vector<int> v2;
    v2.reserve(1000);
    for (int i = 0; i < 1000; i++)
    {
        v2.push_back(100);
        cout << v2.size() << " " << v2.capacity() << endl;
    }

    // 사이즈 조정
    vector<int> v3;
    v3.resize(1000);
    cout << v3.size() << " " << v3.capacity() << endl;

    // 값을 다 지워도 capacity는 줄어들지는 않음
    v3.clear();
    // vector<int>().swap(v3); // capacity까지 날릴 수 있지만, 한 번 그 크기까지 갔으면 또 갈 수 있기 때문에 잘 하지 않음
    cout << v3.size() << " " << v3.capacity() << endl;

    vector<int> v4(1000, -1);
    vector<int> v5 = v4; // 모든 값을 다 복사

    return 0;
}