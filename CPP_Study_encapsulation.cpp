#include <iostream>
using namespace std;

// 숨기는 이유?
// 1) 위험하기에 건드리면 안 됨
// 2) 다른 경로로 접근하길 원하는 경우

// 자동차
// - 핸들
// - 페달
// - 엔진
// - 문
// - 각 종 전기선
// 일반 구매자 입장에서 사용하는 것?
// - 핸달 페달 문
// 몰라도 됨 (건드리면 큰일나는 것)
// - 엔진, 각 종 전기선

// 접근 지정자
// public protected private
// public : 누구에게나 공개
// protected : 상속 관계에서만 허락
// private : 현재 클래스에서만 허락

// 상속 접근 지정자 : 
// 보통 public만 씀
// public : 공개적 상속 : public -> public, protected -> protected
// protected : public -> protected, protected -> protected
// private : public -> private, protected -> private

class Car
{
public: // 접근 지정자
    void MoveHandle() {}
    void PushPedal() {}
    void OpenDoor() {}

    void TurnKey()
    {
        RunEngine();
    }
protected: // 접근 지정자
    void RunEngine() {}
    void DisassembleCar() {}
    void ConnectCircuit() {}
};

class SuperCar : private Car
{
public:
    void PushRemoteController()
    {
        RunEngine();
    }
};

// SuperCar가 private으로 Car를 상속 받았기에 Car의 멤버가 다 private
class TestSuperCar : public SuperCar // public을 빼서 쓰면 private가 됨
{
public:
    void Test()
    {
        PushRemoteController();
        // RunEngine(); // 안 됨
    }
};

class Berserker
{
public:
    int GetHp() { return _hp; }
    void SetHp(int hp)
    {
        _hp = hp;
        if (_hp <= 50)
        {
            SetBerserkerMode();
        }
    }

private:
    void SetBerserkerMode()
    {
        cout << "Set Berserker Mode" << endl;
    }

private:
    int _hp = 100;
};

int main() 
{
    Car car;
    car.OpenDoor();

    Berserker b;
    // b._hp = 20; // hp가 공개였을 땐 hp를 바로 건들였지만 버서커 모드가 안 됨
    b.SetHp(20); // 버서커 모드 작동
    // 이처럼 같이 동작해야하는 함수들은 하나로 묶어서 인터페이스로 만들어주는 것이 중요함
}