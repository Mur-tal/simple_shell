#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
  * main - entry point oto the simple shell
  * @argc: argument count
  * @argv: argument vector
  * Return: 0 for Success
  */

int main(int argc, char *argv[])
{
	char *command = NULL;
	size_t len = 0;
	char *stkn;
	pid_t my_pid;
	int status, i;

	while (1)
	{
		printf("$ ");
		getline(&command, &len, stdin);
		stkn = strtok(command, " \n");
		char **arr = malloc(sizeof(char *) * 64);

		if (strcmp(arr[0], "exit") == 0)
			exit(0);
		arr[0] = stkn;
		i = 1;
		while (stkn != NULL)
		{
			stkn = strtok(NULL, " \n");
			arr[i] = stkn;
			i++;
		}
		my_pid = fork();
		if (my_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (my_pid == 0)
		{
			execve(arr[0], arr, NULL);
		}
		else
			wait(&status);
	}
	free(command);
	return (0);

}
