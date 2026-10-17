#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cacl.h"
#include <stdarg.h>
#define ADD(a, b) ((a) + (b)) // 宏定义，计算两个数的和,可以节省大量汇编代码，快速


//int* modify(int* p) {
//	return p;
// }

//int MyPrintf(char* format, ...) {
//	va_list valist;
//	va_start(valist, format);
//	while (*format) {
//		if (*format == "%")
//		{
//			switch (*format) {
//				case 'd': {
//					int num = va_arg(valist, int);
//					printf("%d", num);
//					break;
//				}
//				case 's': {
//					char* str = va_arg(valist, char*);
//					printf("%s", str);
//					break;
//				}
//				
//
//
//			}
//		}
//		else {
//			putchar(*format);
//
//		}
//		format++;
//	}
//	va_end(valist);
//
//
//}





//int* Func() {
//	int* Arry = malloc(5 * sizeof(int)); // 动态分配内存
//	if (Arry == NULL) {
//		printf("内存分配失败！\n");
//		exit(1);
//	}
//
//	else if(Arry != NULL){
//	
//		for (size_t i = 0; i < 5; i++)
//		{
//			Arry[i] = i + 1;
//			printf("%d\n", Arry[i]);
//
//		}
//		free(Arry);
//	}
//
//	
//	
//}



int print(char* format, ...) {
	va_list valist;
	va_start(valist, format);

	while (1) {
		if (*format == '\0') {
			break;
		}
		if (*format == '%') {
			format++;
			switch (*format) {
			case 'd': {
				int num = va_arg(valist, int);
				printf("%d", num);
				break;
			}
			case 's': {
				char* str = va_arg(valist, char*);
				printf("%s", str);
				break;
			}
			case 'p': {
				void* ptr = va_arg(valist, void*);
				printf("%p", ptr);
				break;
			}
			}
		}
		else {
			putchar(*format);
		}
		format++;

	}
	va_end(valist);

}
struct person {
	int age;
	char name[20];

};
//int structPrint(struct person* pl) {
//	pl->age = 20;
//	strcpy(pl->name, "John");
//	printf("Name: %s\n", pl->name);
//	printf("Age: %d\n", pl->age);
//	return 0;
//}


void Fun1(struct person arry[]) {
	for (int i = 0; i < 3; i++) {
		printf("Name: %s\n", arry[i].name);
		printf("Age: %d\n", arry[i].age);
	}

}






int main() {
	

	//int a = 10;
	//int* p = &a; // 定义一个指针变量 p，指向 a 的地址

	//printf("%d\n", *p); // 解引用指针，输出 a 的值

	//int result = add(5, 3); // 调用函数
	//printf("%d\n", result); // 输出函数的返回值


	//int arr[5] = { 1, 2, 3, 4, 5 };

	//int* p = arr; // 指针指向数组的首元素
	////printf("%d\n", *(p + 1)); 

	////for (int i = 0; i < 5; i++)
	////{
	////	printf("%p\n", p+i);
	////}
	//printf("原始 --%p\n", p); // 输出指针的地址

	//int* ret = modify(p);
	//printf("%p\n", ret); // 传递指针给函数
	//int a = 0;
	//int b = 5418814588;
	//printf("请输入密钥证书：");
	//scanf("%d", &a);

	//


	//if (a == b) {
	//	printf("密钥证书正确，欢迎使用！\n");
	//}
	//else {
	//	printf("密钥证书错误，请重新输入！\n");
	//}


	//int a = ADD(5, 3); // 调用宏定义，计算两个数的和)

	//int* a = Func();
	print("Hello, %s! You have %d new messages.\n", "Alice", 6);




	//指针常量，指针指向的地址不能被修改，但指针本身的值可以被修改


	int a = 0;
	int* const ptr = &a; // 定义一个指针常量，指向 a 的地址
	*ptr = 10; // 修改指针指向的值

	//ptr = &b; // 错误，不能修改指针常量的值


	//常量指针，指针本身的值可以被修改，但指针指向的地址不能被修改

	int b = 20;
	const int* ptr2 = &b; // 定义一个常量指针，指向 b 的地址

	ptr2 = &a; // 修改指针的值，指向 a 的地址

	//*ptr2 = 30; // 错误，不能修改常量指针指向的值


	//指向常量的指针，指针本身的值不可以被修改，但指针指向的地址能被修改

	const int c = 30;
	const int* ptr3 = &c; // 定义一个指向常量的指针，指向 c 的地址

	ptr3 = &a;

	//错误， *ptr3 = 40; ; // 错误，不能修改指针指向的值


	//常量指针常量，指针本身的值和指针指向的地址都不能被修改

	const int d = 50;

	const int* const ptr4 = &d; // 定义一个常量指针常量，指向 d 的地址

	//ptr4 = &a; // 错误，不能修改指针常量的值
	//*ptr4 = 60; // 错误，不能修改常量指针指向的值
	short arry[5] = { 2,3,4,5,6 };
	short* ptr5 = arry; // 定义一个指针变量 ptr5，指向数组 arry 的首元素
	printf("First element: %d\n", *ptr5); // 输出第一个元素的值)
	
	printf("Second element: %d\n",(( *(ptr5+1) )) ); // 输出第二个元素的值)
	
	

	
	


	return 0;
}