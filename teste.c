/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 05:26:57 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/29 09:11:05 by brunofer         ###   ########.fr       */
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
	//amount_printed = ft_printf("ola, meu nome e %s. Gostaria de saber se voce tem %d anos.\n", "Bruno", 10);
	//ft_printf("Quantidade printada: %d", amount_printed);

	int l = ft_printf("char=%c, int(d)=%d, int(i)=%i, ui=%u, str=%s, ptr=%p, ui_to_hex=%x, UI_TO_HEX=%X, percentage='me de 10%% de desconto'\n", '6', 897, -989, 1500, "(uma str)", &amount_printed, 561, 561);
	int pl = printf("char=%c, int(d)=%d, int(i)=%i, ui=%u, str=%s, ptr=%p, ui_to_hex=%x, UI_TO_HEX=%X, percentage='me de 10%% de desconto'\n", '6', 897, -989, 1500, "(uma str)", &amount_printed, 561, 561);
	printf("print amount -> ft_print = %d, print = %d", l, pl);
	return (0);
}
