/*A program that is capable of printing out an instruction after execve*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - creates a child process that carries out the execve instruction;
 * Return: the program returns to the parent process which prints line 32
 */
int main(void)
{
	pid_t child_id;
	char *argv[] = {"/bin/ls", "-l", NULL};


	child_id = fork();

	/*checking to see whether the fork failed*/
	if (child_id == -1)
		return -1;

	/*child process*/
	if (child_id == 0)
	{
		int r_val = execve(argv[0], argv, NULL);

	/*checking to see whether the execve failed in the child process*/
		if (r_val == -1)
			perror("Execve failed\n");
	}

	/*parent process: where child_id is no more equal to zero*/
	else
	{
		wait(NULL); /*a wait call to avoid zombie state*/
		printf("Execve successful\n"); /*after execve*/
	}
	return (0);
}
