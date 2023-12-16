#include "monty.h"

/**
 * concat - concatinate string arguments into one new big string
 * @h: stack to be freed on NULL return of malloc
 * @count: count of passed variadic arguments
 *
 * Return: new string (should get free() when no longer needed)
 */
char *concat(stack_t **h, int count, ...)
{
	va_list args;
	char *result;
	int i;
	char *str;
	unsigned int len;

	va_start(args, count);
	result = my_malloc(1, h);
	result[0] = '\0';
	for (i = 0; i < count; i++)
	{
		str = va_arg(args, char*);
		len = strlen(result);
		result = my_realloc(result, len + 1, len + strlen(str) + 1, h);
		strcat(result, str);
	}
	va_end(args);
	return (result);
}

/**
 * lstrip - left-strip a string from spaces
 * @str: ptr to string
 */
void lstrip(char **str)
{
	while ((*str)[0] && (*str)[0] == ' ')
		(*str)++;
}

/**
 * cut_str_before_space - extract the word on the left before spaces
 * @str: ptr to string
 * @h: stack to be freed on NULL return of malloc
 *
 * Return: new string (should get free() when no longer needed)
 */
char *cut_str_before_space(char **str, stack_t **h)
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
		result = my_malloc(idx + 1, h);
		memcpy(result, *str, idx);
		result[idx] = '\0';
		(*str) += idx;
	}
	else
	{
		result = my_malloc(1, h);
		result[0] = 0;
	}
	return (result);
}

/**
 * isInt - checks if a string is a valid integer
 * @i: string to check
 *
 * Return: bool
 */
int isInt(char *i)
{
	char *end;

	strtol(i, &end, 10);
	if (*end != '\0')
		return (0);
	return (1);
}

/**
 * createLstrippedString - create new string whose removed spaces on the left
 * @buffer: string
 * @h: stack to be freed on NULL return of malloc
 *
 * Return: new string (should get free() when no longer needed)
 */
char *createLstrippedString(char *buffer, stack_t **h)
{
	unsigned int idx = 0, len;
	char *bufferPtr;

	while (buffer[idx] == ' ')
		idx++;
	len = strlen(buffer);
	if (idx)
	{
		bufferPtr = my_malloc(len - idx + 1, h);
		memcpy(bufferPtr, buffer + idx, len - idx + 1);
	}
	else
	{
		bufferPtr = my_malloc(len + 1, h);
		strcpy(bufferPtr, buffer);
	}
	free(buffer);
	/*
	* Every good language comes with the capability of commenting.
	* When the first non-space character of a line is #,
	* treat this line as a comment (don’t do anything).
	*/
	if (bufferPtr[0] == '#')
	{
		buffer[0] = '\n';
		buffer[1] = '\0';
	}
	return (bufferPtr);
}
