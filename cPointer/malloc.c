#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "malloc.h"


int* HeapRequest(int size) {
	int* p = (int*)malloc(size * sizeof(int)); // 动态分配内存
	if (p == NULL) {
		printf("内存分配失败！\n");
		exit(1);
	}
	else if (p != NULL) {

		for (size_t i = 0; i < size; i++)
		{
			p[i] = i + 1; // 初始化数组元素
		}
		return p;
	}
}