#pragma once
//头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//常量
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 30
#define CP_SZ 3
//通讯录需存放的个人信息
typedef struct Info {
	char name[MAX_NAME];//姓名
	char tele[MAX_TELE];//电话
	char addr[MAX_ADDR];//住址
}Info;
//通讯录存放信息
typedef struct Contact {
	Info* data;//能够存放信息人数
	int size;//记录当前已有的通讯录人数
	int capacity;//记录当前通讯录的容量
}Contact;
//选择选项
enum Option {
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Show,
	Sort
};
//创建通讯录
Contact con;//con为通讯录，里面包含：data、size、capacity
//声明函数
void InitContact(Contact* p);//初始化通讯录
void AddContact(Contact* p);//添加联系人
void DelContact(Contact* p);//删除指定联系人
void SearchContact(const Contact* p);//查找联系人
void ModifyContact(Contact* p);//修改联系人信息
void ShowContact(const Contact* p);//显示通讯录信息
void DestroyContact(Contact* p);//销毁通讯录