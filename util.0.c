#include "monty.h"

/**
 * exit_with_err - exit(1) with err msg
 * @err_msg: error msg
 * @free_str: bool if err_msg should get free()
 * @stack: head of list
 */
void exit_with_err(char *err_msg, unsigned int free_str, stack_t **stack)
{
	free_dlistint(stack);
	fprintf(stderr, "%s", err_msg);
	if (free_str)
		free(err_msg);
	exit(EXIT_FAILURE);
}

/**
 * my_malloc - custom malloc that handles NULL return
 * @size: size of memory to be allocated
 * @h: stack to be freed on NULL return of malloc
 *
 * Return: void pointer
 */
void *my_malloc(size_t size, stack_t **h)
{
	void *ptr = malloc(size);

	if (!ptr)
		exit_with_err("Error: malloc failed\n", 0, h);
	return (ptr);
}

/**
 * my_realloc - custom realloc that handles NULL return
 * @ptr: pointer to mem to
 * @old_size: current size of @ptr be realocatted
 * @new_size: new size
 * @h: stack to be freed on NULL return of malloc
 *
 * Return: void pointer
 */
void *my_realloc(void *ptr, size_t old_size, size_t new_size, stack_t **h)
{
	void *new_ptr;
	size_t copy_size;

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = my_malloc(new_size, h);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		copy_size = old_size < new_size ? old_size : new_size;
		memcpy(new_ptr, ptr, copy_size);
		free(ptr);
	}
	return (new_ptr);
}

/**
 * strdup - duplicate a string
 * @str: string to duplicate
 * @h: stack to be freed on NULL return of malloc
 *
 * Return: new string (should get free() when no longer needed)
 */
char *strdup(const char *str, stack_t **h)
{
	char *dup = my_malloc(strlen(str) + 1, h);

	if (dup)
		strcpy(dup, str);
	return (dup);
}

/**
 * is_regular_file - checks if @path is a file (not a dir)
 *   and that file can be read
 * @path: path to file
 *
 * Return: bool
 */
int is_regular_file(const char *path)
{
	struct stat path_stat;

	if (access(path, F_OK) != -1 && stat(path, &path_stat) == 0)
		return (S_ISREG(path_stat.st_mode));
	return (0);
}
