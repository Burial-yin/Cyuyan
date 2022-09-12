#define _CRT_SECURE_NO_WARNINGS 1
#include "txl.h"
//�������������
void CheckCapacity(Contact* p) {
	if (p->size == p->capacity) {
		Info* ptr = (Info*)realloc(p->data, (p->capacity + 2) * sizeof(Info));
		if (ptr != NULL) {
			p->data = ptr;
			p->capacity += 2; puts("���ݳɹ���");
		}
		else {
			puts("����ʧ�ܣ�"); system("pause"); return;
		}
	}
}
//���ر�������
void LoadContact(Contact *p) {
	Info temp = { 0 };
	FILE* fpRead = fopen("contact.dat", "rb");
	if (fpRead == NULL) {
		puts("��������ʧ�ܣ�");
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
//��ʼ��
void InitContact(Contact* p) {
	p->data = (Info*)malloc(CP_SZ * sizeof(Info));
	if (p->data == NULL) {
		perror("InitContact"); system("pause"); return;
	}
	p->size = 0;
	p->capacity = CP_SZ;
	LoadContact(p);
}
//����������
static int FindByName(const Contact* p, char name[MAX_NAME]) {
	int i = 0;
	for (i = 0; i < p->size; i++)
		if (strcmp(p->data[i].name, name) == 0)
			return i;
	return -1;
}
//1�����
void AddContact(Contact* p) {
	CheckCapacity(p);
	printf("����������:> ");
	scanf("%s", p->data[p->size].name);
	printf("������绰:> ");
	scanf("%s", p->data[p->size].tele);
	printf("�������ַ:> ");
	scanf("%s", p->data[p->size].addr);
	p->size++;
	puts("��ӳɹ�!");
	system("pause");
}
//2��ɾ��
void DelContact(Contact* p) {
	int pos = 0;
	int i = 0;
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�����:> ");
	scanf("%s", name);
	pos = FindByName(p,name);
	if (pos==-1) {
		puts("���޴��ˣ�"); system("pause"); return;
	}
	else {
		for (i = pos; i < p->size - 1; i++)
			p->data[i] = p->data[i + 1];
		p->size--;
	}
	puts("ɾ���ɹ���");
	system("pause");
}
//3������
void SearchContact(const Contact* p) {
	int pos = 0;
	char name[MAX_NAME];
	printf("��������Ҫ�����˵�����:> ");
	scanf("%s", name);
	pos = FindByName(p,name);
	if (pos == -1) {
		puts("���޴��ˣ�"); system("pause"); return;
	}
	else {
		printf("%-20s\t%-20s\t%-20s\n", "����", "�绰", "��ַ");
		printf("%-20s\t%-20s\t%-20s\n", p->data[pos].name, p->data[pos].tele, p->data[pos].addr);
	}
	puts("��ʾ��ϣ�");
	system("pause");
}
//4���޸�
void ModifyContact(Contact* p) {
	int pos = 0;
	char name[MAX_NAME];
	printf("��������Ҫ�޸��˵�����:> ");
	scanf("%s", name);
	pos = FindByName(p, name);
	if (pos == -1) {
		puts("���޴��ˣ�"); system("pause"); return;
	}
	else {
		printf("����������:> ");
		scanf("%s", p->data[pos].name);
		printf("������绰:> ");
		scanf("%s", p->data[pos].tele);
		printf("�������ַ:> ");
		scanf("%s", p->data[pos].addr);
	}
	puts("�޸���ϣ�");
	system("pause");
}
//����
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
//5����ʾ
void ShowContact(const Contact* p) {
	SortContact(p);
	int i = 0;
	if (p->size == 0)
		puts("ͨѶ¼Ϊ�գ�");
	else {
		printf("%-20s\t%-20s\t%-20s\n", "����", "�绰", "��ַ");
		for (i = 0; i < p->size; i++) 
			printf("%-20s\t%-20s\t%-20s\n",p->data[i].name,p->data[i].tele,p->data[i].addr);
	}
	puts("��ʾ��ϣ�");
	system("pause");
}
//����
static void SaveContact(Contact* p) {
	int i = 0;
	FILE* fpWrite = fopen("contact.dat", "wb");
	if (fpWrite == NULL) {
		puts("�޷����棡");
		perror("contact.dat"); 
		system("pause"); return;
	}
	for (i = 0; i < p->size; i++)
		fwrite(&(p->data[i]), sizeof(Info), 1, fpWrite);
	fclose(fpWrite);
	fpWrite = NULL;
	puts("������ϣ�");
}
//0���˳�����ͨѶ¼
void DestroyContact(Contact* p) {
	SaveContact(p);
	free(p->data);
	p->data = NULL;
	puts("ͨѶ¼������ϣ�");
}