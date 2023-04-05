#include <iostream>
#include <list>
using namespace std;

// vector : 동적 배열
// [                ] 의 연속된 큰 크기를 갖는다할 때
// list는
// [] ->      []->[] ->  [] 처럼 단절된 각 원소의 크기의 공간이 이어져 있는 형태
// stl list는 이중리스트
// stl list는 가상의 마지막 노드하나를 추가하였기에 이를 통해 마지막인 것을 확인
// 각 원소는 노드라고하고, 다음 지점을 찾아갈 수 있는 주소를 갖고 있음
// 노드는 아래 형태와 같음
class Node
{
public:
    Node* _next;
    int _data;
};

int main()
{
    // list, 연결리스트
    // - list의 동작 원리
    // - 중간 삽입 / 삭제
    // - 처음/끝 삽입/삭제
    // - 임의 접근

    list<int> li;

    for(int i = 0; i < 100; i++)
        li.push_back(i);

    li.push_front(10);

    int size = li.size();
    // li.capacity() 없음

    int first = li.front();
    int last = li.back();
    // li[3] = 10; 없음

    list<int>::iterator itBegin = li.begin();
    list<int>::iterator itEnd = li.end();
    // stl list는 가상의 마지막 노드하나를 추가하였기에 이를 통해 마지막인 것을 확인, 더미 노드
    // --itBegin; 에러
    // --itEnd; 가능
    // ++itEnd; 에러

    // itBegin = itBegin + 10; // 한번에 여러번 가는 것 같은 형식은 지원하지 않음

    for(list<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        cout << *it << endl;
    }

    li.insert(itBegin, 100);
    
    li.erase(li.begin()); // 중간 삭제도 가능한 것
    li.pop_front(); // 맨 처음의 것을 삭제하며 값을 반환

    li.remove(10); // 어떤 값을 갖고 있는 모든 것을 삭제
    // 벡터가 이 함수가 없는 이유는 중간 삭제의 효율이 좋지 않기 때문

    // 임의 접근이 안 되지만
    // 중간 삽입/삭제는 빠르다?
    list<int>::iterator it = li.begin();
    for (int i = 0; i < 50; i++)
        ++it;

    li.erase(it);
    // for문을 50번 돌고 나서 지우는 것이 빠른가?
    // for문을 50번 도는 것과, 삭제를 분리해서 생각한다면
    // 삭제만 하는 것은 빠름
    // for을 항상 꼭 처음부터 50번도는것이 아니고 우리가 45번째에 있거나 50번째에 있었다면 거의 바로 삭제 가능하니 효율적

    return 0;
}