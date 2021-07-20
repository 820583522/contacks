	#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
//静态初始化
//void ContactInit(contact* pc)
//{
//	pc->size = 0;
//	memset(pc->date, 0, sizeof(pc->date));
//}

//动态初始化
void ContactInit(contact* pc)
{
	pc->date = (PeoInfo*)malloc(sizeof(PeoInfo)*DefaultValue);
	if (pc->date == NULL)
	{
		perror("ContactInit");
		return;
	}
	pc->capcity = DefaultValue;
	pc->size = 0;
}

void ContactPrint(const contact* pc)
{
	//打印标题
	printf("name\tsex\tage\ttele\taddress\t\n");
	for (int i = 0; i < pc->size; i++)
	{
		printf("%s\t%s\t%d\t%s\t%s\t", pc->date[i].name, pc->date[i].sex, pc->date[i].age, pc->date[i].tele, pc->date[i].addr);
		printf("\n");
	}
}

void ContactAdd(contact* pc)
{
	if (pc->size == pc->capcity)
	{
		PeoInfo* adjust = (PeoInfo*)realloc(pc->date, sizeof(PeoInfo)*(pc->capcity + IncreaseValue));
		if (adjust == NULL)
		{
			printf("Capacity increase operation failed\n");
			return;
		}
		else
		{
			printf("Capacity increase operation successful\n");
			pc->date = adjust;
			pc->capcity += IncreaseValue;
		}
	}
	printf("Please enter name:\n");
	scanf("%s", pc->date[pc->size].name);
	printf("Please enter sex:\n");
	scanf("%s", pc->date[pc->size].sex);
	printf("Please enter age:\n");
	scanf("%d", &pc->date[pc->size].age);
	printf("Please enter tele:\n");
	scanf("%s", pc->date[pc->size].tele);
	printf("Please enter address:\n");
	scanf("%s", pc->date[pc->size].addr);
	pc->size++;
	printf("Successfully adding\n");
}

void ContactDel(contact* pc)
{
	if (pc->size == 0)
	{
		printf("The address book is empty.Don't need to delete\n");
		return;
	}
	int pos=ContactSearchByName(pc);
	if (pos == -1)
	{
		printf("The contact to be deleted does not exist\n");
		return;
	}
	else
	{
		memcpy(&(pc->date[pos]), &(pc->date[pos + 1]), sizeof(PeoInfo)*(pc->size - 1 - pos));
		pc->size--;
		printf("Delete succeeded\n");
	}
}
void ContactSearch(contact* pc)
{
	int pos = ContactSearchByName(pc);
	if (pos == -1)
	{
		printf("The contact does not exist\n");
		return;
	}
	else
	{
		printf("name\tsex\tage\ttele\taddress\t\n");
		printf("%s\t%s\t%d\t%s\t%s\t\n",
			pc->date[pos].name,
			pc->date[pos].sex,
			pc->date[pos].age,
			pc->date[pos].tele,
			pc->date[pos].addr);
	}
}
int ContactSearchByName(contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("Please enter the name of the contact you are looking for\n");
	scanf("%s", name);
	for (int pos = 0; pos < pc->size; pos++)
	{
		if (strcmp(pc->date[pos].name, name) == 0)
		{
			return pos;
		}
	}
	return -1;
}

void ContactModify(contact* pc)
{
	int pos = ContactSearchByName(pc);
	if (pos == -1)
	{
		printf("The contact does not exist\n");
		return;
	}
	else
	{
		printf("Please enter a new name\n");
		scanf("%s", pc->date[pos].name);
		printf("Please enter a new sex\n");
		scanf("%s", pc->date[pos].sex);
		printf("Please enter a new age\n");
		scanf("%d", &pc->date[pos].age);
		printf("Please enter a new tele\n");
		scanf("%s", pc->date[pos].tele);
		printf("Please enter a new address\n");
		scanf("%s", pc->date[pos].addr);
	}
}

void ContactDestory(contact* pc)
{
	free(pc->date);
	pc->size = pc->capcity = 0; 
}