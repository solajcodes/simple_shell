/*using execve and expecting no returns*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - executes bin ls using the execve function
 * Return: execve returns nothing when successful
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", NULL};

	int r_val = execve(argv[0], argv, NULL);

	if (r_val == -1)
	{
		perror("Execve failed\n");
	}
	printf("Execve successful\n");

	return (0);
}
