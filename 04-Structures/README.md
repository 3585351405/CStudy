# 🏗️ 第四模块：结构体与复杂数据结构

学到这里，你已经掌握了 C 语言的基础。本模块教会你如何组织和管理复杂的数据。

## 📚 文件清单

| 文件 | 主要内容 | 难度 |
|------|--------|------|
| `01-struct-basics.c` | 结构体定义、初始化、访问 | ⭐⭐ |
| `02-struct-arrays.c` | 结构体数组和嵌套 | ⭐⭐ |
| `03-unions.c` | 联合体（共享内存） | ⭐⭐ |
| `04-enums.c` | 枚举类型 | ⭐ |

## 🎯 学习目标

1. ✅ 掌握结构体的定义和使用
2. ✅ 理解结构体的内存布局
3. ✅ 学会使用结构体指针
4. ✅ 理解联合体和枚举
5. ✅ 能设计合理的数据结构

## 🔑 核心概念

### 01 结构体基础

#### 定义结构体
```c
// 方式一：定义类型然后声明变量
struct Person {
	char name[50];
	int age;
	float height;
};

struct Person p1;  // 声明变量

// 方式二：同时定义和声明
struct Point {
	int x;
	int y;
} p, q;  // p 和 q 是全局变量

// 方式三：使用 typedef 简化
typedef struct {
	int x;
	int y;
} Point;

Point p;  // 更简洁
```

#### 初始化结构体
```c
// 方式一：指定初始化
struct Person p1 = {"Alice", 25, 165.5};

// 方式二：按成员初始化
struct Person p2 = {
	.name = "Bob",
	.age = 30,
	.height = 180.0
};

// 方式三：部分初始化（剩余为 0）
struct Person p3 = {"Charlie"};  // age 和 height 为 0
```

#### 访问结构体成员
```c
struct Person p = {"Alice", 25, 165.5};

// 直接访问
printf("%s\n", p.name);
p.age = 26;

// 通过指针访问
struct Person* ptr = &p;
printf("%s\n", ptr->name);  // 指针用 ->
ptr->age = 27;

// 也可以这样
printf("%s\n", (*ptr).name);
(*ptr).age = 28;
```

#### 结构体大小计算
```c
struct Person {
	char name[50];   // 50 字节
	int age;         // 4 字节（可能有填充）
	float height;    // 4 字节
};

// sizeof 计算是否包括填充
printf("%lu\n", sizeof(struct Person));  // 可能是 60, 64 等
```

> **注意**：编译器可能添加"填充"以对齐内存，使 sizeof 大于各成员大小之和。

---

### 02 结构体数组

```c
struct Person people[3] = {
	{"Alice", 25, 165.5},
	{"Bob", 30, 180.0},
	{"Charlie", 28, 175.5}
};

// 访问
printf("%s\n", people[0].name);

// 遍历
for (int i = 0; i < 3; i++) {
	printf("%s: %d岁\n", people[i].name, people[i].age);
}

// 指针遍历
struct Person* ptr = people;  // 指向第一个元素
for (int i = 0; i < 3; i++) {
	printf("%s\n", (ptr + i)->name);
}
```

---

### 03 结构体嵌套

```c
struct Address {
	char city[50];
	char street[100];
	int zipcode;
};

struct Person {
	char name[50];
	int age;
	struct Address address;  // 嵌套结构体
};

// 初始化嵌套结构体
struct Person p = {
	"Alice",
	25,
	{"Beijing", "Main Street 123", 100000}
};

// 访问嵌套成员
printf("%s\n", p.address.city);
printf("%s\n", p.address.street);
```

---

### 04 结构体指针与动态分配

```c
// 动态分配单个结构体
struct Person* p = (struct Person*)malloc(sizeof(struct Person));
if (p == NULL) exit(1);

// 访问
p->name = "Alice";  // -> 运算符用于指针
p->age = 25;

// 释放
free(p);
p = NULL;

// 动态分配结构体数组
struct Person* people = (struct Person*)malloc(10 * sizeof(struct Person));
people[0].age = 25;  // 数组形式访问
people[1].age = 30;

free(people);
```

---

### 05 联合体（Union）

联合体与结构体类似，但联合体的所有成员共享同一块内存。

```c
union Data {
	int i;
	char c;
	float f;
};

union Data data;
printf("%lu\n", sizeof(data));  // 输出 4（最大成员的大小）

data.i = 65;
printf("%d\n", data.i);  // 输出 65

data.f = 3.14;
printf("%d\n", data.i);  // 输出改变了（因为共享内存）
```

