/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 05:26:54 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/29 17:48:55 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *print_count)
{
	write(1, &c, 1);
	(*print_count)++;
}

void	print_str(char *str, int *print_count, int print_end_line)
{
	if (!*str && print_end_line)
		print_char('\0', print_count);
	else if (!*str && !print_end_line)
		return ;
	while (*str)
		print_char(*str++, print_count);
}
