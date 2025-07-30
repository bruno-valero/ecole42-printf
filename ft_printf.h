/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:33:15 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/30 09:02:33 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct param_data
{
	char	*content;
	int		length;
	int		is_end_line;
	int		is_error;
}			t_flag_translation;

void	*free_str_array(char **strarr, int idx);
int		str_array_len(char **strarr);
void	print_char(char c, int *print_count);
void	print_str(char *str, int *print_count, int print_end_line);
char	**get_valid_flags(void);
int		is_valid_flag(char *flag);
char	*get_corresponding_flag(char *flag);
void	handle_base(char *result, char *base,
			int len_nbr, unsigned long number);
int		is_valid_base(char *base);
int		nbrlen(unsigned long nbr, int base_len);
char	*itoa_base(int nbr, char *base);
char	*utoa_base(unsigned int nbr, char *base);
char	*ultoa_base(unsigned long nbr, char *base);
char	*ptoa(va_list args);
char	*make_tranlation(char *flag, va_list args);
void	text_input_translate_and_print(
			char *str, va_list args, int *print_count
			);
int		ft_printf(const char *str, ...);

#endif
