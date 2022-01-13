#include "monty.h"

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
* printElm - Print an instruction given in parameters
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
		if (str[i] == '-')
			continue;
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
