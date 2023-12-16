#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		result = malloc(idx + 1);
		memcpy(result, *str, idx);
		result[idx] = '\0';
		(*str) += idx;
	}
	else
	{
		result = malloc(1);
		result[0] = 0;
	}
	return (result);
}

void lstrip(char **str)
{
	while ((*str)[0] == ' ')
		(*str)++;
}

int main() {
   char *str = "      push    6\n";
   char *word = cut_str_before_space(&str);
   lstrip(&str);
   printf("%s\n", word); // prints: asd
   printf("%s\n", str); // prints:
   str = "gggs  \\n";
   lstrip(&str);
   word = cut_str_before_space(&str);
   printf("%s\n", word); // prints: asd
   printf("%s\n", str); // prints:
   free(word); // Don't forget to free the allocated memory
   return 0;
}
