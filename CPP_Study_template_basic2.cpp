#include <iostream>
using namespace std;

template<typename T, int SIZE> // 기본 매개변수 값 가능
class RandomBox
{
public:
    T GetRandomData()
    {
        int idx = rand() % SIZE;
        return _data[idx];
    }
public:
    T _data[SIZE];
};

// 템플릿 특수화
template<int SIZE>
class RandomBox<double, SIZE> // double에 대한 특수화인 것을 적어주어야함
{
public:
    double GetRandomData()
    {
        cout << "randomBox double" << endl;
        int idx = rand() % SIZE;
        return _data[idx];
    }
public:
    double _data[SIZE];
};

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    
    RandomBox<int, 10> rb1;
    for (int i = 0; i < 10; i++)
    {
        rb1._data[i] = i;
    }
    int value = rb1.GetRandomData();
    cout << value << endl;

    RandomBox<float, 20> rb2;
    for (int i = 0; i < 20; i++)
    {
        rb2._data[i] = i + 0.5f;
    }
    float value2 = rb2.GetRandomData();
    cout << value2 << endl;

    // RandomBox<int, 10> rb1;
    // RandomBox<int, 20> rb2; 위와 이것은 아예 다른 클래스임

    RandomBox<double, 20> rb3;
    for (int i = 0; i < 20; i++)
    {
        rb3._data[i] = i + 0.5f;
    }
    float value3 = rb3.GetRandomData();
    cout << value3 << endl;

    return 0;
}