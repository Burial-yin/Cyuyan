#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 16//顺序表的最大长度

typedef struct
{
	int code;
	const  char* name;
	int weight;
}Course;//课程信息

typedef struct
{
	Course elems[MAX_SIZE];
	int length;
}SQList;//顺序表信息

//全部打印函数
void PrintList(SQList* sqlist) 
{
	int i = 0;
	printf("%-20s\t%-20s\t%-20s\n", "课程编号", "课程名称", "课程权重");
	for (i = 0; i < sqlist->length; i++) {
		printf("%-20d\t%-20s\t%-20d\n",
			sqlist->elems[i].code, sqlist->elems[i].name, sqlist->elems[i].weight);
	}
}

//初始化信息
SQList* InitList() 
{
	SQList* sqlist = (SQList*)malloc(sizeof(SQList));//开辟顺序表空间
	if (sqlist == NULL) {
		return sqlist;
	}
	sqlist->length = 0;
	sqlist->elems[sqlist->length++] = { 1,"程序设计",9 };
	sqlist->elems[sqlist->length++] = { 2,"离散数学",2 };
	sqlist->elems[sqlist->length++] = { 3,"数据结构",8 };
	sqlist->elems[sqlist->length++] = { 4,"汇编语言",1 };
	sqlist->elems[sqlist->length++] = { 5,"计算机算法",7 };
	sqlist->elems[sqlist->length++] = { 6,"微机原理",3 };
	sqlist->elems[sqlist->length++] = { 7,"编译原理",4 };
	sqlist->elems[sqlist->length++] = { 8,"操作系统",6 };
	sqlist->elems[sqlist->length++] = { 9,"高等数学",5 };
	sqlist->elems[sqlist->length++] = { 10,"线性代数",5 };
	printf("初始化完毕，结果如下：\n");
	PrintList(sqlist);
	return sqlist;
}

//插入信息
int InsertCourse(SQList* sqlist, int index, Course course) 
{
	int i = 0;
	if (sqlist == NULL) 
	{
		printf("顺序表不存在！\n");
		return -1;
	}
	if ((sqlist->length) >= MAX_SIZE) 
	{
		printf("顺序表已满，无法插入！\n");
		return -2;
	}
	if (index<1 || index>sqlist->length) 
	{
		printf("插入位置有误，无法插入！\n");
		return -3;
	}
	for (i = sqlist->length; i >= index; i--) 
	{
		sqlist->elems[i] = sqlist->elems[i - 1];
	}
	sqlist->elems[index - 1] = course;
	sqlist->length++;
	printf("\n插入成功，插入结果如下：\n");
	PrintList(sqlist);
	return 0;
}

//打印单门课程
void PrintCourse(Course course) {
	printf("%-20d\t%-20s\t%-20d\n",course.code,course.name,course.weight);
}

//查找课程信息
int FindCourse(SQList* sqlist) 
{
	int index = 0;
	int i = 0;
	for (i = 0; i < sqlist->length; i++) 
	{
		if (sqlist->elems[i].name == "编译原理")
		{
			index = i + 1;
			break;
		}
	}
	if (index == 0)
	{
		printf("没有找到“编译原理\"这门课！");
		return -1;
	}
	else
	{
		printf("\n已经找到“编译原理\",其信息如下：\n");
		PrintCourse(sqlist->elems[index-1]);
	}
	return index;
}

//删除课程
int DelCourse(SQList* sqlist, int pos)
{
	int i = 0;
	if (sqlist == NULL)
	{
		printf("顺序表不存在！\n");
		return -1;
	}
	if ((pos < 1) || (pos > sqlist->length))
	{
		printf("删除位置错误，无法删除！\n");
		return -2;
	}
	for (i = pos; i <= sqlist->length; i++)
	{
		sqlist->elems[i - 1] = sqlist->elems[i];
	}
	sqlist->length--;
	printf("\n删除成功，结果如下：\n");
	PrintList(sqlist);
}

int main() {
	SQList* sqlist = InitList();//创建顺序表并初始化
	InsertCourse(sqlist, 6, { 11,"计算机图形学",6 });
	//查找“编译原理”这门课程
	int j = FindCourse(sqlist);
	//删除课程
	DelCourse(sqlist, j);
	return 0;
}