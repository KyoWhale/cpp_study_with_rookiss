#include <iostream>
using namespace std;

// 배열은 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환함 (char[] -> char* )
// 배열 내용의 전체를 넘기는 것이 아닌 배열의 시작 주소(포인터)만 넘김
void Test(char a[])
{
    a[0] = 'x';
}

int main()
{
    cout << "Hello World" << endl; // const char[12]
    char msg[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // char[6]
    cout << msg << endl;

    // const char
    const char* test1 = "Hello World";
    // char []
    char test2[] = "Hello World";

    // test1은 .data 영역에 배열형태로 저장되어 있음
    // readonly 이기 때문에 수정이 불가능함
    // test2는 .data 의 영역에 저장되어 있는 test1의 값을 4바이트씩 복사하여 초기화됨
    // 각 인덱스에 접근해서 값을 수정할 수 있음
    test2[0] = 'D';
    // Dello World가 됨

    // 포인터는 주소를 담는 바구니
    // 배열은 '닭장'. 즉, 같은 데이터끼리 붙어있는 바구니
    // 배열 이름은 바구니 모음의 '시작 주소'

    // 함수에 인자로 배열을 넘길 때
    // 일반 자료형은 지역변수의 값이 바뀌기에 원본은 안 바뀌지만, 배열은 주소에 찾아가서 원본을 바꿈
    cout << test2 << endl;
    Test(test2);
    cout << test2 << endl;
    
    return 0;
}