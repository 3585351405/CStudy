#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int* Fun1() {
	int* ptr = malloc(5 * sizeof(int));
	if (ptr == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	else {
		for (size_t i = 0; i < 5; i++)
		{
			ptr[i] = i + 1;
		}
		return ptr;
	}

}

int main() {
	int arry[5] = { 0 };

	int* ptr = Fun1();

	for (size_t i = 0; i < 5; i++)
	{
		arry[i] = ptr[i];
		printf("%d\n", arry[i]);
	}
	

	

	return 0;
}