#include "monty.h"

int main(int argc, char **argv)
{
    unsigned int line = 1;
    ssize_t lineSize;
    void (*f)(stack_t **stack_t, unsigned int line);

    checkInput(argc);
    init_data();
    openFile(argv[1]);
    while(getline(&globalVar.lineBuff, &lineSize, globalVar.file) != -1)
    {
        if (globalVar.lineBuff[strlen(globalVar.lineBuff) - 1] == '\n')
            globalVar.lineBuff[strlen(globalVar.lineBuff) - 1] = '\0';
        if (strlen(globalVar.lineBuff) != 0)
        {
            _strtow(globalVar.lineBuff);
            f = searchFn();
            if (f == NULL)
            {
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

void checkInput(int argc)
{
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    return;
}

void openFile(char *fileName)
{
    globalVar.file = fopen(fileName, "r");

    if (!globalVar.file)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", fileName);
        exit(EXIT_FAILURE);
    }
}

void (*searchFn(void))(stack_t **stack_t, unsigned int line)
{
    int j;

    instruction_t p[] = {
        {"push", push},
        {"pall", pall},
        {"pop", pop},
        /**
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

void push(stack_t **stack, unsigned int line)
{
    stack_t *new;

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
	return;
}


/**
 * strtow - splits a string into words.
 *
 * @str: String to splits
 *
 * Return: NULL is any problem, pointer to the new string else
 */
void _strtow(char *str)
{
	int i, word, letter, k, j = 0;

	if (str == NULL || *str == '\0')
		return;

	word = _strcount_word(str);
	if (word == 0)
		return;

	globalVar.arrayCommand = (char **)malloc(sizeof(char *) * (word + 1));
	if (globalVar.arrayCommand == NULL)
		return;

	for (i = 0; i < word; i++)
	{
		while (*(str + j) == ' ' || *(str + j) == '\t')
			j++;

		letter = _strlen_letter(str + j);

		globalVar.arrayCommand[i] = (char *)malloc(sizeof(char) * letter + 1);

		if (globalVar.arrayCommand[i] == NULL)
		{
			for ( ; i >= 0; i--)
				free(globalVar.arrayCommand[i]);
			free(globalVar.arrayCommand);
			return;
		}

		for (k = 0; k < letter; k++, j++)
			globalVar.arrayCommand[i][k] = str[j];

		globalVar.arrayCommand[i][k] = '\0';
	}
	globalVar.arrayCommand[i] = NULL;
}

/**
 * _strlen_letter - Calculate length of a word
 *
 * @s: Word inputed
 *
 * Return: Length of the word
 */
int _strlen_letter(char *s)
{
	int i = 0;

	while (*(s + i) != ' ' && *(s + i))
		i++;
	return (i);
}

/**
 * _strcount_word - Calculate the number of word
 *
 * @str: String inputed
 *
 * Return: The number of word
 */
int _strcount_word(char *str)
{
	int i = 0, word_count = 0, len = 0;

	for (i = 0; *(str + i); i++)
		len++;

	for (i = 0; i < len; i++)
	{
		if (*(str + i) != ' ')
		{
			word_count++;
			i += _strlen_letter(str + i);
		}
	}
	return (word_count);
}

/**
* pint - Prints the value at the top of the stack, followed by a new line.
*
*@stack: Stack where are stored the value.
*@line_number: Line where we want to read.
*/
void pall(stack_t **stack, unsigned int line_number)
{
    int i = line_number;
    stack_t *browse = *stack;

    if (stack == NULL)
    {
        printf("L%d: can't pint, stack empty\n", line_number);
        EXIT_FAILURE;
    }
    while (browse != NULL)
    {
        printf("%d\n", browse->n);
        browse = browse->next;
    }
}

void pint(stack_t **stack, unsigned int line_number)
{
    return;
}

void pop(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	stack_t *browse = *stack;

	if (browse->next == NULL)
		*stack = NULL;
	else if (browse->next != NULL)
	{
		browse->next->prev = NULL;
		(*stack) = browse->next;
	}
	free(browse);
    return;
}

void init_data(void)
{
    globalVar.lineBuff = NULL;
    globalVar.head = NULL;
    globalVar.arrayCommand = NULL;
    globalVar.file = NULL;
}