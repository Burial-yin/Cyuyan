#define _CRT_SECURE_NO_WARNINGS 1
//������С��Ϸ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void menu(){
	printf("**************************\n");
	printf("*** 1��play    0��exit ***\n");
	printf("**************************\n");
}
void game(){
	//1�����������
	int ret;
	int guess;
	ret = rand() % 100 + 1;//����1��100֮��������
	//2��������
	while (1){
		printf("�������>:");
		scanf("%d", &guess);
		if (guess>ret)
			printf("��´���!\n");
		else if (guess<ret)
			printf("���С��!\n");
		else{
			printf("��ϲ�㣬�¶���!\n");
			break;
		}
	}
}
int main(){
	int input;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input){
		case 1:game();
			break;
		case 0:printf("�˳���Ϸ����ӭ�´�����!!\n");
			break;
		default:printf("�������!\n");
			break;
		}
	} while (input);
	return 0;
}