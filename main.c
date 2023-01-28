#include "head.h"

int main() 
{
	int run = 1;

	while (run)
	{
		run = printMenu();
	}

	freeList();
	return 0;
}
