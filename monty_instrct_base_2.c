#include "monty.h"


/**
* swap - Swap the two elem of the top stack
*
* @stack: The stack.
* @line_number: The num of the line.
*
* Return: Anything, cause void function
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *browse = *stack;
	int tmp;

	if (browse == NULL || browse->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}

	tmp = browse->n;
	browse->n = browse->next->n;
	browse->next->n = tmp;
}

/**
* pchar - Print if possible the top elem of the stack into a char
*
* @stack: The stack.
* @line_number: The num of the line.
*
* Return: Anything, cause void function
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->n > 127 || (*stack)->n < 0)
	{
		if (*stack == NULL)
			dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		else if ((*stack)->n > 127 || (*stack)->n < 0)
			dprintf(STDERR_FILENO,
			"L%d: can't pchar, value out of range\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}

/**
* pstr - Print since the top elem of the stack a char * until get a stop
*
* @stack: The stack.
* @line_number: The num of the line.
*
* Return: Anything, cause void function
*/
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *browse = *stack;

	while (browse)
	{
		if (browse->n > 127 || browse->n <= 0)
			break;
		putchar(browse->n);
		browse = browse->next;
	}
	printf("\n");
}

/**
* rotr - The top of the stack become the last elem
*
* @stack: The stack.
* @line_number: The num of the line.
*
* Return: Anything, cause void function
*/
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *browse = *stack;
	int i = 0;

	if (browse == NULL)
		return;

	while (browse->next)
	{
		i++;
		browse = browse->next;
	}
	if (i == 0)
		return;
	browse->prev->next = NULL;
	browse->next = (*stack);
	browse->prev = NULL;
	*stack = browse;
}

/**
* rotl - The last elem of the stack become the first
*
* @stack: The stack.
* @line_number: The num of the line.
*
* Return: Anything, cause void function
*/
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *browse = *stack, *cur = *stack;

	if (browse == NULL)
		return;
	while (browse->next)
		browse = browse->next;
	if (browse == *stack)
		return;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	cur->next = NULL;
	cur->prev = browse;
	browse->next = cur;
}
