/*A program that creates a child process and causes it to sleep for 5 secs*/
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of the program
 * Return: returns 0 in the child and the child's pid in the parents.
 */
int main(void)
{
	pid_t child_id;


	child_id = fork();
	if (child_id == -1)
	{
		perror("e no work!\n");
		return (0);
	}
	else if (child_id == 0)
	{
		sleep (5);
		printf("After birth, this resulted\n");
	}
	else
		printf("Before birth, we had this\n");
	return (0);
}
