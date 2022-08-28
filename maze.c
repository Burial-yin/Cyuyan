#define _CRT_SECURE_NO_WARNINGS 1
//�Թ�����
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
//��λ����
int N = 9, M = 11;
int curX = 0, curY = 0, mg_x = 20, mg_y = 10, tips_x = 10, tips_y = 30, intro_x = 10, intro_y = 45;
void gotoxy(int x, int y){
	COORD pos;
	pos.X = x, pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//������ɫ
void setColor(unsigned int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//�����ʾ��
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
//�����ʾ��Ϣ
void outtips_text(char *s){
	gotoxy(tips_x + 1, tips_y + 1);
	for (int i = 0; i <= 58; i++)
		printf(" ");
	gotoxy(tips_x + 1, tips_y + 1);
	printf("%s\a", s);
}
//��ӡ����
void printPerson()
{
	printf("*");
	gotoxy(curX + mg_x + 15, curY + mg_y);
	printf("A");
	gotoxy(curX + mg_x + 15, curY + mg_y);
}
//��ӡ��ͼ
void printMap(){
	for (int i = 0; i<N; i++){
		gotoxy(mg_x + 15, mg_y + i);
		printf("%s\n", map[i]);
	}
}
//�����ƶ�
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
	setColor(FOREGROUND_RED);//������ɫΪ��ɫ
	outtips();
	printPerson();
	outtips_text("\t\t��ʾ��A������ D������ W������ S������\n");
	gotoxy(tips_x + 20, tips_y + 2);
	system("pause");
	time_t time(time_t *t);//����ʱ�������ͨ��ʱ��
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
			sprintf(ss, "\tͨ���ɹ�,��ʱ%d�룡", (end - start));
			outtips_text(ss);
			break;
		}
	}
	time_t timep;
	struct tm*p;
	time(&timep);
	p = localtime(&timep);
	printf("%d�� %d�� %d��", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	printf("\t %d:%d:%d\n", p->tm_hour, p->tm_min, p->tm_sec);
	printf(" \n\n\n\n\b��д�ˣ�һ��·\n\n");
}