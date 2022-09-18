#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct Course {
	int code;//�γ̱���
	char* name;//�γ�����
	int weight;//�γ�Ȩ��
}Course;
Course* data;//dataΪ��ſγ����ݵ�����
int length;//����
int curlen;//ʵ�ʳ���
void init() {
	length = 30;
	curlen = 0;
	data = (Course*)malloc(sizeof(Course) * length);
}
//���ؼ��ֿγ̱���������������Ԫ��crs
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
	data[i] = crs;//�����½��crs
	curlen++;
	return 1;
}
void print() {
	int i = 0;
	printf("%-20s\t%-20s\t%-20s\n", "�γ̱���", "�γ�����", "�γ�Ȩ��");
	for (i = 0; i < curlen; i++)
		printf("%-20d\t%-20s\t%-20d\n", data[i].code, data[i].name, data[i].weight);
}
void Destroy() {
	free(data); data = NULL;
}
Course* Delete(int i) {
	int n = 0;
	//�ж�ɾ��λ���Ƿ���ȷ
	if (i<1 || i>curlen) {
		printf("ɾ��λ������"); return 0;
	}
	//����ɾ��ǰ��һ������Ԫ��
	Course crs = data[i - 1];
	//��i+1��λ��������ǰ��һ��λ��
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
		printf("%-20s\t%-20s\t%-20s\n", "�γ̱���", "�γ�����", "�γ�Ȩ��");
		printf("%-20d\t%-20s\t%-20d\n", crs->code, crs->name, crs->weight);
	}
	else
		printf("%s�����ڣ�\n", name);
}
int main() {
	init();
	Course c1 = { 1,"�������",9 }; insert(c1);
	Course c2 = { 2,"��ɢ��ѧ",2 }; insert(c2);
	Course c3 = { 3,"���ݽṹ",8 }; insert(c3);
	Course c4 = { 4,"�������",1 }; insert(c4);
	Course c5 = { 5,"������㷨",7 }; insert(c5);
	Course c6 = { 6,"΢��ԭ��",3 }; insert(c6);
	Course c7 = { 7,"����ԭ��",4 }; insert(c7);
	Course c8 = { 8,"����ϵͳ",6 }; insert(c8);
	Course c9 = { 9,"�ߵ���ѧ",5 }; insert(c9);
	Course c10 = { 10,"���Դ���",5 }; insert(c10);
	puts("������ӡ���£�"); print(); system("pause");
	Delete(10);
	puts("ɾ�����ӡ���£�"); print(); system("pause");
	puts("���ҽ�����£�"); Find("����ԭ��"); system("pause");
	Destroy();
	return 0;
}

