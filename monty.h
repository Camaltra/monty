#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct global - Create the global malloc var, to free more easly
*
* @file: Pointer to the file
* @arrayCommand: The array of command
* @head: Pointer to the linked list
* @lineBuff: The pointer to the buffer getting line
*
*/
typedef struct global
{
	FILE *file;
	char **arrayCommand;
	stack_t *head;
	char *lineBuff;
} global;

global globalVar;

/* Prototype */

/* INIT */
void init_data(void);
void checkInput(int argc);
void openFile(char *fileName);

/* FN COMMAND */
void (*searchFn(void))(stack_t **stack_t, unsigned int line);
void push(stack_t **stack_t, unsigned int line);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

/* STR USEFULL */
int _strlen_letter(char *s);
void _strtow(char *str);
int _strcount_word(char *str);

/* FREE */
void freeAll(void);
void freeArrayCommand(void);
void freeList(stack_t *head);

#endif