#include "monty.h"

void parseLine2(
	stack_t **h, char *opcode, char *strLineNumber, unsigned int *LIFO);

/**
 * parseLine - parse a left-stripped one-line string of monty bytecode
 * @h: head of stack [list]
 * @line: ptr to string to parse
 * @lineNumber: unsigned int that is printed when err occurs (eg: syntax err)
 * @LIFO: Last-In-First-Out
 */
void parseLine(
	stack_t **h, char **line, unsigned int lineNumber, unsigned int *LIFO)
{
	char *opcode, *arg;
	char strLineNumber[BUF_SIZE];

	sprintf(strLineNumber, "%u", lineNumber);
	/* lstrip(&line); */
	opcode = cut_str_before_space(line);
	/* printf("--%s-%d\n", opcode, strcmp(*line, "push")); */
	/* (*line) += strlen(opcode); */
	if (!strcmp(opcode, "push"))
	{
		lstrip(line);
		arg = cut_str_before_space(line);
		/* printf("-%s-%s-%d-%ld-\n", opcode, arg, arg[1], strlen(arg)); */
		if (!strlen(arg) || !isInt(arg))
			exit_with_err(
				concat(3, "L", strLineNumber, ": usage: push integer\n"),
					1, h);
		__push(h, atoi(arg), LIFO);
		free(arg);
	}
	else if (!strcmp(opcode, "pint"))
		__pint(h, strLineNumber);
	else if (!strcmp(opcode, "pop"))
		__pop(h, strLineNumber);
	else if (!strcmp(opcode, "swap"))
		__swap(h, strLineNumber);
	else if (!strcmp(opcode, "add"))
		__add(h, strLineNumber);
	else if (!strcmp(opcode, "nop"))
		__nop();
	else
		parseLine2(h, opcode, strLineNumber, LIFO);

}

/**
 * parseLine2 - the remaining of parseLine function
 *   (to bypass 40-line limit of betty stylecode)
 * @h: head of stack [list]
 * @opcode: opcode of current line of monty bytecode
 * @strLineNumber: string number that is printed when syntax err occurs
 * @LIFO: Last-In-First-Out
 */
void parseLine2(
	stack_t **h, char *opcode, char *strLineNumber, unsigned int *LIFO)
{
	if (!strcmp(opcode, "sub"))
		__sub(h, strLineNumber);
	else if (!strcmp(opcode, "div"))
		__div(h, strLineNumber);
	else if (!strcmp(opcode, "mul"))
		__mul(h, strLineNumber);
	else if (!strcmp(opcode, "mod"))
		__mod(h, strLineNumber);
	else if (!strcmp(opcode, "pchar"))
		__pchar(h, strLineNumber);
	else if (!strcmp(opcode, "pstr"))
		__pstr(h);
	else if (!strcmp(opcode, "rotl"))
		__rotl(h);
	else if (!strcmp(opcode, "rotr"))
		__rotr(h);
	else if (!strcmp(opcode, "stack"))
		__stack(LIFO);
	else if (!strcmp(opcode, "queue"))
		__queue(LIFO);
	else if (!strcmp(opcode, "pall"))
		__pall(h);
	else
		exit_with_err(
			concat(5, "L", strLineNumber, ": unknown instruction ", opcode, "\n"),
		1, h);
	free(opcode);
}


/**
 * main - entry point
 * @argc: count of string arguments
 * @argv: arr of string arguments
 *
 * Return: (0 on success) or (1 on fail)
 */
int main(int argc, char *argv[])
{
	FILE *filePointer;
	char buffer[BUF_SIZE], *bufferPtr, *bufferPtrReserve, *filename;
	unsigned int lineNumber = 1, LIFO = 1;
	stack_t *stack = NULL;

	if (argc != 2)
		exit_with_err("USAGE: monty file\n", 0, &stack);
	else if (!is_regular_file(argv[1]))
		exit_with_err(concat(3, "Error: Can't open file ", argv[1], "\n"),
			1, &stack);
	filename = argv[1];
	filePointer = fopen(filename, "r");
	while (fgets(buffer, BUF_SIZE, filePointer))
	{
		bufferPtr = createLstrippedString(strdup(buffer));
		bufferPtrReserve = bufferPtr;
		if (strcmp("\n", bufferPtr))
			parseLine(&stack, &bufferPtr, lineNumber, &LIFO);
		lineNumber++;
		free(bufferPtrReserve);
	}
	free_dlistint(&stack);
	fclose(filePointer);
	return (0);
}
