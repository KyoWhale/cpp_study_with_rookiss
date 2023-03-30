#include <iostream>
using namespace std;

const int TILE_ROW = 10;
const int TILE_COL = 10;

class Specialty
{
public:
    void Initialize()
    {
        m_posX = 0;
        m_posY = 0;
        spawnCount++;
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
    if (IsSafePosition(x, y))
    {
        m_posX = x;
        m_posY = y;
    }
}

bool Specialty::IsSafePosition(int x, int y)
{
    if (x < 0 || y < 0 || TILE_ROW <= x || TILE_COL <= y)
    {
        return false;
    }

    return true;
}

class NewString
{
public:
    NewString()
    {
        m_nameLen = 1;
        m_name = new char[m_nameLen];
        strcpy(m_name, "");
    }
    NewString(const char* const name)
    {
        m_nameLen = strlen(name) + 1;
        m_name = new char[m_nameLen];
        strcpy(m_name, name);
    }
    NewString(const NewString& origin)
    {
        m_nameLen = origin.m_nameLen;
        m_name = new char[m_nameLen];
        strcpy(m_name, origin.m_name);
    }
    ~NewString()
    {
        delete[] m_name;
        m_nameLen = 0;
        m_name = nullptr;
    }
    NewString& operator=(const NewString& right) // 복사 대입 연산자
    {
        if(this == &right)
        {
            return *this;
        }

        delete []m_name;
        m_nameLen = right.m_nameLen;
        m_name = new char[m_nameLen];
        strcpy(m_name, right.m_name);
        return *this;
    }
    NewString& operator=(const char* const charArr) // 대입 연산자
    {
        delete []m_name;
        m_nameLen = strlen(charArr) + 1;
        m_name = new char[m_nameLen];
        strcpy(m_name, charArr);
        return *this;
    }
    bool operator==(const NewString& right) // 비교 연산자
    {
        if (strcmp(m_name, right.m_name) == 0)
        {
            return true;
        }
        return false;
    }
    NewString& operator++() // 전위 증가 연산자, ++T
    {
        char* tempCharArr = m_name;

        m_nameLen++;
        m_name = new char[m_nameLen];
        strcpy(m_name, tempCharArr);
        strcat(m_name, "!");
        delete[] tempCharArr;

        return *this;
    }
    NewString operator--(int value) // 후위 감소 연산자, T--
    {
        NewString temp = *this;

        if (m_nameLen == 1) // 간단한 예외처리
        {
            return temp;
        }
        m_nameLen--;
        m_name[m_nameLen - 1] = '\0';
        char* tempCharArr = m_name;
        m_name = new char[m_nameLen];
        strcpy(m_name, tempCharArr);
        delete[] tempCharArr;

        return temp;
    }
    char& operator[](int n) // 첨자 지정 연산자, []
    {
        if (n >= m_nameLen)
        {
            return m_name[m_nameLen - 1];
        }
        else if (n < 0)
        {
            return m_name[0];
        }
        return m_name[n];
    }
    friend ostream& operator<<(ostream& os, const NewString& right); // << 연산자
private:
    char* m_name;
    int m_nameLen;
};

ostream& operator<<(ostream& os, const NewString& temp) // << 연산자
{
    cout << temp.m_name << " " << &(temp.m_name) << " " << (int*)(temp.m_name);
    return os;
}

int main() 
{
    // Specialty player1;
    // player1.Initialize();
    // Specialty player2;
    // player2.Initialize();
    // player2.Move(2, 3);

    // player1.Print();
    // player2.Print();

    // Specialty::InitSpawnCount();
    // player1.Print();
    // player2.Print();

    // Specialty* ptr = &player1;
    // ptr->Move(1,2);
    // ptr->Print();

    NewString lion("lion"); // char* 생성자
    // NewString tiger(lion); // 복사 생성자
    // tiger = lion; // 복사 대입 연산자
    
    // cout << empty << endl;
    // cout << lion << endl;
    // cout << cat << endl;
    // cout << tiger << endl;

    cout << lion << endl;
    cout << ++lion << endl;
    cout << lion-- << endl;
    cout << lion << endl;
}
// 출력 결과
// Total : 2       Pos : 0,        0
// Total : 2       Pos : 2,        3
// spawnCount Initalized
// Total : 0       Pos : 0,        0
// Total : 0       Pos : 2,        3
//  0x16bc2f260 0x156606b00
// lion 0x16bc2f250 0x156606a70
// lion 0x16bc2f230 0x156606a80
// lion 0x16bc2f220 0x156606a90

// 출력 결과
// lion 0x16b327260 0x11d606b00
// lion 0x16b327250 0x11d606b00
// dion 0x16b327260 0x11d606b00
// dion 0x16b327250 0x11d606b00

// 출력 결과
// lion 0x16ce2f260 0x127e06b00
// lion 0x16ce2f240 0x127e06a70
// lio 0x16ce2f260 0x127e06a80
// li 0x16ce2f260 0x127e06b00

// lion 0x16b24b260 0x123f04100
// lion! 0x16b24b260 0x123f04110
// lion! 0x16b24b240 0x123f04100
// lion 0x16b24b260 0x123f04120