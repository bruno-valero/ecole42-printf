/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:02:52 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/25 15:46:26 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		size;
	int		len_str;
	char	*sub;

	if ((!s && !start))
		return (NULL);
	len_str = ft_strlen(s);
	if (!s || (start > (unsigned int)len_str))
	{
		sub = (char *)ft_calloc(1, 1);
		return (sub);
	}
	if (len < (len_str - start))
		size = len;
	else
		size = len_str - start;
	sub = (char *)ft_calloc(size + 1, 1);
	if (!sub)
		return (((void *)0));
	i = 0;
	while ((i < size) && s[start])
		sub[i++] = s[start++];
	return (sub);
}
