/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:49:18 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/18 07:13:20 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbrlen(long int nbr, int is_negative);
static void		strreverse(char *str);
static void		change_number(int is_negative, long int nbr, char *str_nbr);
static void		handle_negative(int *is_negative, long int *nbr);

char	*ft_itoa(int n)
{
	int			is_negative;
	long int	nbr;
	char		*str_nbr;

	is_negative = 0;
	nbr = (long int)n;
	handle_negative(&is_negative, &nbr);
	if (n == 0)
	{
		str_nbr = ft_calloc(2, 1);
		if (!str_nbr)
			return ((void *)0);
		ft_strlcpy(str_nbr, "0", 2);
		return (str_nbr);
	}
	str_nbr = ft_calloc(nbrlen(nbr, is_negative) + 1, 1);
	if (!str_nbr)
		return ((void *)0);
	change_number(is_negative, nbr, str_nbr);
	return (str_nbr);
}

static int	nbrlen(long int nbr, int is_negative)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len + is_negative);
}

static void	strreverse(char *str)
{
	int		i;
	int		len;
	char	temp;

	len = ft_strlen(str);
	i = -1;
	temp = 0;
	while (++i < len)
	{
		temp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = temp;
		len--;
	}
}

static void	change_number(int is_negative, long int nbr, char *str_nbr)
{
	int	temp;
	int	i;

	i = 0;
	temp = 0;
	while (nbr > 0)
	{
		temp = nbr % 10;
		str_nbr[i++] = temp + '0';
		nbr /= 10;
	}
	if (is_negative)
		str_nbr[i++] = '-';
	strreverse(str_nbr);
	str_nbr[i] = '\0';
}

static void	handle_negative(int *is_negative, long int *nbr)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		*is_negative = 1;
	}
	else
		*is_negative = 0;
}
