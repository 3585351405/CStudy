# 🔨 第五模块：代码优化与高级技巧

学到这里，你已经掌握了 C 语言的核心。本模块教会你如何写出更优雅、更高效的代码。

## 📚 文件清单

| 文件 | 主要内容 | 难度 |
|------|--------|------|
| `01-string-functions.c` | 手写 strcmp/strlen/strcat | ⭐⭐ |
| `02-macros.c` | 宏定义高级用法 | ⭐⭐ |
| `03-typedefs.c` | 复杂类型别名 | ⭐⭐ |
| `04-file-io.c` | 文件读写操作 | ⭐⭐⭐ |

## 🎯 学习目标

1. ✅ 理解标准库字符串函数的实现
2. ✅ 掌握宏定义的用法和陷阱
3. ✅ 学会使用 typedef 简化代码
4. ✅ 掌握文件 I/O 操作
5. ✅ 写出更高质量的代码

## 🔑 核心概念

### 01 字符串函数重构

#### strlen - 计算字符串长度
```c
// 标准库版本
#include <string.h>
int len = strlen("hello");  // 返回 5

// 手写版本
int my_strlen(const char* str) {
	int count = 0;
	while (*str != '\0') {
		count++;
		str++;
	}
	return count;
}

// 更简洁的版本
int my_strlen_v2(const char* str) {
	int count = 0;
	for (; *str != '\0'; str++) {
		count++;
	}
	return count;
}
```

#### strcmp - 比较字符串
```c
// 返回值
//  < 0: str1 < str2
//  = 0: str1 == str2
//  > 0: str1 > str2

int my_strcmp(const char* str1, const char* str2) {
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
```

#### strcpy - 复制字符串
```c
// 标准库版本
strcpy(dest, src);  // ⚠️ 危险：不检查大小

// 安全版本
strncpy(dest, src, size - 1);
dest[size - 1] = '\0';

// 手写版本
char* my_strcpy(char* dest, const char* src) {
	char* original_dest = dest;
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';  // 添加结束标记
	return original_dest;
}
```

#### strcat - 连接字符串
```c
// 手写版本
char* my_strcat(char* dest, const char* src) {
	char* original_dest = dest;

	// 移到 dest 的末尾
	while (*dest != '\0') {
		dest++;
	}

	// 复制 src
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return original_dest;
}
```

---

### 02 宏定义（#define）

#### 基本宏
```c
#define MAX_SIZE 100
#define PI 3.14159
#define ADD(a, b) ((a) + (b))
```

#### 函数式宏
```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))

int result = MAX(5, 10);  // 10
```

#### 宏的陷阱（必须了解！）

**陷阱 1：参数没有括号**
```c
// ❌ 危险
#define DOUBLE(x) x * 2

int result = DOUBLE(3 + 1);  // = 3 + 1 * 2 = 5（不是 8！）

// ✅ 正确
#define DOUBLE(x) ((x) * 2)

int result = DOUBLE(3 + 1);  // = (3 + 1) * 2 = 8
```

**陷阱 2：多次使用参数**
```c
// ❌ 危险
#define SQUARE(x) (x) * (x)

int i = 5;
int result = SQUARE(i++);  // i++ 被调用两次！

// ✅ 正确
#define SQUARE(x) ({ int _x = (x); _x * _x; })
```

**陷阱 3：缺少分号**
```c
// ❌ 危险
#define PRINT(x) printf("%d\n", x)

if (condition)
	PRINT(x);  // ❌ 缺少分号可能导致语法错误
else
	PRINT(y);

// ✅ 正确
#define PRINT(x) do { printf("%d\n", x); } while(0)
```

#### 条件编译
```c
#ifdef DEBUG
#define LOG(msg) printf("DEBUG: %s\n", msg)
#else
#define LOG(msg)  // 什么都不做
#endif

#if MAX_SIZE > 100
	static char buffer[MAX_SIZE];
#endif
```

#### stringify 和 token pasting
```c
// stringify - 转为字符串
#define STRINGIFY(x) #x

printf("%s\n", STRINGIFY(hello));  // 输出 "hello"

// token pasting - 连接符号
#define CONCAT(a, b) a##b

int hello_world = 10;
int result = CONCAT(hello_, world);  // = hello_world
```

---

### 03 typedef - 类型别名

#### 基本用法
```c
// 简化类型声明
typedef unsigned int uint;
typedef float real;

uint a = 10;
real b = 3.14;
```

#### 结构体别名
```c
// 普通方式
struct Person {
	char name[50];
	int age;
};
struct Person p;

// typedef 方式
typedef struct {
	char name[50];
	int age;
} Person;
Person p;  // 更简洁
```

#### 指针别名
```c
// ❌ 危险
typedef int* intptr;
intptr p1, p2;  // p1 是指针，但 p2 不是！因为 * 只作用于 p1

// ✅ 安全做法
typedef int * intptr;
intptr p1, p2;  // 都是指针

// 最佳做法：避免指针别名，显式写出
int* p1;
int* p2;
```

#### 函数指针别名
```c
// 复杂的函数指针  
int (*func)(int, int);

// 使用 typedef 简化
typedef int (*Comparator)(int, int);

Comparator cmp = some_comparison_function;
int result = cmp(5, 10);
```

---

### 04 文件 I/O 操作

#### 打开和关闭文件
```c
#include <stdio.h>

FILE* file = fopen("filename.txt", "r");  // 读
if (file == NULL) {
	perror("Cannot open file");
	return;
}

// 使用文件...

fclose(file);
```

#### 文件打开模式
| 模式 | 说明 |
|------|------|
| `"r"` | 只读 |
| `"w"` | 只写（覆盖） |
| `"a"` | 追加 |
| `"r+"` | 读写，文件必须存在 |
| `"w+"` | 读写，覆盖如存在 |
| `"a+"` | 读写，追加 |
| `"rb"` | 二进制读 |

