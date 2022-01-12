#include "monty.h"

/**
* push - Push an elem to the top of the stack
*
* @stack: The stack.
* @line_number: The num of the line
*
* Return: Nothing, cause void function
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (globalVar.arrayCommand[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}

	if (stack == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return;


	new->n = atoi(globalVar.arrayCommand[1]);
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
* pall - Prints the value at the top of the stack, followed by a new line.
*
*@stack: Stack where are stored the value.
*@line_number: Line where we want to read.
*
* Return: Nothing cause void function
*/
void pall(stack_t **stack, unsigned int line_number)
{
	int i = line_number;
	stack_t *browse = *stack;

	if (stack == NULL)
	{
		return;
	}
	while (browse != NULL)
	{
		printf("%d\n", browse->n);
		browse = browse->next;
	}
}

/**
* pint - Print the top elem of the stack
*
* @stack: The stack.
* @line_number: The num of the line
*
* Return: Nothing, cause void function
*/
void pint(stack_t **stack, unsigned int line_number)
{

}

/**
* pop - Remove the top elem of the stack
*
* @stack: The stack.
* @line_number: The num of the line
*
* Return: Nothing, cause void function
*/
void pop(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	stack_t *browse = *stack;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}
	
	if (browse->next == NULL)
		*stack = NULL;
	else if (browse->next != NULL)
	{
		browse->next->prev = NULL;
		(*stack) = browse->next;
	}
	free(browse);
}
