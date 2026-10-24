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

	printf("%d %d", b,d);




	return 0;
}