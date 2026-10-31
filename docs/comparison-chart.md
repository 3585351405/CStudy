# 📋 C 语言学习对比与参考表

快速查询常用函数、概念和最佳实践。

## 一、数据类型对比表

| 类型 | 大小 | 范围 | 用途 |
|------|------|------|------|
| `char` | 1 字节 | -128 ~ 127 | 单字符、小整数 |
| `short` | 2 字节 | -32,768 ~ 32,767 | 中等整数 |
| `int` | 4 字节 | -2,147,483,648 ~ 2,147,483,647 | 通用整数（推荐） |
| `long` | 4 字节 | 同 int（系统相关） | 大整数 |
| `long long` | 8 字节 | -9,223,372,036,854,775,808 ~ ... | 超大整数 |
| `float` | 4 字节 | 单精度（~7位数字） | 单精度浮点 |
| `double` | 8 字节 | 双精度（~15位数字） | 双精度浮点（推荐） |

## 二、字符串函数快速参考

### 标准库函数

| 函数 | 声明 | 说明 |
|------|------|------|
| `strlen` | `size_t strlen(const char* s)` | 字符串长度 |
| `strcpy` | `char* strcpy(char* d, const char* s)` | 复制（危险，无检查大小） |
| `strncpy` | `char* strncpy(char* d, const char* s, size_t n)` | 安全复制 |
| `strcat` | `char* strcat(char* d, const char* s)` | 连接字符串 |
| `strcmp` | `int strcmp(const char* s1, const char* s2)` | 比较字符串 |
| `strncmp` | `int strncmp(const char* s1, const char* s2, size_t n)` | 比较前 n 个字符 |
| `strchr` | `char* strchr(const char* s, int c)` | 查找字符 |
| `strstr` | `char* strstr(const char* h, const char* n)` | 查找子字符串 |

## 三、内存函数参考

| 函数 | 声明 | 说明 |
|------|------|------|
| `malloc` | `void* malloc(size_t size)` | 分配未初始化内存 |
| `calloc` | `void* calloc(size_t n, size_t size)` | 分配初始化为0的内存 |
| `realloc` | `void* realloc(void* ptr, size_t size)` | 调整内存大小 |
| `free` | `void free(void* ptr)` | 释放内存 |
| `memcpy` | `void* memcpy(void*d, const void*s, size_t n)` | 复制内存块 |
| `memset` | `void* memset(void* p, int v, size_t n)` | 填充内存块 |
| `memmove` | `void* memmove(void*d, const void*s, size_t n)` | 移动内存（支持重叠） |

## 四、指针常见组合

| 声明 | 读法 | 含义 |
|------|------|------|
| `int* p` | p是指向int的指针 | 指针和数据都可变 |
| `const int* p` | p是指向const int的指针 | 数据const，指针可变 |
| `int* const p` | p是const指针，指向int | 指针const，数据可变 |
| `const int* const p` | p是const指针，指向const int | 都是const |
| `int** p` | p是指向(int*)的指针 | 二级指针 |
| `int* arr[5]` | arr是5个(int*)的数组 | 指针数组 |
| `int (*p)[5]` | p是指向(int[5])的指针 | 数组指针 |
| `int (*f)(int, int)` | f是指向函数的指针 | 函数指针 |

## 五、运算符优先级（高到低）

| 优先级 | 运算符 | 含义 |
|--------|--------|------|
| 1 | `() [] . ->` | 括号、数组、成员访问 |
| 2 | `! ~ + - * & sizeof` | 逻辑非、位非、正负号、解引用、取地址、大小 |
| 3 | `* / %` | 乘、除、求模 |
| 4 | `+ -` | 加、减 |
| 5 | `<< >>` | 位移 |
| 6 | `< <= > >=` | 关系运算 |
| 7 | `== !=` | 相等运算 |
| 8 | `&` | 位与 |
| 9 | `^` | 位异或 |
| 10 | `\|` | 位或 |
| 11 | `&&` | 逻辑与 |
| 12 | `\|\|` | 逻辑或 |
| 13 | `?:` | 三元运算 |
| 14 | `= += -= *= /= %=` | 赋值运算 |

## 六、宏定义常见模式

