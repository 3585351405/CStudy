#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <io.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>




/* 注意：printf 使用示例应为 printf("%d", num); 当前文件保留原有代码风格，仅修复 scanf 报错 */
//常量与变量不同 永恒不变
//const 数据类型 常量名 = 常量值     常量修饰
//#define 常量名 常量值      宏常量

int main() {



	//scanf("%d",&num);  //这里与python不同，第一个参数是接收的数据，第二个参数的&是寻址内存，从而替换num的值
	//printf("%d", num);
	//printf("Size of short: %lu bytes\n", sizeof(short));
	//printf("Size of int: %lu bytes\n", sizeof(int));
	//printf("Size of long: %lu bytes\n", sizeof(long));
	//double a = 3.14159265358979323846;
	//printf("%.10lf", a);
	/*bool isTrue = true;
	if (isTrue) {
		printf("The value is true.\n");
	}
	else {
		printf("The value is false.\n");
	}*/

	//True 为 1，False 为 0，bool所占大小为1字节
	//字符类型的大小为1字节，只能填写一个字符，若填写多个字符，则只取第一个字符，计算机是将字符转换为ASCII码进行存储的
	//int a = 10;
	//printf("%d\n", (int)(a/2.0));



	//运算符
	//正数
	//int a = +10;
	//负数
	//int b = -10;
	//加法
	//int c = a + b;
	//减法
	//int d = a - b;
	//乘法
	//int e = a * b;
	//除法
	//int f = a / b;
	//取模代表求余数
	//前置递增
	//先求和再赋值
	//后置相反
	//int a = 10;
	//a += 5; // a = a + 5
	//a -= 5; // a = a - 5
	//a *= 5; // a = a * 5
	//a /= 5; // a = a / 5
	//a %= 5; // a = a % 5
	//逻辑运算
	//! 取反
	//&& 与
	//|| 或




	//选择结构
	//三目运算符
	//语法：表达式1？表达式2：表达式3
	//如果表达式1为真，则执行表达式2，否则执行表达式3
	//int a = 1?5:10;
	//printf("%d", a);

	//网吧上网
	//int age;
	//printf("请输入年龄：");
	//scanf("%d", &age);
	//if (age >= 18) {
	//	printf("可以上网\n");
	//}
	//else {
	//	printf("不可以上网\n");
	//}

	//成绩与分数
	//int score = 0;
	//printf("请输入你的成绩：");
	//scanf("%d", &score);

	//switch (score) {
	//    case 'A'://这里的'A'是一个字符常量，表示字符A的ASCII码值，而不是成绩的数值。
	//		break;
	//	case 'B':
	//		printf("优秀！\n");
	//		break;
	//	case 'C':
	//		printf("良好！\n");
	//		break;
	//	case 'D':
	//		printf("及格！\n");
	//		break;
	//	default:
	//		printf("不及格！\n");
	//}


	//int a = 0;
	//while (a < 1000) {
	//	printf("  %d \r\n", a);
	//	a++;
	//      
	// do while 的特性
	// 先执行一次循环体，再判断条件是否成立，如果成立则继续执行循环体，否则退出循环
	//例如:
	//int a = 0;
	//do {} while (a < 1000);
	//for （起始表达式；条件表达式；末尾表达式）{code} 1.执行1->起始表达式
													   //2.执行2->条件表达式
													   //3. 执行3->循环语句
													   //4.执行4->末尾循环体
 //   srand(time(NULL)); //置随机数种子
	//int num = rand() % 100;



	////猜数字游戏
	//for (int i = 0; i < 10; i++) {
	//	int eTemp = 0;
	//	printf("请输入0到100之间的整数：");
	//	scanf("%d", &eTemp);
	//	if (eTemp == num) {
	//		printf("恭喜你，猜对了！\n");
	//		break;
	//	}
	//	else if (eTemp < num) {
	//		printf("太小了，请再试一次。\n");
	//	}
	//	else {
	//		printf("太大了，请再试一次。\n");
	//	}
	//}
    
    //九九乘法表
	//for (int i = 1; i <= 9; i++) {
	//	for (int j = 1; j <= i; j++) {
	//		printf("%d*%d=%d ", j, i, i * j);
	//	}
	//	printf("\n");
	//}
	//goto语句
	//int a = 0;
    //label:
	//if (a < 10) {
	//	printf("%d\n", a);
	//	a++;
	//	goto label;
	//}
	//就可以循环了，goto灵活性很高，但是不建议使用，容易造成程序混乱，难以维护
 //   int Arry[11] = { 0 };
	//printf("Size of array: %lu bytes\n", sizeof(Arry));
    //拓展数组的特性 
	//数组的大小是固定的，不能动态改变
	//int Arry2[5] = { 1,2,3,4,5 };
	//printf("%p", &Arry2[0]);= //printf("%p", Arry2);  //数组名就是数组首元素的地址
    //二维数组存储的三个方式
    /*
	  1.int Arry2[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	  2. int Arry2[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	  3. int Arry2[3][4] = { {1,2},{5,6,7},{9,10,11,12} };  //未赋值的元素会被初始化为0
	  4. int Arry2[3][4] = { 0 };  //所有元素都被初始化为0
	  5.一个一个赋值
	  6. int Arry2[][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };  //不指定行数，编译器会根据初始化列表的元素个数自动计算行数
	  

	
	*/
    //字符串是需要一个结束标记 “\0”
 //   char arry3[] = { 'a','b','c','d','e','\0' };  
	//printf("%s", arry3);  //输出字符串)
  //   char arry4[] = "abcde";  //字符串的简写方式，编译器会自动在末尾添加结束标记“\0”


	 //// strlen()函数用于计算字符串的长度，不包括结束标记“\0”
	 ////strcpy(目标，源)函数用于复制字符串（覆盖掉目标数据），strcat()函数用于连接字符串（拼接在目标数据后），strcmp()函数用于比较字符串（当返回值不等于零时，则为不相等）
	 //char arry5[] = "hello";
	 //int cp = strcmp(arry4, arry5);
	 //printf("Comparison result: %d\n", cp);
  //   char buffer[] = { 0 };
	 //scanf("%s", buffer);  //读取字符串，遇到空格、换行符或制表符时停止读取,不需要加取地址符的原因是：数组名就是数组首元素的地址
	





    
    




    return 0;
}