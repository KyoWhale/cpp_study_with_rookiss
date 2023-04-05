#include <iostream>
#include <map>
#include <set>
using namespace std;

// set : 중복을 허용하지 않는 집합, 키만 활용함
// multimap : 중복 키를 허용하는 맵, 자주 안 씀
// multiset : 중복 키를 허용하는 셋, 자주 안 씀

// 연관 컨테이너
// 넣고
// 빼고
// 찾고
// 순회하기

int main()
{
    // 넣고
    set<int> s;
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(40);
    s.insert(70);
    s.insert(2);
    s.insert(5);

    // 빼고
    s.erase(40);

    // 찾고
    set<int>::iterator findIt = s.find(50);
    if (findIt == s.end())
    {
        cout << "못 찾음" << endl;
    }
    else
    {
        cout << "찾음" << endl;
    }

    // 순회하고
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << (*it) << endl;
    }

    multimap<int, int> mm;

    // 넣고
    mm.insert(make_pair(1, 100));
    mm.insert(make_pair(1, 200));
    mm.insert(make_pair(1, 300));
    mm.insert(make_pair(2, 100));
    mm.insert(make_pair(2, 200));
    mm.insert(make_pair(3, 200));
    
    // mm[1] = 500; // 막혀있음

    // 빼고
    mm.erase(2); // 2인 키 모두가 삭제됨, 삭제한 갯수를 반납함

    // 찾고
    multimap<int, int>::iterator itFind = mm.find(1);
    if (itFind != mm.end())
        mm.erase(itFind);

    // 순회하고
    
    // 키가 1인 모든 값 순회
    pair<multimap<int, int>::iterator, multimap<int, int>::iterator> itPair;
    itPair = mm.equal_range(1);

    for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    // 키가 1인 모든 값 순회
    multimap<int, int>::iterator itBegin = mm.lower_bound(1); // 첫 원소
    multimap<int, int>::iterator itEnd = mm.upper_bound(1); // 마지막 원소의 다음
    for (multimap<int, int>::iterator it = itBegin; it != itEnd; ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    // 전체 값 순회
    for (multimap<int, int>::iterator it = mm.begin(); it != mm.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    multiset<int> ms;
    // 넣고
    ms.insert(100);
    ms.insert(100);
    ms.insert(200);
    ms.insert(200);
    ms.insert(300);
    ms.insert(400);

    // 찾고
    multiset<int>::iterator findIt2 = ms.find(100);

    pair<multiset<int>::iterator, multiset<int>::iterator> itPair2;
    itPair2 = ms.equal_range(100);

    for (multiset<int>::iterator it = itPair2.first; it != itPair2.second; ++it)
    {
        cout << *it << endl;
    }

    multiset<int>::iterator itBegin2 = ms.lower_bound(100);
    multiset<int>::iterator itEnd2 = ms.upper_bound(100);
    for (multiset<int>::iterator it = itBegin2; it != itEnd2; ++it)
    {
        cout << *it << endl;
    }

    return 0;
}