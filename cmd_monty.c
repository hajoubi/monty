#include "main.h"

<<<<<<< HEAD
extern int number;
#define DELIM "\n\t\r "
=======
/**
* execute - function that executes the opcode
* @stack: head stack linked list
* @counter: line count
* @file: pointer to monty file stream
* @content: line content
*
* Return: nothing
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop}, {NULL, NULL}
				};
	unsigned int i = 0;
	char *op;
>>>>>>> c02704dba70399584cf7c5c61b25cca6a02ce2b6

/**
 * open_and_read - Opens and reads the Monty file, executing the commands.
 * @argv: Command-line arguments.
 */
void open_and_read(char **argv)
{
	void (*p_func)(stack_t **, uint);
	FILE *fp;
	char *buf = NULL, *token = NULL, command[1024];
	size_t len = 0;
	int line_size;
	uint line_counter = 1;
	stack_t *top = NULL;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		open_error(argv);
	while ((line_size = getline(&buf, &len, fp)) != EOF)
	{
		token = strtok(buf, DELIM);
		if (token == NULL)
			continue;
		strcpy(command, token);
		if (is_comment(token, line_counter) == 1)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, DELIM);
			if (token == NULL || is_number(token) == -1)
				not_int_err(line_counter);
			number = atoi(token);
			p_func = get_op_code(command, line_counter);
			p_func(&top, line_counter);
		}
		else
		{
			p_func = get_op_code(token, line_counter);
			p_func(&top, line_counter);
		}
		line_counter++;
	}
	fclose(fp);
	if (buf != NULL)
		free(buf);
	free_stack(top);
}

/**
 * is_number - Checks if a string represents a valid number.
 * @token: The string to check.
 *
 * Return: 1 if the string is a valid number, -1 otherwise.
 */
int is_number(char *token)
{
	int i;

	if (token == NULL)
		return (-1);

	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] != '-' && isdigit(token[i]) == 0)
			return (-1);
	}

	return (1);
}

/**
 * is_comment - Checks if a token is a comment.
 * @token: The token to check.
 * @line_counter: The current line counter.
 *
 * Return: 1 if the token is a comment, -1 otherwise.
 */
int is_comment(char *token, int line_counter)
{
	if (token == NULL || token[0] == '#')
	{
		line_counter++;
		return (1);
	}
	return (-1);
}
