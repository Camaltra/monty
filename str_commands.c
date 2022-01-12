#include "monty.h"

/**
 * _strtow - splits a string into words.
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

