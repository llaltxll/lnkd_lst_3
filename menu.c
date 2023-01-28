#include "head.h"

int handleAppend()
{
	struct NODE *tmp;
	int data = -1;
	while (data < 0)
	{
		printf("Append a new node to the list\n");
		printf("Enter positive int data-value for new node: ");
		scanf("%d", &data);
		getchar();//discard cr
		putchar('\n');
	}
	tmp = craateNode(data);
	append(tmp);
}


void handleSelection(char selection)
{
	switch (selection)
	{
		case '1':
			printList();
			break;
		case '2':
			handleAppend();
			break;
		case '3':
			printf("%d\n",pop());
			break;
		default:
			printf("invalid option: %c\n", selection);
			break;
	}
}
int printMenu()
{
	char selection = -1;

	do
	{	
		if (selection > -1)
		{
			handleSelection(selection);
		}
		printf("\nLinked-list program operations:\n");
		printf("1. print list\n");
		printf("2. append data node to list\n");
		printf("3. pop last node\n");

		printf("\nEnter selection number or q to quit: ");
		selection = getchar();
		getchar(); //discard cr
		putchar('\n');
	}
	while (selection != 'q');
	
	freeList();
	return 0;
}

