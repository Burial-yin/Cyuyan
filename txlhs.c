#define _CRT_SECURE_NO_WARNINGS 1
#include "txl.h"
//检测容量并增容
void CheckCapacity(Contact* p) {
	if (p->size == p->capacity) {
		Info* ptr = (Info*)realloc(p->data, (p->capacity + 2) * sizeof(Info));
		if (ptr != NULL) {
			p->data = ptr;
			p->capacity += 2; puts("增容成功！");
		}
		else {
			puts("增容失败！"); system("pause"); return;
		}
	}
}
//加载本地数据
void LoadContact(Contact *p) {
	Info temp = { 0 };
	FILE* fpRead = fopen("contact.dat", "rb");
	if (fpRead == NULL) {
		puts("加载数据失败！");
		perror("contact.dat"); system("pause"); return;
	}
	while (fread(&temp, sizeof(Info), 1, fpRead)) {
		CheckCapacity(p);
		p->data[p->size] = temp;
		p->size++;
	}
	fclose(fpRead);
	fpRead = NULL;
}
//初始化
void InitContact(Contact* p) {
	p->data = (Info*)malloc(CP_SZ * sizeof(Info));
	if (p->data == NULL) {
		perror("InitContact"); system("pause"); return;
	}
	p->size = 0;
	p->capacity = CP_SZ;
	LoadContact(p);
}
//按姓名查找
static int FindByName(const Contact* p, char name[MAX_NAME]) {
	int i = 0;
	for (i = 0; i < p->size; i++)
		if (strcmp(p->data[i].name, name) == 0)
			return i;
	return -1;
}
//1、添加
void AddContact(Contact* p) {
	CheckCapacity(p);
	printf("请输入姓名:> ");
	scanf("%s", p->data[p->size].name);
	printf("请输入电话:> ");
	scanf("%s", p->data[p->size].tele);
	printf("请输入地址:> ");
	scanf("%s", p->data[p->size].addr);
	p->size++;
	puts("添加成功!");
	system("pause");
}
//2、删除
void DelContact(Contact* p) {
	int pos = 0;
	int i = 0;
	char name[MAX_NAME];
	printf("请输入要删除人的姓名:> ");
	scanf("%s", name);
	pos = FindByName(p,name);
	if (pos==-1) {
		puts("查无此人！"); system("pause"); return;
	}
	else {
		for (i = pos; i < p->size - 1; i++)
			p->data[i] = p->data[i + 1];
		p->size--;
	}
	puts("删除成功！");
	system("pause");
}
//3、查找
void SearchContact(const Contact* p) {
	int pos = 0;
	char name[MAX_NAME];
	printf("请输入需要查找人的姓名:> ");
	scanf("%s", name);
	pos = FindByName(p,name);
	if (pos == -1) {
		puts("查无此人！"); system("pause"); return;
	}
	else {
		printf("%-20s\t%-20s\t%-20s\n", "名字", "电话", "地址");
		printf("%-20s\t%-20s\t%-20s\n", p->data[pos].name, p->data[pos].tele, p->data[pos].addr);
	}
	puts("显示完毕！");
	system("pause");
}
//4、修改
void ModifyContact(Contact* p) {
	int pos = 0;
	char name[MAX_NAME];
	printf("请输入需要修改人的姓名:> ");
	scanf("%s", name);
	pos = FindByName(p, name);
	if (pos == -1) {
		puts("查无此人！"); system("pause"); return;
	}
	else {
		printf("请输入姓名:> ");
		scanf("%s", p->data[pos].name);
		printf("请输入电话:> ");
		scanf("%s", p->data[pos].tele);
		printf("请输入地址:> ");
		scanf("%s", p->data[pos].addr);
	}
	puts("修改完毕！");
	system("pause");
}
//排序
static void SortContact(Contact* p) {
	int i = 0, j = 0;
	Info name;
	for (i = 0; i < p->size; i++) {
		for (j = 0; j < p->size - 1; j++) {
			if (strcmp(p->data[j].name, p->data[j + 1].name) > 0) {
				name = p->data[j], p->data[j] = p->data[j + 1],
					p->data[j + 1] = name;
			}
		}
	}
}
//5、显示
void ShowContact(const Contact* p) {
	SortContact(p);
	int i = 0;
	if (p->size == 0)
		puts("通讯录为空！");
	else {
		printf("%-20s\t%-20s\t%-20s\n", "名字", "电话", "地址");
		for (i = 0; i < p->size; i++) 
			printf("%-20s\t%-20s\t%-20s\n",p->data[i].name,p->data[i].tele,p->data[i].addr);
	}
	puts("显示完毕！");
	system("pause");
}
//保存
static void SaveContact(Contact* p) {
	int i = 0;
	FILE* fpWrite = fopen("contact.dat", "wb");
	if (fpWrite == NULL) {
		puts("无法保存！");
		perror("contact.dat"); 
		system("pause"); return;
	}
	for (i = 0; i < p->size; i++)
		fwrite(&(p->data[i]), sizeof(Info), 1, fpWrite);
	fclose(fpWrite);
	fpWrite = NULL;
	puts("保存完毕！");
}
//0、退出销毁通讯录
void DestroyContact(Contact* p) {
	SaveContact(p);
	free(p->data);
	p->data = NULL;
	puts("通讯录销毁完毕！");
}