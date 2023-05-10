#include <iostream>
#include <vector>
using namespace std;

void Test(int a)
{
    cout << "Test(int)" << endl;
}

void Test(int* a)
{
    cout << "Test(int*)" << endl;
}
class Knight
{
public:
    Knight() {}
    Knight(int a, int b)
    {
        cout << "Knight(int, int)" << endl;
    }
    Knight(initializer_list<int> li)
    {
        cout << "Init_list" << endl;
    }
    void Test()
    {

    }
};

Knight* FindKnight()
{
    return nullptr;
}

// nullptr 구현
const // 바뀌면 안 되는 객체
class // 이름이 없어도 됨
{
public:
    // 어떤 타입의 포인터와도 치환 가능
    template<typename T>
    operator T*() const
    {
        return 0;
    }

    // 어떤 타입의 멤버 포인터와도 치환 가능
    template<typename C, typename T>
    operator T C::*() const
    {
        return 0;
    }

// 주소값&를 막는 방법
// 방법 1. delete로 사용하지 못하게 함
    // void operator&() const = delete;
// 방법 2. 접근 지정자를 private
// private:
//     void operator&() const;  
} _NullPtr; // 이름 없는 클래스의 객체 하나만을 만듬

int main() 
{
#pragma region auto
    // auto
    int a = 3;
    float b = 3.14f;
    double c = 1.23;
    char* d = "rookiss";

    // auto : 형식 연역(type deduction)
    // -> 컴파일러에게 알아서 타입을 맞추게하는 것
    // - 추론 규칙은 생각보다 복잡해질 수 있음
    // - 포인터, 레퍼런스, 보편참조 등
    auto a2 = 3;
    auto b2 = 3.14f;
    auto c2 = 234.2;
    auto d2 = "rookiss";

    auto e = &a;
    const auto test1 = b;
    // auto* test2 = a; // 안 됨

    // 주의할 점
    // 기본 auto 자체는 const, & 무시
    int& reference = a;
    const int cst = a;

    auto test2 = reference; // int로 바뀜
    auto teest3 = cst; // int로 바뀜

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (vector<int>::size_type i = 0; i < v.size(); i++)
    {
        auto data = v[i];
        data = 100; // 지역변수의 값을 바꾸는 것이기 때문에 벡터의 원소 값이 바뀌는 것이 아님
    }

    // 이제 모든 자료형을 auto로 바꿔서 쓴다? -> NO
    // 일반적인 상황에서는 원래 자료형을 사용
    // 타이핑이 굉장히 길어지는 경우에만 사용 ex) map
#pragma endregion
#pragma region bracket_init
    // 중괄호 초기화
    // 1. vecotr 등 container와 어울린다
    vector<int> v2(10, 1);
    int arr[] = {1, 2, 3, 4};
    vector<int> v3 { 1, 2, 3, 4 };

    // 2.축소 변환 방지
    int x = 0;
    // double y {x};

    // 3. init list
    Knight a {1, 2}; // init list 생성자만 호출될 수 있어서 다른 생성자를 막아버릴 수 있음
    
    // 괄호 초기화()를 기본으로 간다
    // - 전통적인 C++ 거부감이 없음
    // - vector 등 특이한 케이스만 대해서 { } 사용

    // 중괄호 초기화 { }를 기본으로 간다
    // - 초기화 문법의 일치화
    // - 축소 변환 방지
#pragma endregion
#pragma region nullptr
    // nullptr
    // 이전에는 0 또는 NULL을 활용했었음
    int* ptr = NULL;
    ptr = 0;

    // nullptr을 사용하는 이유
    // 1. 오동작을 막기 위함
    Test(0);
    Test(NULL);
    Test(nullptr);

    // 2. 가독성
    Knight* knight = FindKnight();
    if (knight == nullptr)
    {

    }

    // 3. 함수 포인터에서도 가독성
    void (Knight::*memFunc)();
    memFunc = &Knight::Test;

    if (memFunc == _NullPtr)
    {
        
    }
#pragma endregion
#pragma region using
    // using
    typedef vector<int>::iterator vecIt;
    typedef __int64 i64;

    using id2 = int; // using 새로운이름 = 원래이름;

    // 1. 직관성에서 좋음
    typedef void (*MyFunc)(); // typedef 함수 포인터
    using MyFunc2 = void(*)(); // using을 사용한 함수 포인터

    // 2. 템플릿
    // typedef는 템플릿과 맞지 않음
}