#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//struct Stu
//{
//    char name[10];
//    int age;
//};
//void print1(struct Stu a) {
//    printf("%s %d\n", a.name, a.age);
//}
//void print2(struct Stu* a) {
//    printf("%s %d\n", a->name, a->age);
//}
//int main() {
//    struct Stu a = { "����",21 };
//    print1(a);
//    print2(&a);
//    return 0;
//}
//int check() {
//	union Un {
//		char a;
//		int b;
//	}un;
//	un.b = 1;
//	return un.a;
//}
//int main() {
//	int ret = check();
//	if (ret == 1)
//		printf("С�˴洢ģʽ��");
//	else
//		printf("��˴洢ģʽ��");
//	return 0;
//}
//#include <stdlib.h>
//int main() {
//	//���ڴ�����10�����Ϳռ�
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//		perror("p");
//	else 
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++) {
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//			printf("%d ", *(p + i));
//	}
//	free(p);
//  p = NULL;
//	return 0;
//}
//#include <stdlib.h>
//int main() {
//	//���ڴ�����10�����Ϳռ�
//	int* p = (int*)calloc(10 , sizeof(int));
//	if (p == NULL)
//		perror("p");
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//			printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
//#include <stdlib.h>
//int main() {
//	//���ڴ�����5�����Ϳռ�
//	int* p = (int*)malloc(5 * sizeof(int));
//	if (p != NULL)
//		perror("p");
//	else 
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++) {
//			*(p + i) = i;//��0 1 2 3 4 ���������ٵĿռ�
//		}
//	}
	//int* ptr = realloc(p, 10 * sizeof(int));//����5�����Ϳռ�
	//if (ptr != NULL) {
	//	p = ptr;
	//	int i = 0;
	//	for (i = 5; i < 10; i++) {
	//		*(p + i) = i;//��5 6 7 8 9�������ӵĿռ�
	//	}
	//	for (i = 0; i < 10; i++)
	//		printf("%d ", *(p + i));
	//}
	//free(p);
	//p = NULL;
	//return 0;
//}
//#include <string.h>
//#include <stdlib.h>
//void GetMemory(char** p) {
//	*p = (char*)malloc(100);
//}
//void Test() {
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "Hello world");
//	printf(str);
//	free(str);
//	str=NULL;
//}
//int main() {
//	Test();
//	return 0;
//}
#include <stdlib.h>
struct S {
	int a;
	int b[];//δָ�������С�����������Ա,����Ĵ�С�ǿ��Ե�����
};
int main() {
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
	ps->a = 100;
	int i = 0;
	for (i = 0; i < 5; i++)
		ps->b[i] = i;
	struct S* ptr = realloc(ps, 44);
	if (ptr != NULL)
		ps = ptr;
	for (i = 5; i < 10; i++)
		ps->b[i] = i;
	for (i = 0; i < 10; i++)
		printf("%d ", ps->b[i]);
	free(ps);
	ps = NULL;
	return 0;
}
//#include <stdlib.h>
//struct S {
//	int n;
//	int* arr;
//};
//int main() {
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	ps->arr = malloc(5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 5; i++) {
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 5; i++)
//		printf("%d ", ps->arr[i]);
//	//�����ڴ�
//	int* ptr = realloc(ps->arr, 10 * sizeof(int));
//	if (ptr != NULL) {
//		ps->arr = ptr;
//		for (i = 5; i < 10; i++)
//			ps->arr[i] = i;
//		for (i = 0; i < 10; i++)
//			printf("%d ", ps->arr[i]);
//	}
//	free(ps->arr);
//	free(ps);
//	ps->arr = NULL;
//	ps = NULL;
//	return 0;
//}