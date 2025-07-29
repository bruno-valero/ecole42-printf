/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 05:26:57 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/29 07:04:30 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

/*
compile with:
		cc *.c -I . -I libft -L libft -lft

 */

int main()
{
	int amount_printed = 0;
	amount_printed = ft_printf("ola, meu nome e %s. Gostaria de saber se voce tem %d anos.\n", "Bruno", 10);
	ft_printf("Quantidade printada: %d", amount_printed);
}
