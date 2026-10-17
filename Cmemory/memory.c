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


//realloc() 函数用于重新分配内存块的大小。它可以用来调整之前分配的内存块的大小，而不需要释放原来的内存块并重新分配新的内存块。
//void* realloc(void* ptr, size_t new_size);



// free() 函数用于释放之前分配的内存块。它将内存块标记为可用，以便后续的内存分配可以使用该内存块。


//calloc() 函数用于动态分配内存，并将分配的内存初始化为零。它接受两个参数：要分配的元素数量和每个元素的大小（以字节为单位）。calloc() 返回一个指向分配内存块的指针，如果分配失败，则返回 NULL。
//void* calloc(size_t num_elements, size_t element_size);
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