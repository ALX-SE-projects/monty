#include "monty.h"

unsigned int LIFO = 1;
stack_t *stack = NULL;


void free_stack(void)
{
	if (stack)
		free_dlistint(stack);
}

void exit_with_err(char *err_msg, unsigned int free_str)
{
	free_stack();
	fprintf(stderr, "%s", err_msg);
	if (free_str)
		free(err_msg);
	exit(EXIT_FAILURE);
}

void *my_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
		exit_with_err("Error: malloc failed\n", 0);
	return (ptr);
}

void *my_realloc(void* ptr, size_t old_size, size_t new_size)
{
   void* new_ptr;
   if (!new_size)
   {
       free(ptr);
       return (NULL);
   }
   new_ptr = my_malloc(new_size);
   if (!new_ptr)
       return (NULL);
   if (ptr)
   {
       size_t copy_size = old_size < new_size ? old_size : new_size;
       memcpy(new_ptr, ptr, copy_size);
       free(ptr);
   }
   return (new_ptr);
}

char *strdup(const char *str)
{
	char *dup = malloc(strlen(str) + 1);

	if (dup)
		strcpy(dup, str);
	return (dup);
}

int is_regular_file(const char *path)
{
	struct stat path_stat;

	if (access(path, F_OK) != -1 && stat(path, &path_stat) == 0)
		return (S_ISREG(path_stat.st_mode));
	return (0);
}

char *concat(int count, ...)
{
	va_list args;
	char *result;
	int i;
	char *str;
	unsigned int len;

	va_start(args, count);
	result = malloc(1);
	result[0] = '\0';
	for (i = 0; i < count; i++)
	{
		str = va_arg(args, char*);
		len = strlen(result);
		result = my_realloc(result, len + 1, len + strlen(str) + 1);
		strcat(result, str);
	}
	va_end(args);
	return (result);
}

void lstrip(char **str)
{
	while ((*str)[0] && (*str)[0] == ' ')
		(*str)++;
}

/**
 *
 */
char *cut_str_before_space(char **str)
{
	int idx = 0;
	char *result, chr;

	while (1)
	{
		chr = (*str)[idx];
		if (!(chr != '\0' && chr != ' ' && chr != '\n'))
			break;
		idx++;
	}
	if (idx)
	{
		result = my_malloc(idx + 1);
		memcpy(result, *str, idx);
		result[idx] = '\0';
		(*str) += idx;
	}
	else
	{
		result = my_malloc(1);
		result[0] = 0;
	}
	return (result);
}

int isInt(char *i)
{
	char *end;

	strtol(i, &end, 10);
	if (*end != '\0')
		return (0);
	return (1);
}

void parseLine(stack_t **h, char **line, const unsigned int lineNumber)
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
			exit_with_err(concat(3, "L", strLineNumber, ": usage: push integer\n"), 1);
		__push(h, atoi(arg));
		free(arg);
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
		exit_with_err(
			concat(5, "L", strLineNumber, ": unknown instruction ", opcode, "\n"),
		1);
	free(opcode);
}

char *createLstrippedString(char *buffer)
{
	unsigned int idx = 0, len;
	char *bufferPtr;

	while (buffer[idx] == ' ')
		idx++;
	len = strlen(buffer);
	if (idx)
	{
		bufferPtr = my_malloc(len - idx + 1);
		memcpy(bufferPtr, buffer + idx, len - idx + 1);
	}
	else
	{
		bufferPtr = my_malloc(len + 1);
		strcpy(bufferPtr, buffer);
	}
	free(buffer);
	return (bufferPtr);
}

int main(int argc, char *argv[])
{
	FILE *filePointer;
	char buffer[BUF_SIZE], *bufferPtr, *bufferPtrReserve, *filename;
	unsigned int lineNumber = 1;

	stack = NULL;
	if (argc != 2)
		exit_with_err("USAGE: monty file\n", 0);
	else if (!is_regular_file(argv[1]))
		exit_with_err(concat(3, "Error: Can't open file ", argv[1], "\n"), 1);
	filename = argv[1];
	filePointer = fopen(filename, "r");
	while (fgets(buffer, BUF_SIZE, filePointer))
	{
		bufferPtr = createLstrippedString(strdup(buffer));
		bufferPtrReserve = bufferPtr;
		if (strcmp("\n", bufferPtr))
			parseLine(&stack, &bufferPtr, lineNumber);
		lineNumber++;
		free(bufferPtrReserve);
	}
	free_stack();
	fclose(filePointer);
	return (0);
}
