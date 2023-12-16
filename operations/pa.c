/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:23:11 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/16 10:49:34 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Push top of stack `b` to stack `a`. */
void	pa(t_stack *a, t_stack *b)
{
	int	b_top;

	b_top = stack_pop(b);
	stack_push(a, b_top);
	ft_printf("pa\n");
}
