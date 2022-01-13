#include "monty.h"


/**
* add - Add two nodes content in one and remove the top node
*
* @stack: The stack.
* @line_number: The num of the line.
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *browse = *stack;
	int count = 0;

	if (*stack == NULL || browse->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}

	count += browse->n;
	browse = browse->next;
	count += browse->n;
	browse->n = count;

	browse = browse->prev;

	if (browse->next != NULL)
	{
		browse->next->prev = NULL;
		(*stack) = browse->next;
	}
	else if (browse->next == NULL)
		browse->prev->next = NULL;
	else
	{
		browse->next->prev = browse->prev;
		browse->prev->next = browse->next;
	}
	free(browse);
}

/**
* sub - Substract the top node with the content of
* the second node and remove the top node
*
* @stack: The stack.
* @line_number: The num of the line.
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *browse = *stack;
	int count = 0;

	if (*stack == NULL || browse->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}
	count -= browse->n;
	browse = browse->next;
	count += browse->n;
	browse->n = count;
	browse = browse->prev;
	if (browse->next != NULL)
	{
		browse->next->prev = NULL;
		(*stack) = browse->next;
	}
	else if (browse->next == NULL)
		browse->prev->next = NULL;
	else
	{
		browse->next->prev = browse->prev;
		browse->prev->next = browse->next;
	}
	free(browse);
}

/**
* mul - Multiply the top node with the content
* of the second node and remove the top node
*
* @stack: The stack.
* @line_number: The num of the line.
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *browse = *stack;
	int count = 0;

	if (*stack == NULL || browse->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}
	count += browse->n;
	browse = browse->next;
	count *= browse->n;
	browse->n = count;
	browse = browse->prev;
	if (browse->next != NULL)
	{
		browse->next->prev = NULL;
		(*stack) = browse->next;
	}
	else if (browse->next == NULL)
		browse->prev->next = NULL;
	else
	{
		browse->next->prev = browse->prev;
		browse->prev->next = browse->next;
	}
	free(browse);
}

/**
* _div - Divise the top node with the content
* of the second node and remove the top node
*
* @stack: The stack.
* @line_number: The num of the line.
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *browse = *stack;
	int count = 0;

	if (*stack == NULL || browse->next == NULL || browse->n == 0)
	{
		if (!*stack || !browse->next)
			dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		else if (browse->n == 0)
			dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}
	browse = browse->next;
	count += browse->n;
	browse = browse->prev;
	count /= browse->n;
	browse = browse->next;
	browse->n = count;
	browse = browse->prev;
	if (browse->next != NULL)
	{
		browse->next->prev = NULL;
		(*stack) = browse->next;
	}
	else if (browse->next == NULL)
		browse->prev->next = NULL;
	else
	{
		browse->next->prev = browse->prev;
		browse->prev->next = browse->next;
	}
	free(browse);
}

/**
* mod - Computes the rest of the division of the second top
* element of the stack by the top element of the stack and delete the top node.
*
* @stack: The stack.
* @line_number: The num of the line.
*
* Return: Anything, cause void function
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *browse = *stack;
	int count = 0;

	if (*stack == NULL || browse->next == NULL || browse->n == 0)
	{
		if (!*stack || !browse->next)
			dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		else if (browse->n == 0)
			dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}
	browse = browse->next;
	count += browse->n;
	browse = browse->prev;
	count %= browse->n;
	browse = browse->next;
	browse->n = count;
	browse = browse->prev;
	if (browse->next != NULL)
	{
		browse->next->prev = NULL;
		(*stack) = browse->next;
	}
	else if (browse->next == NULL)
		browse->prev->next = NULL;
	else
	{
		browse->next->prev = browse->prev;
		browse->prev->next = browse->next;
	}
	free(browse);
}
