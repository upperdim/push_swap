/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:05:18 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/18 07:04:38 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_print(t_stack *s, char *name, int print_name)
{
	int	i;

	if (print_name)
		ft_printf("%s: ", name);
	i = s->top;
	while (i > 0)
	{
		ft_printf("%d, ", s->data[i]);
		--i;
	}
	if (s->top >= 0)
		ft_printf("%d", s->data[0]);
	ft_putchar('\n');
}
