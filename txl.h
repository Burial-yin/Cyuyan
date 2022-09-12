#pragma once
//ͷ�ļ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//����
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 30
#define CP_SZ 3
//ͨѶ¼���ŵĸ�����Ϣ
typedef struct Info {
	char name[MAX_NAME];//����
	char tele[MAX_TELE];//�绰
	char addr[MAX_ADDR];//סַ
}Info;
//ͨѶ¼�����Ϣ
typedef struct Contact {
	Info* data;//�ܹ������Ϣ����
	int size;//��¼��ǰ���е�ͨѶ¼����
	int capacity;//��¼��ǰͨѶ¼������
}Contact;
//ѡ��ѡ��
enum Option {
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Show,
	Sort
};
//����ͨѶ¼
Contact con;//conΪͨѶ¼�����������data��size��capacity
//��������
void InitContact(Contact* p);//��ʼ��ͨѶ¼
void AddContact(Contact* p);//�����ϵ��
void DelContact(Contact* p);//ɾ��ָ����ϵ��
void SearchContact(const Contact* p);//������ϵ��
void ModifyContact(Contact* p);//�޸���ϵ����Ϣ
void ShowContact(const Contact* p);//��ʾͨѶ¼��Ϣ
void DestroyContact(Contact* p);//����ͨѶ¼