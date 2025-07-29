#include "printf.h"
#include "libft.h"

static flag_translation	*translate_flag(char *str, va_list args);

char	*handle_input_text(char *str, va_list args, int *print_count)
{
	int					i;
	flag_translation	*translation;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			translation = translate_flag(&str[i], args);
			print_str(translation->content, print_count);
			i += translation->length;
			translation->content = NULL;
			translation->length = 0;
			free(translation);
		}
		else
			print_char(str[i], print_count);
	}
}

static flag_translation	*translate_flag(char *str, va_list args)
{
	flag_translation	*translation;
	char				*corresponding_flag;
	char				*flag_translated;

	corresponding_flag = NULL;
	translation = ft_calloc(1, sizeof(flag_translation));
	if (!is_valid_flag(str))
	{
		translation->content = "%";
		translation->length = 0;
		return (translation);
	}
	corresponding_flag = get_corresponding_flag(str);
	flag_translated = make_tranlation(corresponding_flag, args);
	translation->content = flag_translated;
	translation->length = ft_strlen(flag_translated) - 1;
	free(flag_translated);
	return (translation);
}
