/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_ntoa_support.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 05:26:43 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/29 17:56:01 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_base(char *result, char *base, int len_nbr, unsigned long number)
{
	int	len_base;

	len_base = ft_strlen(base);
	while (len_nbr--)
	{
		result[len_nbr] = base[number % len_base];
		number /= len_base;
	}
}

int	is_valid_base(char *base)
{
	int	i;
	int	i_verify_repeated;

	if (!base)
		return (0);
	i = -1;
	while (base[++i] != '\0')
	{
		if (!(base[i] > 32 && base[i] < 127)
			|| (base[i] == '+' || base[i] == '-'))
			return (0);
		i_verify_repeated = i;
		while (base[++i_verify_repeated] != '\0')
			if (base[i] == base[i_verify_repeated])
				return (0);
	}
	if (i < 2)
		return (0);
	return (1);
}

int	nbrlen(unsigned long nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}
