/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_valid_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 05:26:29 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/30 08:47:19 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	join_flags(char **flags, char **complete_flags);

int	is_valid_flag(char *flag)
{
	char	**flags;
	int		len_flags;
	int		is_valid;

	flags = get_valid_flags();
	if (!flags)
		return (0);
	len_flags = 0;
	is_valid = 0;
	while (flags[len_flags])
	{
		if (!is_valid)
			is_valid = !!ft_strnstr(
					flag, flags[len_flags], ft_strlen(flags[len_flags])
					);
		len_flags++;
	}
	free_str_array(flags, len_flags - 1);
	return (is_valid);
}

char	**get_valid_flags(void)
{
	int		len_flags;
	char	**flags;
	char	**complete_flags;

	flags = ft_split("c,s,p,d,i,u,x,X,%", ',');
	if (!flags)
		return (NULL);
	len_flags = str_array_len(flags);
	complete_flags = malloc((len_flags + 1) * sizeof(char *));
	if (!complete_flags)
		return (free_str_array(flags, len_flags - 1));
	if (!join_flags(flags, complete_flags))
		return (NULL);
	return (complete_flags);
}

static int	join_flags(char **flags, char **complete_flags)
{
	int	idx;

	idx = -1;
	while (flags[++idx])
	{
		complete_flags[idx] = ft_strjoin("%", flags[idx]);
		free(flags[idx]);
		if (!complete_flags[idx])
		{
			free(flags);
			free_str_array(complete_flags, idx - 1);
			return (0);
		}
	}
	free(flags);
	complete_flags[idx] = NULL;
	return (1);
}

void	*free_str_array(char **strarr, int idx)
{
	while (idx >= 0)
		free(strarr[idx--]);
	free(strarr);
	return (NULL);
}

int	str_array_len(char **strarr)
{
	int	len;

	len = 0;
	while (strarr[len])
		len++;
	return (len);
}
