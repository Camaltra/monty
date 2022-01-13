#include "monty.h"

/**
* stack - Stack mode
*
* @stack: The stack.
* @line_number: The num of the line.
*
* Return: Anything, cause void function
*/
void stack(__attribute__((unused)) stack_t **stack, unsigned int line_number)
{
	int i;

	i = line_number;
	line_number = i;
	if (globalVar.etat == 0)
		return;
	globalVar.etat = 0;
}

/**
* queue - Queue mode
*
* @stack: The stack.
* @line_number: The num of the line.
*
* Return: Anything, cause void function
*/
void queue(__attribute__((unused)) stack_t **stack, unsigned int line_number)
{
	int i;

	i = line_number;
	line_number = i;
	if (globalVar.etat == 1)
		return;
	globalVar.etat = 1;
}
