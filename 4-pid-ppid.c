/**
 * A program that prints the process id and parent process id each time
 * it is runned
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
  * main - Entry point of the program
  * Return: return 0
  */
int main(void)
{
	pid_t child_process;
	pid_t parent;

	child_process = getpid();
	parent = getppid();

	printf("I was trying to write a simple shell by this time\n");

	printf("The unique ID of this process is: %d\n", child_process);
	printf("The parent process ID is: %d (try echo $$)\n", parent);
	printf("You may run (/bin/bash) to get a different ppid\n");

	return (0);
}
