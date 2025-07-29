/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_input_translation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:56:34 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/29 16:03:06 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static t_flag_translation	*translate_flag(char *str, va_list args);
static void					print_list(t_list *lst, int *print_count);

void	text_input_translate_and_print(
		char *str, va_list args, int *print_count
		)
{
	int					i;
	t_flag_translation	*translation;
	t_list				*char_list;
	t_list				*list_next;

	char_list = ft_lstnew(NULL);
	if (!char_list)
		return ;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			translation = translate_flag(&str[i], args);
			if (translation->is_error)
			{
				ft_lstclear(&char_list, free_tanslation);
				*print_count = -1;
				return ;
			}
			if (!char_list->content)
				char_list->content = translation;
			else
			{
				list_next = ft_lstnew(translation);
				if (!list_next)
					return (ft_lstclear(&char_list, free_tanslation));
				ft_lstadd_back(&char_list, list_next);
			}
			// print_str(translation->content, print_count,
			// 	translation->is_end_line);
			i += translation->length;
			free(translation->content);
			translation->length = 0;
			// free(translation);
			if (!str[i])
				break ;
		}
		else
		{
			translation = malloc(sizeof(t_flag_translation));

			if (!char_list->content)
				char_list->content = translation;
			else
			{
				translation->content = char_to_str(str[i]);
				list_next = ft_lstnew(translation);
				if (!list_next)
					return (ft_lstclear(&char_list, free_tanslation));
				ft_lstadd_back(&char_list, list_next);
			}
			// print_char(str[i], print_count);
		}
		print_list(char_list, print_count);
	}
}

static t_flag_translation	*translate_flag(char *str, va_list args)
{
	t_flag_translation	*translation;
	char				*corresponding_flag;
	char				*flag_translated;

	corresponding_flag = NULL;
	translation = ft_calloc(1, sizeof(t_flag_translation));
	translation->is_error = 0;
	if (!is_valid_flag(str))
	{
		translation->content = ft_strdup("%");
		translation->length = 0;
		if (str[1] == '\0' || str[1] == ' ')
			translation->is_error = 1;
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

void	free_tanslation(t_flag_translation *translation)
{
	free(translation->content);
	free(translation);
}

static void	print_list(t_list *lst, int *print_count)
{
	t_flag_translation	*translation;
	t_list				*temp;

	temp = lst;
	translation = NULL;
	if (!temp)
		return (print_str("(nil)", print_count, 0));
	while (temp)
	{
		translation = (t_flag_translation *)temp->content;
		print_str(translation, print_count, translation->is_end_line);
		temp = temp->next;
	}
	ft_lstclear(lst, free_tanslation);
}
