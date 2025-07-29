#include "printf.h"
#include "libft.h"

int ft_printf(char *str, ...)
{
	va_list	args;
	int		print_count;

	print_count = 0;
	va_start(args, str);
	handle_input_text(str, args, &print_count);
	va_end(args);
	return (print_count);
}
