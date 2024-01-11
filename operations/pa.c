/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:23:11 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:06:11 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Push top of stack `b` to stack `a`. */
void	pa(t_stack *a, t_stack *b, int print)
{
	int	b_top;

	b_top = stack_pop(b);
	stack_push(a, b_top);
	if (print)
		ft_printf("pa\n");
}
