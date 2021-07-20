#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DefaultValue 3
#define IncreaseValue 2
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct contact
{
	PeoInfo* date;
	int size;
	int capcity;
}contact;

void ContactInit(contact* pc);
void ContactAdd(contact* pc);
void ContactPrint(const contact* pc);
void ContactDel(contact* pc);
void ContactSearch(contact* pc);
int ContactSearchByName(contact* pc);
void ContactModify(contact* pc);

void ContactDestory(contact* pc);