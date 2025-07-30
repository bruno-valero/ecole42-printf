/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 05:26:14 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/29 17:48:52 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_count;

	print_count = 0;
	va_start(args, str);
	text_input_translate_and_print((char *)str, args, &print_count);
	va_end(args);
	return (print_count);
}
