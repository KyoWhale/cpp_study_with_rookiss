#include <iostream>
#include <vector>
#include <list>
using namespace std;

// override final
class Player
{
public:
    virtual void Attack()
    {
        cout << "Player!" << endl;
    }
    virtual void Defense()
    {
        cout << "Player!" << endl;
    }
};

class Knight : public Player
{
public:
    Knight() { cout << "기본 생성자" << endl; }
    Knight(const Knight &) { cout << "복사 생성자" << endl; }
    Knight(Knight&&) { cout << "이동 생성자" << endl; }
    virtual void Attack() override // override를 붙여줌으로서 내가 최초가 아니다라는 것을 알려줌
    {
        cout << "Knight!" << endl;
    }
    virtual void Attack() final // final을 붙여줌으로서 override의 의미를 포함해 내가 마지막 오버라이딩이라는 것을 알려줌
    {
        cout << "Knight!" << endl;
    }
};

// 복사하기 때문에 크기가 크면 오래 걸림
void TestKnight_Copy(Knight knight) {}
// 복사가 일어나지 않기 때문에 빠름
void TestKnight_LValueRef(Knight& Knight) {}
// 어차피 함수 내부에서 값을 변경하지 않을 것이기 때문에 가능
void TestKnight_ConstLValueRef(const Knight& Knight) {}
void TestKnight_RValueRef(Knight&& Knight) {} // 오른값 참조

void Test_Copy(Knight k)
{

}

// void Test_ForwardingRef(const T& param); // 왼값 참조를 또 만들어야한다면, 매개변수가 더 늘어난다면 만들어야하는 함수의 갯수가 배로 증가하기 때문에 두 경우를 한 번에 처리할 수 있는 전달 참조를 사용하는 것
// 그럼 두 것의 사용 방법을 나눠줘야하는데? -> forward
template<typename T>
void Test_ForwardingRef(T&& param) // 전달 참조
{
    
    // // 왼값 참조였다면
    // Test_Copy(param);

    // // 오른값 참조였다면
    // Test_Copy(move(param));

    // 위 조건의 의미를 갖고 있는 std:forward
    Test_Copy(forward<T>(param));
}


int main()
{
    Player* player = new Knight();
    player->Attack();

    // 오른값 참조
    // modern C++의 꽃
    // 이것의 도입으로 인해 이전과 이후의 속도차이가 많이 난다

    // 왼값 lvalue vs 오른값 rvalue
    // - lvalue : 단일식을 넘어서 계속 지속되는 개체
    // - rvalue : lvalue가 아닌 나머지 (임시값, 열거형, 람다, i++ 등)

    int a = 3;
    a = 4;
    // 3 = a; 3 = rvalue이므로 왼쪽에 두지 못함

    Knight k1;

    TestKnight_Copy(k1);
    TestKnight_LValueRef(k1);
    // TestKnight_LValueRef(Knight()); // lvalue가 아니기 때문에 어차피 사라질 값을 넣는 것은 비효율적
    TestKnight_ConstLValueRef(Knight()); // 어차피 함수 내부에서 값을 변경하지 않을 것이기 때문에 가능

    TestKnight_RValueRef(Knight()); // 왼값이기 때문에 가능
    // TestKnight_RValueRef(k1); // k1은 왼값이기 때문에 안 됨
    TestKnight_RValueRef(static_cast<Knight&&>(k1)); // k1은 왼값이기 때문에 안 되는데 캐스팅하면 됨

    // 오른값인 임시 객체의 값을 수정할 수 있지만 의미가 없음
    // 왼값을 오른값처럼 넘겨주어 원본을 수정할 수 있음
    // 어셈블리 단에서는 참조 인자와 rvalue의 차이가 크게 나지 않음
    // 그럼 왜 사용하느냐?
    // 어셈블리 단에선 비슷하지만, C++ 의미로는 다름
    // - 왼값 참조는 원본을 갖고 놀면 되라는 말이지만
    // - const 참조는 읽는 것은 허락해준다는 의미
    // - 오른값 참조는 넘겨주고 다신 사용하지 않을 것이라는 의미가 있음

    // 기존에 복사 대입 연산자를 할 때, 항상 깊은 복사를 하여 새로운 값을 만들어서 대입을 했지만,
    // 만약 그래야할 필요가 없고, 원래의 값을 다시 집어넣어줘야할 때 복사 대입 연산자의 매개변수로 오른값 참조를 사용할 수 있음
    // 그럼 깊은 복사 비용이 들지 않음
    // - 이것이 이동 대입 연산자
    // 원본을 날려도 된다는 힌트를 줌

    Knight k2 = move(k1); // std::move()

    unique_ptr<Knight> uptr = make_unique<Knight>();
    unique_ptr<Knight> uptr2 = move(uptr);

    // 보편 참조(universal reference) // 예전에는 이 이름으로 불렸음
    // 전달 참조(forwarding reference) // C++ 17
    // &&, 오른값 참조와 똑같이 생김
    Knight k3;
    TestKnight_RValueRef(move(k3));

    Test_ForwardingRef(move(k3)); // Knight의 오른값으로 잘 작동함
    Test_ForwardingRef(k1); // ? 통과가 됨, 나이트의 왼쪽 참조

    auto&& k4 = k3; // 오른값이 아님, 왼값임
    auto&& k5 = move(k3); // 오른값임

    // template, auto 같은 문법과 사용할 때만(형식 연역(type deduction)이 일어날 때) 전달 참조가 발생
    // 여기까지는 전달 참조를 구별하는 방법
    // --------------------------------------------------------------------------

    Knight& k6 = k3;
    Knight&& k7 = move(k3); // k7은 오른값 참조로 받은 왼값임
    // 오른값 : 왼값이 아니다 = 단일식에서 벗어나면 사용하지 못함
    // 오른값 참조 : 오른값만 참조할 수 있는 참조 타입

    // TestKnight_RValueRef(k6); // 왼값이라 불가
    // TestKnight_RValueRef(k7); // 오른값참조를 한 왼값이라 불가
    TestKnight_RValueRef(move(k7));

    return 0;
}