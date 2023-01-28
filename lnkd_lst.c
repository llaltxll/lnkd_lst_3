#include "head.h"
#include <stdlib.h>
#include <assert.h>

struct NODE
{
	int data;
	struct NODE * next;
};

struct NODE * HEAD_PTR = NULL;

void printList()
{
	struct NODE *next = HEAD_PTR;
	
	printf("|HEAD>");
	while (next)
	{
		printf("|%d>",next->data);
		next = next->next;
	}
	printf("|NULL|\n");
}

struct NODE *craateNode(int data)
{
	struct NODE *tmp;
	tmp = (struct NODE*)malloc(sizeof(struct NODE));
	assert(tmp != NULL && "malloc failed @ createNode()\n");
	
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

void append(struct NODE *tmp)
{
	//get pointer to last pointer
	struct NODE **ptr_last_ptr = pointerToLastPointer();	
	//point it to new node
	(*ptr_last_ptr) = tmp;
}

struct NODE **pointerToLastPointer()
{
	struct NODE **last = &HEAD_PTR;
	//go through list until we get a pointer to a null pointer
	while ( *last != NULL) last = &(*last)->next;
	return last;
}

	
