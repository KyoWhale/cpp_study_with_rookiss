#include <iostream>
#include <map>
using namespace std;

// 연관 컨테이너

class Player
{
public:
    Player();
    Player(int id) : _id(id)
    {

    }
public:
    int _id;
};

int main()
{
    // map : 균형 이진 트리
    // - 노드 기반

    class Node
    {
    public:
        Node* _left;
        Node* _right;
        pair<int, Player*> _data;
        // int _key;
        // Player* _value;
    };

    map<int, int> m;

    // 서버에 10만명 입장
    for (int i = 0; i < 100000; i++)
    {
        m.insert(pair<int, int>(i, i*100));
    }

    // 5만명 퇴장
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 50000; i++)
    {
        int randomValue = rand() % 50000;
        m.erase(randomValue);
    }

    // Q) ID = 10000인 플레이어 찾고 싶다
    // A) 매우 빠르게 찾을 수 있음
    map<int, int>::iterator findIt = m.find(10000);
    if (findIt != m.end())
    {
        cout << "찾음" << endl;
    }
    else
    {
        cout << "못찾음" << endl;
    }

    // 같은 key erase
    unsigned int count = 0;
    count = m.erase(10000); // 찾으면 count = 1
    count = m.erase(10000); // 못 찾으면 count = 0
    // 이미 없어도 상관 없음

    // 같은 key insert
    m.insert(make_pair(1, 100));
    m.insert(make_pair(1, 200));
    // 이미 있으면 추가 요청은 받아들여지지 않음

    // map 순회
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        pair<const int, int>& p = (*it);
        int key = p.first;
        // key = it->first; // 위와 동일
        int value = p.second;
        // value = it->second; // 위와 동일
    }

    // 없으면 추가, 있으면 수정
    map<int, int>::iterator findIt = m.find(10000);
    if (findIt != m.end())
    {
        findIt->second = 200;
    }
    else
    {
        m.insert(make_pair(10000, 200));
    }

    // 없으면 추가, 있으면 수정2
    m[10000] = 200;
    // [] 연산자 사용할 때 주의
    // 대입을 하지 않더라도 Key/Value 형태의 데이터가 추가됨
    m.clear();
    for (int i = 0; i < 10; i++)
    {
        cout << m[i] << endl;
    }

    return 0;
}