```c
// 常量宏
#define PI 3.14159
#define MAX_SIZE 100

// 函数宏（函数式宏）
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SWAP(a, b) { int t = a; a = b; b = t; }
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 条件编译
#ifdef DEBUG
	#define LOG(x) printf("DEBUG: %s\n", x)
#else
	#define LOG(x)
#endif

// 字符串化
#define STRINGIFY(x) #x

// Token 连接
#define CONCAT(a, b) a##b
```

## 七、文件 I/O 模式一览

| 模式 | 说明 |
|------|------|
| `"r"` | 只读（文件必须存在） |
| `"w"` | 只写（覆盖） |
| `"a"` | 追加 |
| `"r+"` | 读写（文件必须存在） |
| `"w+"` | 读写（覆盖） |
| `"a+"` | 读写（追加） |
| `"rb"` | 二进制只读 |
| `"wb"` | 二进制只写 |
| `"ab"` | 二进制追加 |

## 八、错误检查清单

### malloc 后检查
```c
int* p = (int*)malloc(size);
if (p == NULL) {
	perror("malloc failed");
	exit(1);
}
```

### 文件操作后检查
```c
FILE* fp = fopen(filename, "r");
if (fp == NULL) {
	perror("fopen failed");
	exit(1);
}
// ... 使用文件
fclose(fp);
```

### 函数返回值检查
```c
int result = some_function();
if (result < 0) {  // 检查错误值
	// 处理错误
}
```

### 指针使用前检查
```c
if (ptr != NULL) {
	// 安全使用指针
	printf("%d\n", *ptr);
}
```

## 九、常见陷阱速记

| 陷阱 | 症状 | 解决方案 |
|------|------|---------|
| 内存泄漏 | 程序占用内存越来越多 | malloc后必须free |
| 悬空指针 | 访问已释放的内存 | free后设置为NULL |
| 缓冲区溢出 | 程序崩溃或数据损坏 | 使用strncpy而非strcpy |
| Double free | 程序崩溃 | free前检查，free后设NULL |
| 字符串未结尾 | 字符串操作异常 | 确保'\0' |
| 宏参数括号 | 计算错误 | 宏参数和结果都要括号 |
| 指针大小混淆 | 内存溢出 | 使用 sizeof正确计算 |
| 浮点数比较 | 比较总是错 | 使用误差范围比较 |

## 十、最佳实践速记

### 命名规范
- **常量**：全大写 `MAX_SIZE`
- **函数**：驼峰式 `calculate_score()`
- **变量**：驼峰式 `user_count`
- **宏**：全大写 `BUFFER_SIZE`

### 内存管理
```c
// ✅ 正确模式
int* data = (int*)malloc(size);
if (data == NULL) exit(1);
// 使用 data
free(data);
data = NULL;
```

### 字符串处理
```c
// ❌ 危险
strcpy(buffer, str);

// ✅ 安全
strncpy(buffer, str, sizeof(buffer) - 1);
buffer[sizeof(buffer) - 1] = '\0';
```

### 文件操作
```c
// ✅ 正确模式
FILE* fp = fopen(filename, mode);
if (fp == NULL) { handle_error(); }
// 使用文件
fclose(fp);
```

### 指针初始化
```c
int* p = NULL;      // 初始化为 NULL
if (p != NULL) {
	// 使用指针
}
```

## 十一、快速问题排查

### Q: 程序崩溃了
**检查清单**：
- [ ] 指针是否初始化？
- [ ] 超出数组边界？
- [ ] 使用了已释放的内存？
- [ ] scanf/strcpy/strcat 真的检查了大小？

### Q: 为什么计算结果错了
**检查清单**：
- [ ] 整数溢出？
- [ ] 浮点数精度问题？
- [ ] 宏定义参数没括号？
- [ ] 运算符优先级问题？

### Q: 程序内存占用在增长
**检查清单**：
- [ ] malloc 后 free 了吗？
- [ ] 循环中反复 malloc？
- [ ] 使用 valgrind 检测

### Q: 字符串操作有问题
**检查清单**：
- [ ] 字符串以 '\0' 结尾吗？
- [ ] 缓冲区大小够吗？
- [ ] 用对了 strcpy/strncpy？

---

**更新**：2024年

