#include "monty.h"

/**
* checkInput - Check if the command is right
*
* @argc: Number of arg
*
* Return: Nothing, cause void function
*/
void checkInput(int argc)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
* openFile - Open the given file
*
* @fileName: The name of the file
*
* Return: Nothing, cause void function
*/
void openFile(char *fileName)
{
	globalVar.file = fopen(fileName, "r");

	if (!globalVar.file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}
}

/**
* init_data - Init the global var data
*
* Return: Nothing, cause void function
*/
void init_data(void)
{
	globalVar.lineBuff = NULL;
	globalVar.head = NULL;
	globalVar.arrayCommand = NULL;
	globalVar.file = NULL;
	globalVar.etat = 0;
}