#### 逐字符读写
```c
// 写入
FILE* fp = fopen("test.txt", "w");
fputc('A', fp);
fputs("Hello\n", fp);
fclose(fp);

// 读取
FILE* fp = fopen("test.txt", "r");
int c = fgetc(fp);  // 读一个字符
char line[100];
fgets(line, 100, fp);  // 读一行
fclose(fp);
```

#### 格式化读写
```c
FILE* fp = fopen("data.txt", "w");
fprintf(fp, "Name: %s, Age: %d\n", "Alice", 25);
fclose(fp);

FILE* fp = fopen("data.txt", "r");
char name[50];
int age;
fscanf(fp, "Name: %s, Age: %d", name, &age);
fclose(fp);
```

#### 文件指针定位
```c
FILE* fp = fopen("file.txt", "r");

fseek(fp, 0, SEEK_END);          // 移到末尾
long size = ftell(fp);            // 获取文件大小
fseek(fp, 0, SEEK_SET);          // 移到开头
rewind(fp);                        // 也是移到开头

fclose(fp);
```

#### 块读写（二进制）
```c
struct Data {
	int id;
	char name[50];
};

// 写入
FILE* fp = fopen("data.bin", "wb");
struct Data d = {1, "Alice"};
fwrite(&d, sizeof(struct Data), 1, fp);
fclose(fp);

// 读取
FILE* fp = fopen("data.bin", "rb");
struct Data d;
fread(&d, sizeof(struct Data), 1, fp);
fclose(fp);
```

---

## 💡 代码质量最佳实践

### 1. 使用有意义的名称
```c
// ❌ 难以理解
int calc(int x, int y) {
	return x * 2 + y / 3;
}

// ✅ 清楚
int calculate_adjusted_score(int base_score, int bonus) {
	return base_score * 2 + bonus / 3;
}
```

### 2. 函数要单一职责
```c
// ❌ 做太多事
void process_file(const char* filename) {
	// 打开文件
	// 读取数据
	// 验证数据
	// 处理数据
	// 写入结果
	// 关闭文件
}

// ✅ 职责单一
void read_file(const char* filename, Data* output);
void validate_data(const Data* data);
void process_data(Data* data);
void write_result(const char* filename, const Data* data);
```

### 3. 添加错误处理
```c
// ❌ 没有错误处理
FILE* fp = fopen(filename, "r");
fscanf(fp, "%d", &value);
fclose(fp);

// ✅ 有错误处理
FILE* fp = fopen(filename, "r");
if (fp == NULL) {
	fprintf(stderr, "Cannot open file: %s\n", strerror(errno));
	return -1;
}

if (fscanf(fp, "%d", &value) != 1) {
	fprintf(stderr, "Invalid data format\n");
	fclose(fp);
	return -1;
}

fclose(fp);
return 0;
```

### 4. 使用常量避免魔术数字
```c
// ❌ 魔术数字
if (score >= 90) { grade = 'A'; }
if (score >= 80) { grade = 'B'; }
if (score >= 70) { grade = 'C'; }

// ✅ 使用常量或枚举
#define GRADE_A 90
#define GRADE_B 80
#define GRADE_C 70

if (score >= GRADE_A) { grade = 'A'; }
if (score >= GRADE_B) { grade = 'B'; }
if (score >= GRADE_C) { grade = 'C'; }
```

### 5. 文档化复杂函数
```c
/**
 * Compare two strings.
 * @param str1: First string to compare
 * @param str2: Second string to compare
 * @return: <0 if str1 < str2, 0 if equal, >0 if str1 > str2
 */
int my_strcmp(const char* str1, const char* str2);
```

---

## ⚠️ 常见错误

### 错误 1：宏参数的括号
```c
#define DOUBLE(x) x * 2       // ❌
#define DOUBLE(x) ((x) * 2)   // ✅
```

### 错误 2：文件没有关闭
```c
FILE* fp = fopen("file.txt", "r");
// ... 使用文件
// ❌ 忘记关闭
return;

// ✅ 应该关闭
fclose(fp);
```

### 错误 3：缓冲区溢出
```c
char buffer[50];
strcpy(buffer, "This is a very long string");  // ❌ 危险

strncpy(buffer, "This is a very long string", 49);  // ✅ 安全
```

---

## 🎯 自测检查

完成本模块后，你应该能够：

- [ ] 手写基本的字符串函数
- [ ] 理解宏定义的用法和陷阱
- [ ] 正确使用 typedef
- [ ] 进行文件读写操作
- [ ] 理解文件指针定位
- [ ] 避免常见的代码缺陷

---

## 🧪 综合项目

### 项目 1：文本编辑器
实现一个简单的文本编辑器，支持打开、编辑、保存文件。

### 项目 2：数据分析工具
编写程序从 CSV 文件读取数据，进行统计分析，输出结果。

### 项目 3：配置文件解析器
编写程序解析 INI 格式的配置文件。

### 项目 4：日志系统
实现一个简单的日志系统，将日志输出到文件。

---

**恭喜！** 你已完成整个 C 语言学习路径！

现在你可以：
- 🎯 理解 C 语言的核心概念
- 💪 写出规范、高效的代码
- 🚀 进阶到数据结构、算法、系统编程等领域

**下一步建议**：
1. **📚 数据结构** - 基于 C 的链表、树、图等
2. **🔍 算法** - 排序、搜索、动态规划等
3. **🐧 系统编程** - Linux 系统调用、进程、线程
4. **🌐 网络编程** - Socket、网络协议等

---

**祝你编程之路顺利！** 💻
