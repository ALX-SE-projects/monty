#include "monty.h"
unsigned int LIFO = 1;
stack_t *stack = NULL;

void free_stack()
{
	if (stack)
		free_dlistint(stack);
}

int is_regular_file(const char *path)
{
   struct stat path_stat;
   if (access(path, F_OK) != -1 && stat(path, &path_stat) == 0) {
       return S_ISREG(path_stat.st_mode);
   } else {
       return 0;
   }
}

char *concat(int count, ...) {
   va_list args;
   va_start(args, count);
   char* result = malloc(1);
   result[0] = '\0';
   for (int i = 0; i < count; i++) {
       char* str = va_arg(args, char*);
       result = realloc(result, strlen(result) + strlen(str) + 1);
       strcat(result, str);
   }
   va_end(args);
   return result;
}

void exit_with_err(char *err_msg)
{
	free_stack();
	fprintf(stderr, err_msg);
	exit(EXIT_FAILURE);
}

void *my_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (!ptr)
		exit_with_err("Error: malloc failed\n");
	return (ptr);
}

void lstrip(char **str)
{
	while ((*str)[0] == SPACE)
		(*str)++;
}

/**
 *
 */
char *cut_str_before_space(char *str)
{
	unsigned int idx = 0;
	char *result, chr;

	while (1)
	{
		chr = str[idx];
		if (!(chr != '\0' && chr != SPACE && chr != '\n'))
			break;
		idx++;
	}
	if (idx)
	{
		strncpy(result, str, idx);
		result = strdup(result);
		result[idx] = '\0';
		// while (idx--)
		// 	(*str)++;
		return (result);
	}
	else
		return (strdup(""));
}

int isInt(char *i)
{
	char *end;
	long num = strtol(i, &end, 10);

	if (*end != '\0') {
		return (0);
	}
	return (1);
}

void parseLine(stack_t **h, char *line, const unsigned int lineNumber)
{
	char *opcode, *arg;
	char strLineNumber[BUF_SIZE];

	sprintf(strLineNumber, "%u", lineNumber);
	lstrip(&line);
	opcode = cut_str_before_space(strdup(line));
	line += strlen(opcode);
	if (!strcmp(opcode, "push"))
	{
		lstrip(&line);
		arg = cut_str_before_space(strdup(line));
		if (!isInt(arg))
			exit_with_err(concat(3, "L", strLineNumber, ": usage: push integer\n"));
		__push(h, atoi(arg));
	}
	else if (!strcmp(opcode, "pint"))
		__pint(h);
	else if (!strcmp(opcode, "pop"))
		__pop(h);
	else if (!strcmp(opcode, "swap"))
		__swap(h);
	else if (!strcmp(opcode, "add"))
		__add(h);
	else if (!strcmp(opcode, "nop"))
		__nop(h);
	else if (!strcmp(opcode, "sub"))
		__sub(h);
	else if (!strcmp(opcode, "div"))
		__div(h);
	else if (!strcmp(opcode, "mul"))
		__mul(h);
	else if (!strcmp(opcode, "mod"))
		__mod(h);
	else if (!strcmp(opcode, "pchar"))
		__pchar(h);
	else if (!strcmp(opcode, "pstr"))
		__pstr(h);
	else if (!strcmp(opcode, "rotl"))
		__rotl(h);
	else if (!strcmp(opcode, "rotr"))
		__rotr(h);
	else if (!strcmp(opcode, "stack"))
		__stack(h);
	else if (!strcmp(opcode, "queue"))
		__queue(h);
	else if (!strcmp(opcode, "pall"))
		__pall(h);
	else
		exit_with_err(concat(5, "L", strLineNumber, ": unknown instruction ", opcode, "\n"));
}

int main(int argc, char *argv[])
{
	FILE *filePointer;
	char buffer[BUF_SIZE];
	char *filename;
	unsigned int lineNumber = 1;
	stack = NULL;

	if (argc != 2)
		exit_with_err("USAGE: monty file\n");
	else if (!is_regular_file(argv[1]))
		exit_with_err(strcat(strcat("Error: Can't open file ", argv[1]), "\n"));

	filename = argv[1];
	filePointer = fopen(filename, "r");
	while(fgets(buffer, BUF_SIZE, filePointer))
	{
		parseLine(&stack, buffer, lineNumber);
		lineNumber++;
	}
	free_stack();
	fclose(filePointer);
	return (0);
}
