#include "libft.h"

void print_char(char c, int *print_count)
{
	write(1, &c, 1);
	(*print_count)++;
}

void print_str(char *str, int *print_count)
{
	while (*str)
		print_char(*str++, print_count);
}
