#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


////定义结构体
//
//struct person
//{
//	char name[50];
//	int age;
//	float height;
//	int score;
//
//}p3;


int main() {
	////访问结构体，定义内部成员变量
	//struct person p1 = {0};
	//strcpy(p1.name, "张三");
	//p1.age = 20;
	//p1.height = 175.5;
	//p1.score = 85;

	////方式二
	//struct person p2 = { "李四", 22, 180.2, 90 };

	////方式三
	//p3.age = 25;
	//p3.height = 185.0;
	//p3.score = 95;
	//strcpy(p3.name, "王五");





	//定义结构体

	struct person{
		char name[50];
		int age;
		int score;
	};



	//初始化结构体数组


	struct  person people[3] = { 0 };


	//遍历结构体数组，输入数据


	for (int i = 0; i < sizeof(people) / sizeof(people[0]); i++) {


		printf("请输入第%d个人的姓名：",i + 1);
		scanf("%s", people[i].name);
		printf("请输入第%d个人的年龄：", i + 1);
		scanf("%d", &people[i].age);
		printf("请输入第%d个人的成绩：", i + 1);
		scanf("%d", &people[i].score);
		
	}



	//遍历结构体数组，输出数据
	for (int i = 0; i < sizeof(people) / sizeof(people[0]); i++) {
		printf("第%d个人的姓名：%s\n", i + 1, people[i].name);
		printf("第%d个人的年龄：%d\n", i + 1, people[i].age);
		printf("第%d个人的成绩：%d\n", i + 1, people[i].score);
	}





	return 0;
}
