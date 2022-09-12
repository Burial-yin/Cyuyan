#define _CRT_SECURE_NO_WARNINGS 1

#include "txl.h"
//选择系统
void menu() {
	puts("***************************************");
	puts("*** 1、添加 2、删除 3、查找 4、修改 ***");
	puts("*** 5、显示                 0、退出 ***");
	puts("***************************************");
	printf("请选择:> ");
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
			case Exit:DestroyContact(&con); puts("即将退出通讯录！");
				system("pause"); exit(0);
				break;
			default:puts("选择错误，请重试！"); system("pause"); break;
		}
	}
}
//主函数
int main() {
	//初始化通讯录
	InitContact(&con);
	slect();
	return 0;
}