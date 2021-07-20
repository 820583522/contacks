#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void menu()
{
	printf("*******************************************\n");
	printf("*******1.add           2.del **************\n");
	printf("*******3.search        4.modify************\n");
	printf("*******5.sort          6.print*************\n");
	printf("*******0.exit                 *************\n");
	printf("*******************************************\n");
}
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};
int main()
{
	int input = 0;
	contact con;
	ContactInit(&con); 
	do
	{
		menu();
		printf("Please select -> \n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			ContactAdd(&con);
			break;
		case DEL:
			ContactDel(&con);
			break;
		case SEARCH:
			ContactSearch(&con);
			break;
		case MODIFY:
			ContactModify(&con);
			break;
		case SORT:
			break;
		case PRINT:
			ContactPrint(&con);
			break;
		case EXIT:
			break;
		default:
			printf("Option error\n");
			break;
		}
	} while (input);
	return 0;
}