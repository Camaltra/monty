#include "monty.h"

/**
* freeAll - Free all variable
*
*
*
*
*/
void freeAll(void)
{
    freeList(globalVar.head);
    freeArrayCommand();
}

void freeArrayCommand(void)
{
    int i;
    for (i = 0; globalVar.arrayCommand[i]; i++)
        ;

    for ( ; i >= 0; i--)
        free(globalVar.arrayCommand[i]);
    free(globalVar.arrayCommand);
}

void freeList(stack_t *head)
{
    stack_t *cur;

	while (head != NULL)
	{
		cur = head;
		head = head->next;
		free(cur);
	}
}