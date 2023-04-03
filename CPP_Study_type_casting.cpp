#include <iostream>
using namespace std;

class Knight
{
public:
    int _hp = 10;
};

class Dog
{
public:
    Dog()
    {
        
    }
    Dog(Knight& knight) // 타입 변환 생성자
    {
        _age = knight._hp;
    }
    operator Knight() // 타입 변환 연산자
    {
        return (Knight)(*this);
    }
public:
    int _age;
    int _cuteness;
};

class BullDog : public Dog
{
public:
    bool _french;
};

int main() 
{
    // 1. 값 타입 변환
    // 의미를 유지하기 위해, 원본 객체와 다른 비트열 재구성
    int a = 123456789;
    float b = (float)a;
    cout << b << endl;

    // 2. 참조 타입 변환
    // 비트열을 재구성하지 않고 관점만 바꾸는 것
    // 거의 쓸일은 없지만, 포인터 타입 변환도 참조 타입 변환과 동일한 룰을 따르니까 일석이조로 공부하자
    int c = 123456789;
    float d = (float&)c;
    cout << d << endl;

    // ----------- 안전도 분류 -----------
    // 1. 안전한 변환
    // 의미가 항상 100% 완전히 일치하는 경우
    // 같은 타입이면서 크기가 더 큰 바구니로 이동
    // 작은 바구니 -> 큰 바구니로 이동 OK(업캐스팅)
    // ex) char -> short, short -> int, int -> long

    // 2. 불안전한 변환
    // 의미가 항상 100% 일치한다고 보장하지 못하는 경우

    // ------- 관계 없는 클래스 사이의 변환 ------- 
    // 1. 연관 없는 클래스 사이의 '값 타입' 변환
    // 일반적으로 안됨(예외: 타입 변환 생성자, 타입 변환 연산자)
    Knight knight;
    Dog dog = (Dog)knight;

    Knight knight2 = dog;

    // 2. 연관 없는 클래스 사이의 참조 타입 변환
    Knight knight3;
    Dog& dog = (Dog&)knight3;
    dog._cuteness = 12;

    // ------- 상속 관계 클래스 사이의 타입 변환 -------
    // 1. 상속 관계 클래스의 값 타입 변환
    // 자식 -> 부모 OK, 부모 -> 자식 NO
    // 안됨
    // Dog dog;
    // BullDog bulldog = (BullDog)dog;

    // 가능
    {
        BullDog BullDog;
        Dog dog = (Dog)BullDog;
    }


    // 2. 상속 관계 클래스의 참조 타입 변환
    // 자식 -> 부모 OK, 부모 -> 자식 (암시적 NO) (명시적 OK)
    {


        BullDog bullDog;
        Dog dog = bullDog;
    }

    // 결론
    // [값 타입 변환] 진짜 비트열도 바꾸고 논리적으로 말이 되게 바꾸는 변환
    // - 논리적으로 말이 된다? (BullDog -> Dog ) Ok
    // - 논리적으로 말이 안 된다 (Dog -> BullDog, Dog -> Knight) 안 됨
    // [참조 타입 변환] 비트열은 냅두고 우리의 관점만 바꾸는 변환
    // - 땡깡 부리면(명시적 요구) 해주긴 하는데, 말 안해도 그냥(암시적)으로 해주는지는 안정성 여부에 연관 있음
    // - 안전하다? (BullDog -> Dog&) 그냥 OK
    // - 위험하다? (Dog -> BullDog&)
    // -- 메모리 침범 위험이 있는 경우는 그냥 안해줌
    // -- 명시적으로 정말 하겠다고 하면 OK
}