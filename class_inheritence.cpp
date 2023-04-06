#include <iostream>
using namespace std;

const int TILE_ROW = 10;
const int TILE_COL = 10;

class Specialty
{
public:
    Specialty()
    {
        cout << "매개변수 없는 생성자 호출" << endl;
        m_posX = 0;
        m_posY = 0;
        spawnCount++;
    }
    Specialty(int value)
    {
        cout << "매개변수 1개 생성자 호출" << endl;
        m_posX = value;
        m_posY = value;
        spawnCount++;
    }
    Specialty(int x, int y)
    {
        cout << "매개변수 2개 생성자 호출" << endl;
        m_posX = x;
        m_posY = y;
        spawnCount++;
    }
    Specialty(const Specialty& original)
    {
        cout << "복사 생성자 호출" << endl;
        m_posX = original.m_posX;
        m_posY = original.m_posY;
        spawnCount++;
    }
    ~Specialty()
    {
        cout << "소멸자 호출" << endl;
        spawnCount--;
    }
    void Print() const;
    void Move(int x, int y);
    static void InitSpawnCount();
private:
    bool IsSafePosition(int x, int y);
protected:
    int m_posX;
    int m_posY;
    static int spawnCount;
};

int Specialty::spawnCount = 0;
void Specialty::InitSpawnCount()
{
    spawnCount = 0;
    cout << "spawnCount Initalized" << endl;
}

void Specialty::Print() const
{
    cout << "Total : " << spawnCount << "\tPos : " << m_posX << ",\t" << m_posY << endl;
}

void Specialty::Move(int x, int y)
{
    cout << "Specialty Move " << x << " " << y << endl;
    if (IsSafePosition(x, y))
    {
        m_posX = x;
        m_posY = y;
    }
}

bool Specialty::IsSafePosition(int x, int y)
{
    cout << "Specialty IsSafePosition " << x << " " << y << endl;
    if (x < 0 || y < 0 || TILE_ROW <= x || TILE_COL <= y)
    {
        return false;
    }

    return true;
}

class Knight : public Specialty
{

};

class Parent
{
public:
    // Parent() { cout << "Parent()" << endl; }
    // Parent(int a) { cout << "Parent(int)" << endl; }
    // ~Parent() { cout << "~Parent()" << endl; }

    void Print() { cout << "Parent Print()" << endl; }
};

class Child : public Parent
{
public:
    // Child() { cout << "Child()" << endl; }
    // Child(int a) { cout << "Child(int)" << endl; }
    // ~Child() { cout << "~Child()" << endl; }

    void Print() { cout << "Child Print()" << endl; }
};

int main()
{
    Child c;

    Parent* pp = &c;
    Child* pc = (Child*)pp;

    c.Print();
    pp->Print();
    pc->Print();
}
// 출력 결과
// Child Print()
// Parent Print()
// Child Print()