#include "monty.h"

/**
* main - The heart of the program, transform the
* given file code and compile it
*
* @argc: Num of arg
* @argv: Array of arg
*
* Return: 0 (succes)
*/
int main(int argc, char **argv)
{
	unsigned int line = 1;
	ssize_t lineSize;
	void (*f)(stack_t **stack_t, unsigned int line);

	checkInput(argc);
	init_data();
	openFile(argv[1]);
	while (getline(&globalVar.lineBuff, &lineSize, globalVar.file) != -1)
	{
		if (globalVar.lineBuff[strlen(globalVar.lineBuff) - 1] == '\n')
			globalVar.lineBuff[strlen(globalVar.lineBuff) - 1] = '\0';
		if (strlen(globalVar.lineBuff) != 0)
		{
			_strtow(globalVar.lineBuff);
			f = searchFn();
			if (f == NULL)
			{
				dprintf(STDERR_FILENO,
				"L%d : unknown instruction %s\n", line, globalVar.arrayCommand[0]);
				free(globalVar.lineBuff);
				freeAll();
				fclose(globalVar.file);
				exit(EXIT_FAILURE);
			}
			f(&globalVar.head, line);
			freeArrayCommand();
		}
		line++;
	}
	free(globalVar.lineBuff);
	fclose(globalVar.file);
	freeList(globalVar.head);
	return (0);
}

/**
* searchFn - Search the good function to exe
*
* Return: Nothing, cause void function
*/
void (*searchFn(void))(stack_t **stack_t, unsigned int line)
{
	int j;

	instruction_t p[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		/*
		{"nop", nop},
		{"add", add},
		{"swap", swap},
		{"pint", pint},
		*/
		{"NULL", NULL},
	};
	for (j = 0; p[j].opcode != NULL; j++)
	{
		if (strcmp("NULL", p[j].opcode) == 0)
			break;
		if (strcmp(globalVar.arrayCommand[0], p[j].opcode) == 0)
			return (p[j].f);
	}

	return (NULL);
}
