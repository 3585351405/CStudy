#include <stdio.h>
#include <stdlib.h>




//sizeof 重构

#define MySizeOf(x)  ( (char*)(&x + 1) - (char*)(&x) )
int main() {
	//sizeof

	int a = 1;

	char c = 'c';

	int b = MySizeOf(a);

	int d = MySizeOf(c);

	printf("%d %d \n", b,d);


	int n_count = Mystrlen("Hello");

	printf("%d  \n ", n_count);







	return 0;
}