#### 联合体 vs 结构体
| 特性 | 结构体 | 联合体 |
|------|--------|--------|
| 内存占用 | 所有成员之和 | 最大成员的大小 |
| 成员修改 | 各自独立 | 共享内存 |
| 应用场景 | 存储不同类型数据 | 节省内存，存储变量数据 |

---

### 06 枚举（Enum）

定义一组命名常数。

```c
// 定义枚举
enum Color {
	RED = 0,
	GREEN = 1,
	BLUE = 2
};

// 使用
enum Color c = RED;

if (c == RED) {
	printf("Color is red\n");
}

// 也可以自动编号
enum Status {
	OFFLINE,      // 0
	ONLINE,       // 1
	BUSY,         // 2
	AWAY          // 3
};
```

#### 枚举的好处
- 代码更可读：`status == ONLINE` 比 `status == 1` 更清楚
- 避免魔术数字
- 编译器可以进行类型检查

---

## 💡 应用实例

### 例 1：学生管理系统
```c
struct Student {
	int id;
	char name[50];
	float grade;
	char class[10];
};

void print_student(struct Student s) {
	printf("ID: %d\n", s.id);
	printf("Name: %s\n", s.name);
	printf("Grade: %.2f\n", s.grade);
	printf("Class: %s\n", s.class);
}

int main() {
	struct Student students[100];
	int count = 0;

	// 读入学生信息
	// 打印学生信息
	// 搜索学生
	// 排序学生

	return 0;
}
```

### 例 2：复杂数据结构
```c
// 链表节点
struct Node {
	int data;
	struct Node* next;
};

struct Node* create_node(int value) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;
	return node;
}

// 树节点
struct TreeNode {
	int value;
	struct TreeNode* left;
	struct TreeNode* right;
};
```

---

## ⚠️ 常见错误

### 错误 1：忘记 typedef
```c
// ❌ 麻烦
struct Person p;

// ✅ 使用 typedef
typedef struct {
	char name[50];
	int age;
} Person;

Person p;  // 更简洁
```

### 错误 2：混淆 . 和 ->
```c
struct Person p;
struct Person* ptr = &p;

p.age = 25;        // ✅ 直接访问用 .
ptr->age = 25;     // ✅ 指针访问用 ->
ptr.age = 25;      // ❌ 错误！
(*ptr).age = 25;   // ✅ 也可以，但不推荐
```

### 错误 3：忘记 malloc 返回值检查
```c
struct Person* p = (struct Person*)malloc(sizeof(struct Person));
// ❌ 没有检查
p->age = 25;  // 可能崩溃

// ✅ 正确
if (p == NULL) exit(1);
p->age = 25;
```

### 错误 4：结构体成员数组大小不适当
```c
struct Person {
	char name[10];  // 只能存 9 个字符（+ null terminator）
};

strcpy(p.name, "This is a very long name");  // ❌ 缓冲区溢出
```

---

## 🎓 最佳实践

### 1. 使用 typedef 简化
```c
typedef struct {
	int x;
	int y;
} Point;

Point p = {10, 20};  // 更简洁
```

### 2. 为结构体写初始化函数
```c
struct Person* person_create(const char* name, int age) {
	struct Person* p = (struct Person*)malloc(sizeof(struct Person));
	if (p == NULL) return NULL;

	strcpy(p->name, name);
	p->age = age;
	return p;
}

void person_free(struct Person* p) {
	free(p);
}
```

### 3. 定义清晰的成员命名
```c
// ❌ 不清楚
struct Data {
	int a;
	float b;
	char* c;
};

// ✅ 清楚
struct Person {
	int id;
	char name[50];
	float salary;
};
```

### 4. 在头文件中定义结构体
```c
// person.h
#ifndef PERSON_H
#define PERSON_H

typedef struct {
	int id;
	char name[50];
	float salary;
} Person;

Person* person_create(const char* name);
void person_free(Person* p);

#endif
```

---

## 🎯 自测检查

完成本模块后，你应该能够：

- [ ] 定义和使用结构体
- [ ] 理解结构体内存布局
- [ ] 正确使用 . 和 ->
- [ ] 使用结构体指针和动态分配
- [ ] 理解联合体和结构体的区别
- [ ] 使用枚举定义常数
- [ ] 设计合理的数据结构
- [ ] 避免结构体相关的常见错误

---

## 🧪 练习项目

### 项目 1：地址簿
创建一个简单的联系人管理系统，支持添加、删除、查询联系人。

### 项目 2：图书馆系统
实现图书管理系统，包括图书的增添、借阅、归还等功能。

### 项目 3：链表实现
使用结构体指针实现一个简单的整数链表。

### 项目 4：二叉搜索树
实现一个简单的二叉搜索树数据结构。

---

**下一步**：进入**第五模块：代码优化与高级技巧** 🚀
