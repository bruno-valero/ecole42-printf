/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_get_corresponding_flag.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 05:26:36 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/29 13:11:50 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	compare_flags(char **flags, char *flag,
				int *corresponding_flag_idx, int *len_array_flags);

char	*get_corresponding_flag(char *flag)
{
	char	**flags;
	int		len_array_flags;
	int		corresponding_flag_idx;
	char	*corresponding_flag;

	flags = get_valid_flags();
	if (!flags)
		return (0);
	len_array_flags = 0;
	compare_flags(flags, flag, &corresponding_flag_idx, &len_array_flags);
	if (corresponding_flag_idx == -1)
		return (free_str_array(flags, len_array_flags - 1));
	corresponding_flag = ft_strdup(flags[corresponding_flag_idx]);
	free_str_array(flags, len_array_flags - 1);
	return (corresponding_flag);
}

static void	compare_flags(char **flags, char *flag,
				int *corresponding_flag_idx, int *len_array_flags)
{
	int	len_current_flag;
	int	len_corresponding_flag;
	int	is_current_flag_valid;

	*corresponding_flag_idx = -1;
	len_corresponding_flag = 0;
	while (flags[*len_array_flags])
	{
		len_current_flag = ft_strlen(flags[*len_array_flags]);
		if (*corresponding_flag_idx >= 0)
			len_corresponding_flag = ft_strlen(flags[*corresponding_flag_idx]);
		is_current_flag_valid = !!ft_strnstr(
				flag, flags[*len_array_flags], len_current_flag
				);
		if (is_current_flag_valid
			&& (len_corresponding_flag < len_current_flag))
			*corresponding_flag_idx = *len_array_flags;
		(*len_array_flags)++;
	}
}
