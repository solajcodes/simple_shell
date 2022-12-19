#include <string.h>
#include <stdio.h>

/**
 * main - Entry point of the program
 * Return: 0
 */
int main(void)
{
	char string[] = "My team mate is my Best Friend.";
	const char delimiter[] = " ";

	char *tokenized = strtok(string, delimiter);

	while(tokenized != NULL)
	{
		printf("%s\n", tokenized);
		tokenized = strtok(NULL, delimiter);
	}

	return (0);
}
