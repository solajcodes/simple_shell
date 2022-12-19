/*A program that uses the wait system call to avoid zombie state*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - creates a child process and makes the parent wait for the
 * to finish executing, to rip it off the process table
 * Return: the process id of the terminating child is returned to the
 * parent
 */
int main(void)
{
	pid_t pid;


	pid = fork();

	/*the child process*/
	if (pid == -1) /*checking whether it fails*/
	{
		perror("Operation failed!\n");
		return (0);
	}
	else if (pid == 0) /*if the child process was successsfully created*/
	{
		sleep (5); /*the child is made to delay for 5 seconds*/
		printf("Child process successfully created\n");
	}

	/*the parent process, after the child is through and its pid returned*/
	else
	{
		wait(NULL); /*the wait call, to avoid zombie state*/
		printf("Parent process continues after waiting\n");
	}
       	return (0);
}
