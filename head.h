#include <stdio.h>

#ifndef LNKD_LST
#define LNKD_LST

struct NODE **pointerToLastPointer(void);
struct NODE *craateNode(int data);
void append(struct NODE *tmp);
void printList(void);
int printMenu(void);
#endif	
