/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:02:52 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/25 15:46:22 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_valid_char(char c, char const *set);
static void		get_coordinates(char const *s1, char const *set, int data[2]);
static int		is_valid_coords(int *coords);
static char		*empty(void);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		data[2];
	char	*str;

	if (!s1 || !set)
		return (NULL);
	if (!ft_strlen(s1))
		return (empty());
	get_coordinates(s1, set, data);
	if (!is_valid_coords(data))
		return (empty());
	str = malloc(data[1] - data[0] + 2);
	if (!str)
		return ((void *)0);
	i = 0;
	while (data[0] <= data[1])
		str[i++] = s1[data[0]++];
	str[i] = '\0';
	return (str);
}

static void	get_coordinates(char const *s1, char const *set, int data[2])
{
	int	i;

	data[0] = -1;
	data[1] = -1;
	i = -1;
	while (s1[++i])
	{
		if (!i && is_valid_char(s1[i], set))
			data[0] = i;
		if (!is_valid_char(s1[i - 1], set) && is_valid_char(s1[i], set))
			data[0] = i;
		if (data[0] >= 0)
			break ;
	}
	i = ft_strlen(s1);
	while (s1[--i])
	{
		if (is_valid_char(s1[i], set) && !s1[i + 1])
			data[1] = i;
		if (is_valid_char(s1[i], set) && !is_valid_char(s1[i + 1], set))
			data[1] = i;
		if (data[1] >= 0)
			break ;
	}
}

static int	is_valid_char(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (0);
	return (1);
}

static int	is_valid_coords(int *coords)
{
	if (coords[0] < 0 || coords[1] < 0)
		return (0);
	return (1);
}

static char	*empty(void)
{
	char	*str;

	str = malloc(1);
	str[0] = '\0';
	return (str);
}
