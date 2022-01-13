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
	int num;

	if (globalVar.arrayCommand[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}

	num = isNumber(globalVar.arrayCommand[1], line_number);

	if (stack == NULL)
		return;
	if (globalVar.etat == 0)
		add_dnodeint(stack, num);
	else
		add_dnodeint_end(stack, num);

}

/**
* pall - Prints the value at the top of the stack, followed by a new line.
*
*@stack: Stack where are stored the value.
*@line_number: Line where we want to read.
*
* Return: Nothing cause void function
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *browse = *stack;

	if (stack == NULL)
		return;
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
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
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

/**
* newLine - Print a new line to make test clear
*
* @stack: The stack.
* @line_number: The num of the line
*
* Return: Nothing, cause void function
*/
void newLine(__attribute__((unused)) stack_t **stack, unsigned int line_number)
{
	int i;

	printf("\n");
	i = line_number;
	line_number = i;
}

/**
* printElem - Print an instruction given in parameters
*
* @stack: The stack.
* @line_number: The num of the line
*
* Return: Nothing, cause void function
*/
void printElm(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
	if (globalVar.arrayCommand[1] == NULL)
	{
		dprintf(STDERR_FILENO,
		"L%d: No instructions | print instructions\n", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}

	printf("%s\n", globalVar.arrayCommand[1]);
}

/**
* nop - Do nothing
*
* @stack: The stack.
* @line_number: The num of the line
*
* Return: Nothing, cause void function
*/
void nop(__attribute__((unused)) stack_t **stack, unsigned int line_number)
{
	int i;

	i = line_number;
	line_number = i;
}

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
		printf("L%d: can't add, stack too short\n", line_number);
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
* sub - Substract the top node with the content of the second node and remove the top node
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
		printf("L%d: can't sub, stack too short\n", line_number);
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
* mul - Multiply the top node with the content of the second node and remove the top node
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
		printf("L%d: can't mul, stack too short\n", line_number);
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
* _div - Divise the top node with the content of the second node and remove the top node
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
			printf("L%d: can't div, stack too short\n", line_number);
		else if (browse->n == 0)
			printf("L%d: division by zero\n", line_number);
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
* mod - Computes the rest of the division of the second top element of the stack by the top element of the stack and delete the top node.
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
			printf("L%d: can't mod, stack too short\n", line_number);
		else if (browse->n == 0)
			printf("L%d: division by zero\n", line_number);
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

/**
* swap - kfd
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
* pchar - kfd
*
* @stack: The stack.
* @line_number: The num of the line.
*
* Return: Anything, cause void function
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->n > 128 || (*stack)->n < 0)
	{
		if (*stack == NULL)
			printf("L%d: can't pchar, stack empty", line_number);
		else if ((*stack)->n > 128 || (*stack)->n < 0)
			printf("L%d: can't pchar, value out of range", line_number);
		free(globalVar.lineBuff);
		freeAll();
		fclose(globalVar.file);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}

/**
* pstr - kfd
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
		if (browse->n > 128 || browse->n <= 0)
			break;
		putchar(browse->n);
		browse = browse->next;
	}
	printf("\n");
}

/**
* rotl - kfd
*
* @stack: The stack.
* @line_number: The num of the line.
*
* Return: Anything, cause void function
*/
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *browse = *stack;

	if (browse == NULL)
		return;

	while (browse->next)
		browse = browse->next;

	browse->prev->next = NULL;
	browse->next = (*stack);
	browse->prev = NULL;
	*stack = browse;
}

/**
* rotr - kfd
*
* @stack: The stack.
* @line_number: The num of the line.
*
* Return: Anything, cause void function
*/
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
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

/**
* stack - kfd
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
* queue - kfd
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

/**
* add_dnodeint - Add a node at the beginning of the linked list
*
* @head: Double pointer to the linked list
* @n: Value to fill
*
* Return: A pointer to the new created node
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}

/**
* add_dnodeint_end - Add a new node to the end of the linked list
*
* @head: Double pointer to the linked list
* @n: Value to fill
*
* Return: A pointer to the new created node
*/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *browse;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		browse = *head;
		while (browse->next != NULL)
			browse = browse->next;
		browse->next = new;
		new->prev = browse;
	}

	return (new);
}

/**
* isNumber - Check if it's a number
*
* @str: String to test
* @line_number: The x line
*
* Return: The number convert into an int
*/
int isNumber(char *str, int line_number)
{
	int i = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			free(globalVar.lineBuff);
			freeAll();
			fclose(globalVar.file);
			exit(EXIT_FAILURE);
		}
	}
	return (atoi(str));
}
