#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// 자료구조 (데이터를 저장하는 구조)
// 알고리즘 (데이터를 어떻게 사용할 것인가?)
// 알고리즘은 50가지 정도로 많지만 아래 정도만 알면 됨
// find
// find_if
// count
// count_if
// all_of
// any_of
// none_of
// for_each
// remove
// remove_if

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);

    int number = 10;

    // find
    {
        vector<int>::iterator itFind = find(v.begin(), v.end(), number);
        if (itFind == v.end())
        {
            // 못 찾음
            cout << "못 찾았음" << endl;
        }
        else
        {
            // 찾음
            cout << "찾았음" << endl;
        }

        // find_if
        struct CanDivideBy11
        {
            bool operator()(int n)
            {
                return (n % 11) == 0;
            }
        };
        
        vector<int>::iterator itFind2 = find_if(v.begin(), v.end(), CanDivideBy11());
        // vector<int>::iterator itFind3 = find_if(v.begin(), v.end(), [](int n) { return (n % 11) == 0; }); // 람다식
    }

    struct  IsOdd
    {
        bool operator()(int n)
        {
            return n % 2 != 0;
        }
    };

    // count
    // count_if
    {
        int n = count_if(v.begin(), v.end(), IsOdd());
        cout << n << endl;;
    }
    
    // all_of 모든 데이터가 조건과 부합하냐
    {
        bool b1 = all_of(v.begin(), v.end(), IsOdd());
        // any_of 전체 데이터 중 하나라도 조건과 부합하냐
        bool b2 = any_of(v.begin(), v.end(), IsOdd());
        // none_of 모든 데이터가 조건과 부합하지 않느냐
        bool b3 = none_of(v.begin(), v.end(), IsOdd());
        cout << b1 << " " << b2 << " " << b3 << endl;;
    }

    // for_each
    {
        struct  MultiplyBy3
        {
            void Operator(int& n)
            {
                n = n * 3;
                cout << n << endl;
            }
        };
        
        for_each(v.begin(), v.end(), MultiplyBy3());
    }

    // 중요!
    // remove
    remove(v.begin(), v.end(), 4);
    // remove_if 는 날려야하는 애들의 위치를 반환함
    vector<int>::iterator it = remove_if(v.begin(), v.end(), IsOdd());
    // 날려야하는 애들을 아래를 사용하여 삭제
    v.erase(it, v.end());

    return 0;
}