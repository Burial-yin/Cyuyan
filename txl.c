#define _CRT_SECURE_NO_WARNINGS 1

#include "txl.h"
//ѡ��ϵͳ
void menu() {
	puts("***************************************");
	puts("*** 1����� 2��ɾ�� 3������ 4���޸� ***");
	puts("*** 5����ʾ                 0���˳� ***");
	puts("***************************************");
	printf("��ѡ��:> ");
}
void slect() {
	int input = 0;
	while (1) {
		system("cls");
		menu();
		scanf("%d", &input);
		switch (input) {
			case Add:AddContact(&con);
				break;
			case Del:DelContact(&con);
				break;
			case Search:SearchContact(&con);
				break;
			case Modify:ModifyContact(&con);
				break;
			case Show:ShowContact(&con);
				break;
			case Exit:DestroyContact(&con); puts("�����˳�ͨѶ¼��");
				system("pause"); exit(0);
				break;
			default:puts("ѡ����������ԣ�"); system("pause"); break;
		}
	}
}
//������
int main() {
	//��ʼ��ͨѶ¼
	InitContact(&con);
	slect();
	return 0;
}