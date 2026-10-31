#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50;

int Fun3(int a, int b) {

	return a + b;

}


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

	

	







	//中文编程   


	typedef struct 动物 {
		整型 age;



	} 动物 ,* 动物1;


	//动物 狗 = { 1 };

	//动物1 狗2 = &狗;


	////函数指针

	// typedef int (*函数指针) (整型, 整型);

	// //此时point就相当于定义上一条件的所有类别；
	// 
	// 
	// 函数指针 加法 = Fun3;



	 //加法(11,12);



	 //打开文件
	
	 SetConsoleCP(65001);
	 SetConsoleOutputCP(65001);

	 FILE* Pfile = NULL;

	 int  error = fopen_s(&Pfile,"D:\\haker\\123.txt", "r,ccs=UTF-8");
	 printf("\n%d\n", error);

	 //printf("\n%p\n", f);


	


	 if(error == 0){ 
		 //fseek(Pfile, 0, SEEK_SET);
		 //wchar_t file[256] = { 0 };
		 //while ((fgetws(file, 256, Pfile)) != NULL) {

			// wprintf(L"%s", file);  
		 //}

		 //int file[] = { 10,20,30 };


		 //int* file1 = file;

		 //fprintf(Pfile, "%d %d %d", file[0], file[1], file[2]);
		 //fseek(Pfile, 0, SEEK_END);
		 //long filesize = ftell(Pfile);
		 //fseek(Pfile, 0, SEEK_SET);
		 //


		 //char * Pbuffer = malloc(filesize);
		 //if (Pbuffer  == NULL) {
			// exit ;
		 //}
		 //memset(Pbuffer, 0, filesize+10);

		 //fread(Pbuffer, filesize, 1, Pfile); //读取数据

		 //printf("%s", Pbuffer);


		 
		 
			 
			
			//int ch = 0;
			//printf("\n");
			//while ((ch = fgetc(Pfile)) != EOF) {
			// printf("%c", ch);
			//}

			//fseek(Pfile, 0, SEEK_SET);   //将指针修正到文件头部分

			//char pointer[256] = { 0 };
			//printf("\n");
			//while (fgets(pointer, 256, Pfile) != NULL) {
			//    printf("%s", pointer);
			//}
		    //   fclose(Pfile); 
	 
	 }

	 else if (error != 0) {
		 printf("打开文件失败");
	 }
	 




	



	



	return 0;
}