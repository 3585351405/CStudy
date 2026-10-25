#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50;




//联合体


union person {
	char a ;
	short age;
	int score;



};
//联合体的特性：  整个联合体公用同个内存   整个内存取决于其中最大的变量类型所占的空间
//enum 枚举变量


enum THREAD_STATE {
	THREAD_EXIT,
	THREAD_RUNNING,



	//声明常量   且后面往后递增一       整数   方便维护
	



};


//strcmp 重构

int Mystrcmp(const char* str1,const char* str2){
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}

		str1++;
		str2++;
	}

	return *str1 - *str2;

}



//sizeof 重构


//strlen重构


int Mystrlen(const char* string) {
	int n_count = 0;
	for (;*string != '\0'; *string++)
	{
		n_count++;
	}
	return n_count;
}

#define MySizeOf(x)  ( (char*)(&x + 1) - (char*)(&x) )


//strcat重构


char* Mystrcat(char* str1 , char* str2) {

	char* mem = str1;
	while (*mem != '\0') {
		mem++;



	}
	while (*str2 != '\0') {
		*mem = *str2;
		str2++;
		mem++;
	}
	*mem = '\0';

	return str1;



}



int main() {
	//sizeof

	int a = 1;

	char c = 'c';

	int b = MySizeOf(a);

	int d = MySizeOf(c);

	printf("%d %d \n", b,d);


	int n_count = Mystrlen("Hello");

	printf("%d  \n ", n_count);


	int h = Mystrcmp("Hello", "AP");
	printf("cmp %d \n", h);


	char arry1[50] = "hello";

	char arry2[50] = "hello1";

	char* arry3 = Mystrcat(arry1, arry2);

	printf("%s", arry3);
	
	union person p1;
	p1.a = 65;
	p1.age = 1;
	p1.score = 65;



	//别名定义：  typedef    数据类型  别名

	typedef    int     整型;



	整型 血量 = 11111;








	return 0;
}