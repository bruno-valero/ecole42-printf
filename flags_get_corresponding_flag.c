/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_get_corresponding_flag.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 05:26:36 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/29 05:30:45 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static void	compare_flags(char **flags, char *flag,
				int *corresponding_flag_idx, int *len_array_flags);

char	*get_corresponding_flag(char *flag)
{
	char	**flags;
	int		len_array_flags;
	int		corresponding_flag_idx;

	flags = get_valid_flags();
	if (!flags)
		return (0);
	len_array_flags = 0;
	compare_flags(flags, flag, &corresponding_flag_idx, &len_array_flags);
	free_str_array(flags, len_array_flags - 1);
	return (flags[corresponding_flag_idx]);
}

static void	compare_flags(char **flags, char *flag,
				int *corresponding_flag_idx, int *len_array_flags)
{
	int	len_current_flag;
	int	len_corresponding_flag;
	int	is_current_flag_valid;

	while (flags[*len_array_flags])
	{
		len_current_flag = ft_strlen(flags[*len_array_flags]);
		len_corresponding_flag = ft_strlen(flags[*corresponding_flag_idx]);
		is_current_flag_valid = !!ft_strnstr(
				flag, flags[*len_array_flags], len_current_flag
				);
		if (is_current_flag_valid && len_corresponding_flag < len_current_flag)
			*corresponding_flag_idx = *len_array_flags;
		(*len_array_flags)++;
	}
}
