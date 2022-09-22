#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 16//˳������󳤶�

typedef struct
{
	int code;
	const  char* name;
	int weight;
}Course;//�γ���Ϣ

typedef struct
{
	Course elems[MAX_SIZE];
	int length;
}SQList;//˳�����Ϣ

//ȫ����ӡ����
void PrintList(SQList* sqlist) 
{
	int i = 0;
	printf("%-20s\t%-20s\t%-20s\n", "�γ̱��", "�γ�����", "�γ�Ȩ��");
	for (i = 0; i < sqlist->length; i++) {
		printf("%-20d\t%-20s\t%-20d\n",
			sqlist->elems[i].code, sqlist->elems[i].name, sqlist->elems[i].weight);
	}
}

//��ʼ����Ϣ
SQList* InitList() 
{
	SQList* sqlist = (SQList*)malloc(sizeof(SQList));//����˳���ռ�
	if (sqlist == NULL) {
		return sqlist;
	}
	sqlist->length = 0;
	sqlist->elems[sqlist->length++] = { 1,"�������",9 };
	sqlist->elems[sqlist->length++] = { 2,"��ɢ��ѧ",2 };
	sqlist->elems[sqlist->length++] = { 3,"���ݽṹ",8 };
	sqlist->elems[sqlist->length++] = { 4,"�������",1 };
	sqlist->elems[sqlist->length++] = { 5,"������㷨",7 };
	sqlist->elems[sqlist->length++] = { 6,"΢��ԭ��",3 };
	sqlist->elems[sqlist->length++] = { 7,"����ԭ��",4 };
	sqlist->elems[sqlist->length++] = { 8,"����ϵͳ",6 };
	sqlist->elems[sqlist->length++] = { 9,"�ߵ���ѧ",5 };
	sqlist->elems[sqlist->length++] = { 10,"���Դ���",5 };
	printf("��ʼ����ϣ�������£�\n");
	PrintList(sqlist);
	return sqlist;
}

//������Ϣ
int InsertCourse(SQList* sqlist, int index, Course course) 
{
	int i = 0;
	if (sqlist == NULL) 
	{
		printf("˳������ڣ�\n");
		return -1;
	}
	if ((sqlist->length) >= MAX_SIZE) 
	{
		printf("˳����������޷����룡\n");
		return -2;
	}
	if (index<1 || index>sqlist->length) 
	{
		printf("����λ�������޷����룡\n");
		return -3;
	}
	for (i = sqlist->length; i >= index; i--) 
	{
		sqlist->elems[i] = sqlist->elems[i - 1];
	}
	sqlist->elems[index - 1] = course;
	sqlist->length++;
	printf("\n����ɹ������������£�\n");
	PrintList(sqlist);
	return 0;
}

//��ӡ���ſγ�
void PrintCourse(Course course) {
	printf("%-20d\t%-20s\t%-20d\n",course.code,course.name,course.weight);
}

//���ҿγ���Ϣ
int FindCourse(SQList* sqlist) 
{
	int index = 0;
	int i = 0;
	for (i = 0; i < sqlist->length; i++) 
	{
		if (sqlist->elems[i].name == "����ԭ��")
		{
			index = i + 1;
			break;
		}
	}
	if (index == 0)
	{
		printf("û���ҵ�������ԭ��\"���ſΣ�");
		return -1;
	}
	else
	{
		printf("\n�Ѿ��ҵ�������ԭ��\",����Ϣ���£�\n");
		PrintCourse(sqlist->elems[index-1]);
	}
	return index;
}

//ɾ���γ�
int DelCourse(SQList* sqlist, int pos)
{
	int i = 0;
	if (sqlist == NULL)
	{
		printf("˳������ڣ�\n");
		return -1;
	}
	if ((pos < 1) || (pos > sqlist->length))
	{
		printf("ɾ��λ�ô����޷�ɾ����\n");
		return -2;
	}
	for (i = pos; i <= sqlist->length; i++)
	{
		sqlist->elems[i - 1] = sqlist->elems[i];
	}
	sqlist->length--;
	printf("\nɾ���ɹ���������£�\n");
	PrintList(sqlist);
}

int main() {
	SQList* sqlist = InitList();//����˳�����ʼ��
	InsertCourse(sqlist, 6, { 11,"�����ͼ��ѧ",6 });
	//���ҡ�����ԭ�����ſγ�
	int j = FindCourse(sqlist);
	//ɾ���γ�
	DelCourse(sqlist, j);
	return 0;
}