# 💾 第二模块：内存管理与动态分配

本模块深入讲解 C 语言的内存管理，是写出健壮代码的基础。

## 📚 文件清单

| 文件 | 主要内容 | 难度 |
|------|--------|------|
| `memory-allocation.c` | malloc/calloc/realloc/free | ⭐⭐ |
| `memory-operations.c` | memcpy/memset/memmove | ⭐⭐ |

## 🎯 学习目标

1. ✅ 理解堆和栈的区别
2. ✅ 掌握动态内存分配的四种方式
3. ✅ 学会正确使用内存操作函数
4. ✅ 避免内存泄漏和悬空指针问题

## 🔑 核心概念

### 1. 内存布局
```
┌─────────────────────┐
│   高地址 (栈)       │
│   临时局部变量      │
├─────────────────────┤
│                     │
│   未使用空间        │
│                     │
├─────────────────────┤
│   低地址 (堆)       │
│   动态分配的内存    │
└─────────────────────┘
```

**栈**（Stack）：
- 自动分配和释放
- 空间有限（通常几 MB）
- 速度快
- 用于存储局部变量

**堆**（Heap）：
- 手动分配和释放
- 空间大（可达 GB 级）
- 速度较慢
- 用于存储动态数据

### 2. 四大内存函数

#### malloc - 分配未初始化的内存
```c
void* malloc(size_t size);

// 使用例
int* arr = (int*)malloc(10 * sizeof(int));
if (arr == NULL) {
	printf("内存分配失败\\n");
	exit(1);
}
// 使用...
free(arr);
```

#### calloc - 分配初始化为 0 的内存
```c
void* calloc(size_t num_elements, size_t element_size);

// 使用例
int* arr = (int*)calloc(10, sizeof(int));  // 所有元素为 0
// 使用...
free(arr);
```

#### realloc - 调整已分配内存的大小
```c
void* realloc(void* ptr, size_t new_size);

// 使用例
int* arr = (int*)malloc(5 * sizeof(int));
arr = (int*)realloc(arr, 10 * sizeof(int));  // 扩展到 10 个元素
// 使用...
free(arr);
```

#### free - 释放动态分配的内存
```c
void free(void* ptr);

// 正确用法
int* arr = (int*)malloc(10 * sizeof(int));
free(arr);
arr = NULL;  // 避免悬空指针

// 错误用法 - 不要重复释放（double free）
free(arr);
free(arr);   // ❌ 错误！

// 空指针可以安全地释放
free(NULL);  // ✅ 安全
```

### 3. 内存操作函数

#### memcpy - 复制内存块
```c
void* memcpy(void* dest, const void* src, size_t n);

// 使用例
int src[5] = {1, 2, 3, 4, 5};
int dest[5];
memcpy(dest, src, 5 * sizeof(int));  // 复制 5 个整数

// ⚠️ 不要用于重叠的内存区域
```

#### memset - 填充内存块
```c
void* memset(void* ptr, int value, size_t n);

// 使用例
char buffer[100];
memset(buffer, 0, 100);           // 全部清零
memset(buffer, 'A', 10);           // 前 10 字节设为 'A'

// 常见用法
int arr[10];
memset(arr, 0, sizeof(arr));      // 数组清零
```

#### memmove - 移动内存块（支持重叠）
```c
void* memmove(void* dest, const void* src, size_t n);

// 使用例 - 处理重叠情况
char str[10] = "hello";
memmove(str + 1, str, 5);         // 移动重叠数据是安全的
```

## ⚠️ 常见问题与陷阱

### 陷阱 1：内存泄漏
```c
// ❌ 错误：分配后没有释放
void bad_function() {
	int* p = (int*)malloc(100 * sizeof(int));
	// ... 使用 p
	return;  // 忘记释放！内存泄漏
}

// ✅ 正确
void good_function() {
	int* p = (int*)malloc(100 * sizeof(int));
	// ... 使用 p
	free(p);
	p = NULL;
}
```

