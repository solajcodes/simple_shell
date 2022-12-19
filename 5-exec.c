/*A program that prints the maximum value a process ID value can be*/
#include <stdio.h>
#include <unistd.h> /*for the fork and execve functions*/
#include <sys/types.h> /*for the fork and wait call*/
#include <sys/wait.h> /*for the wait call*/

/**
 * main - executes cat /proc/sys/kernel/pid_max
 * Return: 0 in the child and the child pid in the parent or -1 on
 * failure
 */
int main(void)
{
	char *argv[] = {"/usr/bin/cat", "/proc/sys/kernel/pid_max", NULL};
	pid_t child_id;

	child_id = fork();

	if (child_id == -1)
	{
		perror("Fork was unsuccessful\n");
		return (-1);
	}

	if (child_id == 0)
	{
		int value = execve(argv[0], argv, NULL);

		if (value == -1)
			perror("Execve failed\n");
	}
	else
	{
		wait(NULL);
		printf("Execve successfully executed\n");
	}
	return (0);
}
