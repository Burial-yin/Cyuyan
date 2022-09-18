#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct Course {
	int code;//课程编码
	char* name;//课程名称
	int weight;//课程权重
}Course;
Course* data;//data为存放课程数据的数组
int length;//表长度
int curlen;//实际长度
void init() {
	length = 30;
	curlen = 0;
	data = (Course*)malloc(sizeof(Course) * length);
}
//按关键字课程编号有序插入新数据元素crs
int insert(Course crs) {
	int i = 0,n=0;
	if (curlen >= length) return 0;
	for (i = 0; i < curlen; i++) {
		if (data[i].code > crs.code) break;
	}
	if (i < curlen) {
		for (n = curlen - 1; n >= i; n--)
			data[n + 1] = data[n];
	}
	data[i] = crs;//插入新结点crs
	curlen++;
	return 1;
}
void print() {
	int i = 0;
	printf("%-20s\t%-20s\t%-20s\n", "课程编码", "课程名称", "课程权重");
	for (i = 0; i < curlen; i++)
		printf("%-20d\t%-20s\t%-20d\n", data[i].code, data[i].name, data[i].weight);
}
void Destroy() {
	free(data); data = NULL;
}
Course* Delete(int i) {
	int n = 0;
	//判断删除位置是否正确
	if (i<1 || i>curlen) {
		printf("删除位置有误！"); return 0;
	}
	//保存删除前第一个数据元素
	Course crs = data[i - 1];
	//从i+1个位置依次向前移一个位置
	for (n = i; n < curlen; n++)
		data[n - 1] = data[n];
	curlen--;
	return &crs;
}
void Find(char* name) {
	Course* crs = NULL;
	int i = 0;
	for (i = 0; i < curlen; i++)
		if (strcmp(data[i].name, name) == 0)
			crs = &data[i];
	if (crs != NULL) {
		printf("%-20s\t%-20s\t%-20s\n", "课程编码", "课程名称", "课程权重");
		printf("%-20d\t%-20s\t%-20d\n", crs->code, crs->name, crs->weight);
	}
	else
		printf("%s不存在！\n", name);
}
int main() {
	init();
	Course c1 = { 1,"程序设计",9 }; insert(c1);
	Course c2 = { 2,"离散数学",2 }; insert(c2);
	Course c3 = { 3,"数据结构",8 }; insert(c3);
	Course c4 = { 4,"汇编语言",1 }; insert(c4);
	Course c5 = { 5,"计算机算法",7 }; insert(c5);
	Course c6 = { 6,"微机原理",3 }; insert(c6);
	Course c7 = { 7,"编译原理",4 }; insert(c7);
	Course c8 = { 8,"操作系统",6 }; insert(c8);
	Course c9 = { 9,"高等数学",5 }; insert(c9);
	Course c10 = { 10,"线性代数",5 }; insert(c10);
	puts("插入后打印如下："); print(); system("pause");
	Delete(10);
	puts("删除后打印如下："); print(); system("pause");
	puts("查找结果如下："); Find("编译原理"); system("pause");
	Destroy();
	return 0;
}

