#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 반복자(iterator) : 포인터와 유사한 개념, 컨테이너의 원소를 가르키고, 다음/이전 원소로 이동 가능
    vector<int> v(10);

    // for (int i = 0; i < static_cast<unsigned int>(v.size()); i++) // 형 변환 방법 1
    for (vector<int>::size_type i = 0; i < v.size(); i++) // 형변환 방법 2
        v[i] = i;

    
    vector<int>::iterator it;
    int* ptr;

    it = v.begin();
    ptr = &v[0];

    cout << (*it) << endl;
    cout << (*ptr) << endl;

    it++;
    ++it;
    ptr++;
    ++ptr;

    it--;
    --it;
    ptr--;
    --ptr;

    it += 2;
    it = it - 2;
    ptr += 2;
    ptr = ptr - 2;

    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end(); // end는 마지막 원소의 다음을 가르킴

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) // 전위 연산자가 살짝 더 빠름, 임시 객체에 복사하는 연산이 없기 때문
    {
        cout << (*it) << endl;
    }

    int* ptrBegin = &v[0]; // v.begin()._Ptr;
    int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;
    for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
    {
        cout << *ptr << endl;
    }

    // v[i] 처럼 사용하는게 더 편하지 않나?
    // iterator는 vector뿐 아니라 다른 컨테이너에도 공통적으로 있는 개념
    // 다른 컨테이너는 v[i] 같이 인덱스 접근이 안 될 수 있음
    
    // const int*;
    vector<int>::const_iterator cit = v.cbegin();
    // *cit = 100; // const 이기 때문에 안 됨

    // 역순 이터레이터
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
    {
        cout << *it << endl;
    }

    // vector = 동적 배열 = 동적으로 커지는 배열 = 배열
    // 원소가 하나의 메모리 블록에 연속하게 저장됨
    // - 중간 삽입/삭제는 / 비효율적
    // - 처음/끝 삽입/삭제 / 처음은 비효율적 / 끝은 효율적
    // - 임의 접근(Random Access) / 가능함

    v.insert(v.begin() + 2, 5); // 2자리에 5를 넣기
    v.erase(v.begin() + 2); // 2에 있는 것 삭제
    v.erase(v.begin() + 2, v.begin() + 4); // 2 ~ 4직전까지 삭제
    // 이 상태에서 iterator를 사용할 때, capacity가 가득차서 다른 메모리 영역으로 옮겨졌을 수도 있으니 조심해야함

    for (vector<int>::iterator it = v.begin(); it != v.end();)
    {
        int data = *it;
        if (data == 3)
        {
            it = v.erase(it); // erase it을 하게 되면 it이 NULL을 가르키게 되기에 erase의 반환으로 다시 받아야함
        }
        else
        {
            ++it; // if 문 안에를 들어가면 it은 삭제하고 난 그 다음을 가르키기 때문에 if의 it은 이미 증가된 것이라 간주하는 것
        }
    }
    return 0;
}