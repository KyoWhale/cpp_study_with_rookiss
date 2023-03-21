#include <iostream>
using namespace std;

struct student
{
    string name;
	int classNum;
	int number;
	float height;
	float weight;
};

student GetStudent()
{
    return {"name",1,1,1,1};
}

int main()
{
    student student1 = {"김철수", 1, 1, 175, 60.5};
    student student2 = {"이영희", 2, 10, 154};
    student s3;
    s3.name = "박덕철";
    s3.classNum = 3;
    s3.number = 5;
    s3.height = 183;
    s3.weight = 80;
    struct student s4; // 키워드 struct를 붙일 수도 있음

    student s5 = {"S5",1,1,1,1}, // 여러 개의 변수를 한 번에 선언하며 초기화할 수 있음
            s6 = {"S6",1,1,1,1};
    
    student s7 {"S7",1,1,1,1}, // 대입연산자를 빼고 초기화할 수 있음
            s8 {"S8",1,1,1,1};

    // 구조체의 값 대입
    s3 = s5;
    // 위의 대입 연산은 아래와 같이 하나씩 작업이 이루어짐
    s3.name = s5.name;
    s3.classNum = s5.classNum;
    s3.number = s5.number;
    s3.height = s5.height;
    s3.weight = s5.weight;
}