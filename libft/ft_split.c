/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:49:18 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/26 14:28:09 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**create_array(char const *s, int	*data, int data_len);
static void	free_split(char **str, int end);
static int	write_words(char const *s,
				int *data, int data_len, char **splitted);

char	**ft_split(char const *s, char c)
{
	int	*data;
	int	data_count;
	int	i;

	if (!s)
		return (NULL);
	data = (int *)ft_calloc(ft_strlen((char *)s), sizeof(int));
	if (!data)
		return (NULL);
	data_count = 0;
	i = -1;
	while (s[++i])
	{
		if ((i == 0) && (s[i] != c))
			data[data_count++] = i;
		else if ((i > 0) && (s[i] != c) && (s[i - 1] == c))
			data[data_count++] = i;
		else if ((i > 0) && (s[i] == c && s[i - 1] != c))
			data[data_count++] = i - 1;
		else if ((s[i] != c && s[i + 1] == '\0'))
			data[data_count++] = i;
	}
	if (data_count % 2 != 0)
			data[data_count++] = i - 1;
	return (create_array(s, data, data_count));
}

static char	**create_array(char const *s, int	*data, int data_len)
{
	char	**splitted;

	splitted = (char **)ft_calloc((data_len / 2) + 1, sizeof(char *));
	if (!splitted)
		return (NULL);
	if (!write_words(s, data, data_len, splitted))
		return (NULL);
	free(data);
	splitted[(data_len / 2)] = (void *)0;
	return (splitted);
}

static void	free_split(char **str, int end)
{
	while (end >= 0)
		free(str[end--]);
	free(str);
}

static int	write_words(char const *s, int *data, int data_len, char **splitted)
{
	int	i_words;
	int	i_src;
	int	i_current_word;

	i_words = -1;
	while (++i_words < (data_len / 2))
	{
		splitted[i_words] = malloc(
				data[i_words * 2 + 1] - data[i_words * 2] + 2
				);
		if (!splitted[i_words])
		{
			free_split(splitted, i_words - 1);
			return (0);
		}
		i_src = data[i_words * 2];
		i_current_word = 0;
		while (i_src <= data[i_words * 2 + 1])
			splitted[i_words][i_current_word++] = s[i_src++];
		splitted[i_words][i_current_word] = '\0';
	}
	return (1);
}
