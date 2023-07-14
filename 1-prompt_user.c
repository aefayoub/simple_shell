#include <string.h>
#include "main.h"

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *command;
	size_t buffer_size = BUFFER_SIZE;
	ssize_t line_size;

	while (1)
	{
		command = (char *)malloc(buffer_size * sizeof(char));
		if (command == NULL)
		{
			perror("Allocation error");
			exit(EXIT_FAILURE);
		}

		printf("#cisfun$ "); // Display the prompt
		line_size = getline(&command, &buffer_size, stdin);
		if (line_size == -1)
		{
			printf("\n"); // Print a new line if Ctrl+D (EOF) is encountered
			break;
		}

		// Remove the newline character at the end of the command
		command[strcspn(command, "\n")] = '\0';

		// Check if the command is "exit"
		if (strcmp(command, "exit") == 0)
		{
			free(command);
			break;
		}

		// Fork a child process
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("Fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			// Child process

			// Execute the command
			execlp(command, command, NULL);

			// If execution reaches this point, an error occurred
			perror("Command execution error");
			exit(EXIT_FAILURE);
		}
		else
		{
			// Parent process
			int status;
			wait(&status);

			if (status != 0)
				printf("%s: Command not found\n", command);
		}

		free(command);
	}

	return 0;
}

