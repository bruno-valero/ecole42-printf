#include "printf.h"
#include "libft.h"

static data_to_print	*translate(char *str, va_list args);

char	*handle_input_text(char *str, va_list args, int *print_count)
{
	int				i;
	data_to_print	*data;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			data = translate(&str[i], args);
			print_str(data->str_to_print, print_count);
			i += data->length_of_symbol;
			data->str_to_print = NULL;
			data->length_of_symbol = NULL;
			free(data);
		}
		else
			print_char(str[i], print_count);
	}
}

static data_to_print	*translate(char *str, va_list args)
{
	data_to_print	*data;
	char			*corresponding_flag;

	corresponding_flag = NULL;
	data = ft_calloc(1, sizeof(data_to_print));
	if (!is_valid_flag(str))
	{
		data->str_to_print = "%";
		data->length_of_symbol = 0;
		return (data);
	}
	corresponding_flag = get_corresponding_flag(str);
	return (data);
}
