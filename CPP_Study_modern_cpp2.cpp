#include <iostream>
#include <vector>
#include <list>
using namespace std;

#pragma region using
// using
typedef vector<int>::iterator vecIt;
typedef __int64 i64;

using id2 = int; // using 새로운이름 = 원래이름;

// 1. 직관성에서 좋음
typedef void (*MyFunc)(); // typedef 함수 포인터
using MyFunc2 = void(*)(); // using을 사용한 함수 포인터

// 2. 템플릿
// typedef는 템플릿을 활용할 수 없음
// using으로는 아래처럼 가능
// template<typename T>
// using List = std::list<T>

// 템플릿을 쓰는 예전에는 구조체로 간접적으로 사용했음
template<typename T>
struct List2
{
    typedef std::list<T> type;
};
#pragma endregion
#pragma region delete
class Knight
{
public:
    void operator=(const Knight& k) = delete;
private:
    // void operator=(const Knight& k) // 복사가 일어나지 않게 private
    // {

    // }
    friend class Admin; // Admin에는 복사 연산이 열어짐
private:
int _hp = 100;
};
#pragma endregion

int main()
{
#pragma region enum
    // enum class (scoped enum)
    // 1. 이름공간 관리가 좋음
    // - 기본의 여러 enum에서 동일한 원소가 있었으면 중복이 불가능했음
    // - 그래서 enum 이름이 약자를 원소 앞에 접두사로 붙임, PT_XX

    // 2. 암묵적인 변환 금지 (장점이 될 수 있고 단점이 될 수 있음)

    enum PlayerType : char // char를 붙여 기본 4byte를 1byte 짜리로 만들 수 있음
    {
        PT_Knight,
        PT_Archer,
        PT_Mage
    };

    cout << sizeof(PlayerType) << endl;
#pragma endregion
}