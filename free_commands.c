#include "monty.h"

/**
* freeAll - Free all variable
*/
void freeAll(void)
{
	freeList(globalVar.head);
	freeArrayCommand();
}

/**
* freeArrayCommand - Free the array of command
*/
void freeArrayCommand(void)
{
	int i;

	for (i = 0; globalVar.arrayCommand[i]; i++)
		;

	for ( ; i >= 0; i--)
		free(globalVar.arrayCommand[i]);
	free(globalVar.arrayCommand);
}

/**
* freeList - Free the linked list
*
* @head: The pointer to the linked list
*/
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
