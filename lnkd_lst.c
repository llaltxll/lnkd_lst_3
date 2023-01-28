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

int pop()
{
	struct NODE **ptr2ptr2last_node;
	int data;
	if (!HEAD_PTR) return -1;
	ptr2ptr2last_node = &HEAD_PTR;
	//find pointer that points to a node that points to zero
	while ((*ptr2ptr2last_node)->next) ptr2ptr2last_node = &((*ptr2ptr2last_node)->next);
	data = (*ptr2ptr2last_node)->data;	
	//pass pointer to pointer to what we want to delete
	freeNode(ptr2ptr2last_node);

	return data;
}

void freeNode(struct NODE **ptr_node)
{	
	//					  this points to the next node
	struct NODE *delete = *ptr_node;
	//this is updating the next_ptr in the node 
	//that preceeds the deletion target node
	*ptr_node = delete->next;

	free(delete);
	delete = NULL;
}

void freeList()
{
	while (HEAD_PTR != 0)
	{	
		//pop(); less efficient
		freeNode(&HEAD_PTR);
	}
}

