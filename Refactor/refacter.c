#include <stdio.h>
#include <stdlib.h>
#include <string.h>




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