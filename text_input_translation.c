/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_input_translate_and_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 05:26:48 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/29 07:17:47 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static t_flag_translation	*translate_flag(char *str, va_list args);

void	text_input_translate_and_print(
		char *str, va_list args, int *print_count
		)
{
	int					i;
	t_flag_translation	*translation;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			translation = translate_flag(&str[i], args);
			print_str(translation->content, print_count,
				translation->is_end_line);
			i += translation->length;
			free(translation->content);
			translation->length = 0;
			free(translation);
			if (!str[i])
				break ;
		}
		else
			print_char(str[i], print_count);
	}
}

static t_flag_translation	*translate_flag(char *str, va_list args)
{
	t_flag_translation	*translation;
	char				*corresponding_flag;
	char				*flag_translated;

	corresponding_flag = NULL;
	translation = ft_calloc(1, sizeof(t_flag_translation));
	if (!is_valid_flag(str))
	{
		translation->content = ft_strdup("%");
		translation->length = 0;
		return (translation);
	}
	corresponding_flag = get_corresponding_flag(str);
	flag_translated = make_tranlation(corresponding_flag, args);
	translation->content = ft_strdup(flag_translated);
	translation->length = ft_strlen(corresponding_flag) - 1;
	translation->is_end_line = !ft_strncmp(corresponding_flag, "%c", 2);
	free(corresponding_flag);
	free(flag_translated);
	return (translation);
}
