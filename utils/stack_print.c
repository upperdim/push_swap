/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:05:18 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/21 06:44:05 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_print(t_stack *s, char *name)
{
	int	i;

	if (name != NULL)
		ft_printf("%s: ", name);
	i = 0;
	while (i < s->top)
	{
		ft_printf("%d, ", s->data[i]);
		++i;
	}
	if (s->top >= 0)
		ft_printf("%d ", s->data[s->top]);
	ft_printf("<- top");
	ft_putchar('\n');
}