### 陷阱 2：悬空指针
```c
// ❌ 错误：释放后继续使用
int* p = (int*)malloc(10 * sizeof(int));
free(p);
*p = 5;  // ❌ 悬空指针，行为未定义！

// ✅ 正确
int* p = (int*)malloc(10 * sizeof(int));
free(p);
p = NULL;  // 设为 NULL，避免悬空
```

### 陷阱 3：重复释放（Double Free）
```c
// ❌ 错误：重复释放
int* p = (int*)malloc(10 * sizeof(int));
free(p);
free(p);   // ❌ 错误！

// ✅ 正确
int* p = (int*)malloc(10 * sizeof(int));
free(p);
p = NULL;  // 现在可以安全释放 NULL
free(p);   // ✅ 安全（free(NULL) 无操作）
```

### 陷阱 4：malloc 返回值检查
```c
// ❌ 危险：不检查返回值
int* p = (int*)malloc(1000 * sizeof(int));
p[0] = 10;  // ❌ 如果 malloc 失败返回 NULL，这里会崩溃

// ✅ 安全：总是检查
int* p = (int*)malloc(1000 * sizeof(int));
if (p == NULL) {
	printf("内存分配失败\\n");
	exit(1);
}
p[0] = 10;  // ✅ 现在安全
```

### 陷阱 5：指针大小混淆
```c
// ❌ 容易出错
int* p = (int*)malloc(10);      // 只分配 10 字节！
p[0] = 1;
p[1] = 2;  // ❌ 可能越界

// ✅ 正确
int* p = (int*)malloc(10 * sizeof(int));  // 分配 40 字节
p[0] = 1;
p[1] = 2;  // ✅ 安全
```

## 💡 最佳实践

### 1. 分配内存后立即检查
```c
int* p = (int*)malloc(size);
if (p == NULL) {
	perror("malloc failed");
	exit(EXIT_FAILURE);
}
```

### 2. 使用 sizeof 计算大小
```c
// ✅ 好的做法
int* arr = (int*)malloc(10 * sizeof(int));

// ❌ 不好的做法
int* arr = (int*)malloc(40);  // 如果改为 long，就错了
```

### 3. 及时释放内存
```c
// 在函数末尾统一释放
int* data = (int*)malloc(...);
// ... 处理数据
free(data);
data = NULL;
return;
```

### 4. 使用 valgrind 检测内存问题
```bash
gcc -g -o program program.c
valgrind --leak-check=full ./program
```

### 5. 考虑使用 malloc/free 的替代方案
- 栈分配（静态数组）- 更简单快速
- VLA（变长数组） - C99 标准
- 对象池 - 预分配内存

## 🎓 学习方法

### 编译和运行
```bash
gcc -o memory memory-allocation.c
./memory

gcc -o ops memory-operations.c
./ops
```

### 验证没有内存泄漏
```bash
# Linux/Mac
gcc -g -o memory memory-allocation.c
valgrind --leak-check=full ./memory

# Windows（使用 Dr. Memory）
drmemory.exe ./memory.exe
```

## 🧪 练习

### 练习 1：动态数组
创建一个动态整数数组，读入 N 个数字，打印它们，然后释放内存。

### 练习 2：字符串复制
使用 malloc 实现一个 `string_copy` 函数，动态分配内存存储字符串副本。

### 练习 3：二维数组
使用 malloc 创建一个 M × N 的动态二维数组。

### 练习 4：内存检测
写一个程序故意产生内存泄漏，然后用 valgrind 检测。

## 📊 malloc vs calloc 对比

| 特性 | malloc | calloc |
|------|--------|--------|
| 初始化 | 未初始化，随机值 | 初始化为 0 |
| 参数 | 总字节数 | 元素数量 × 大小 |
| 效率 | 更快 | 稍慢（多初始化步骤） |
| 用途 | 已知大小，将初始化 | 需要清零数据 |

## 🎯 自测检查

完成本模块后，你应该能够：

- [ ] 说出栈和堆的区别
- [ ] 正确使用 malloc/calloc/realloc/free
- [ ] 理解什么是内存泄漏和悬空指针
- [ ] 使用 memcpy/memset/memmove
- [ ] 检测和调试内存问题

---

**下一步**：进入**第三模块：指针（最重要！）** 🎯
