/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:23:08 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:06:22 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Push top of stack `a` to stack `b`. */
void	pb(t_stack *a, t_stack *b, int print)
{
	int	a_top;

	a_top = stack_pop(a);
	stack_push(b, a_top);
	if (print)
		ft_printf("pb\n");
}
