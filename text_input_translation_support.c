/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_input_translation_support.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 05:26:33 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/30 10:18:01 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*basic_flags_tranlation(char *flag, va_list args);
static char	*char_to_str(char c);
static char	*handle_str(char *str);

char	*make_tranlation(char *flag, va_list args)
{
	if (ft_strlen(flag) == 2)
		return (basic_flags_tranlation(flag, args));
	return (NULL);
}

static char	*basic_flags_tranlation(char *flag, va_list args)
{
	int		flag_len;

	flag_len = 2;
	if (!ft_strncmp("%c", flag, flag_len))
		return (char_to_str((char)va_arg(args, int)));
	if (!ft_strncmp("%s", flag, flag_len))
		return (handle_str(va_arg(args, char *)));
	if (!ft_strncmp("%d", flag, flag_len) || !ft_strncmp("%i", flag, flag_len))
		return (itoa_base(va_arg(args, int), "0123456789"));
	if (!ft_strncmp("%u", flag, flag_len))
		return (utoa_base(va_arg(args, unsigned int), "0123456789"));
	if (!ft_strncmp("%x", flag, flag_len))
		return (utoa_base(va_arg(args, unsigned int), "0123456789abcdef"));
	if (!ft_strncmp("%X", flag, flag_len))
		return (utoa_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (!ft_strncmp("%p", flag, flag_len))
		return (ptoa(args));
	if (!ft_strncmp("%%", flag, flag_len))
		return (ft_strdup("%"));
	return (NULL);
}

static char	*char_to_str(char c)
{
	char	*str;

	str = malloc(2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

static char	*handle_str(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}
