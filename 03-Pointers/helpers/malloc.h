#ifndef MALLOC_H
#define MALLOC_H

/**
 * malloc.h - 内存分配函数声明
 */

/**
 * 向堆中申请指定大小的内存
 * @param size 要分配的元素个数
 * @return 指向分配内存的指针，失败返回 NULL
 */
int* HeapRequest(int size);

#endif  // MALLOC_H
