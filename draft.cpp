#define _CRT_SECURE_NO_WARNINGS 1

//猜数字小游戏
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void menu() {
	printf("**************************\n");
	printf("*** 1、play    0、exit ***\n");
	printf("**************************\n");
}
void game() {
	//1、生成随机数
	int ret;
	int guess;
	ret = rand() % 100 + 1;//生成1—100之间的随机数
    //2、猜数字
	while (1) {
		printf("请猜数字>:");
		scanf("%d", &guess);
		if (guess > ret)
			printf("你猜大了!\n");
		else if (guess < ret)
			printf("你猜小了!\n");
		else {
			printf("恭喜你，猜对了!\n");
			break;
		}
	}
}
int main() {
	int input;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input) {
		case 1:game();
			break;
		case 0:printf("退出游戏，欢迎下次再玩!!\n");
			break;
		default:printf("输入错误!\n");
			break;
		}
	} while (input);
	return 0;
}