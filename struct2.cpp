#include <iostream>
using namespace std;

struct test1
{
    char c;
    long long i;
    char d;
};

struct test2
{
    long long i;
    char c;
    char d;
};

int main()
{
    cout << sizeof(char) << endl;
    cout << sizeof(long long) << endl;
    cout << sizeof(test1) << endl;
    cout << sizeof(test2) << endl;
}
// 출력 결과
// 1
// 8
// 24
// 16