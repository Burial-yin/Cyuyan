#define _CRT_SECURE_NO_WARNINGS 1
//迷宫初级
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>

char map[100][100] = {
	"*#*********",
	"***###*###*",
	"###**#****#",
	"*#**###**#*",
	"***********",
	"#####*##*##",
	"**#*****#*E",
	"***#*###**#",
	"*#*********",
};
//定位操作
int N = 9, M = 11;
int curX = 0, curY = 0, mg_x = 20, mg_y = 10, tips_x = 10, tips_y = 30, intro_x = 10, intro_y = 45;
void gotoxy(int x, int y){
	COORD pos;
	pos.X = x, pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//定义颜色
void setColor(unsigned int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//输出提示框
void outtips(){
	int i = 0;
	gotoxy(tips_x, tips_y);
	for (i = 0; i <= 60; i++)printf("*");
	gotoxy(tips_x, tips_y + 1);
	printf("*");
	for (i = 0; i<59; i++)printf(" ");
	printf("*");
	gotoxy(tips_x, tips_y + 2);
	for (i = 0; i<60; i++)printf("*");
}
//输出提示信息
void outtips_text(char *s){
	gotoxy(tips_x + 1, tips_y + 1);
	for (int i = 0; i <= 58; i++)
		printf(" ");
	gotoxy(tips_x + 1, tips_y + 1);
	printf("%s\a", s);
}
//打印人物
void printPerson()
{
	printf("*");
	gotoxy(curX + mg_x + 15, curY + mg_y);
	printf("A");
	gotoxy(curX + mg_x + 15, curY + mg_y);
}
//打印地图
void printMap(){
	for (int i = 0; i<N; i++){
		gotoxy(mg_x + 15, mg_y + i);
		printf("%s\n", map[i]);
	}
}
//人物移动
void myMove(char dir){
	switch (dir)
	{
	case 'w':
	case 'W':
		curY--;	if (curY<0) curY = 0;
		if (map[curY][curX] == '#') curY++;
		break;
	case 's':
	case 'S':
		curY++;
		if (curY >= N) curY = N - 1;
		if (map[curY][curX] == '#') curY--;
		break;
	case 'a':
	case 'A':
		curX--;
		if (curX<0) curX = 0;
		if (map[curY][curX] == '#') curX++;
		break;
	case 'd':
	case 'D':
		curX++;
		if (curX >= M) curX = M - 1;
		if (map[curY][curX] == '#') curX--;
		break;
	}
}
int main(){
	printMap();
	setColor(FOREGROUND_RED);//设置颜色为红色
	outtips();
	printPerson();
	outtips_text("\t\t提示：A——左 D——右 W——上 S——下\n");
	gotoxy(tips_x + 20, tips_y + 2);
	system("pause");
	time_t time(time_t *t);//利用时间戳计算通关时间
	time_t start, end;
	time(&start);
	while (1){
		char ch;
		ch = _getch();
		gotoxy(curX + mg_x + 15, curY + mg_y);
		myMove(ch);
		printPerson();
		if (map[curY][curX] == 'E'){
			char ss[100];
			time(&end);
			sprintf(ss, "\t通过成功,用时%d秒！", (end - start));
			outtips_text(ss);
			break;
		}
	}
	time_t timep;
	struct tm*p;
	time(&timep);
	p = localtime(&timep);
	printf("%d年 %d月 %d日", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	printf("\t %d:%d:%d\n", p->tm_hour, p->tm_min, p->tm_sec);
	printf(" \n\n\n\n\b编写人：一段路\n\n");
}