#include <stdio.h>

#ifndef LNKD_LST
#define LNKD_LST

struct NODE **pointerToLastPointer(void);
struct NODE *craateNode(int data);
void append(struct NODE *tmp);
void printList(void);
int printMenu(void);
void freeNode(struct NODE **ptr_node);
int pop();
void freeList();
#endif	
