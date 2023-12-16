/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:23:08 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/16 10:49:19 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Push top of stack `a` to stack `b`. */
void	pb(t_stack *a, t_stack *b)
{
	int	a_top;

	a_top = stack_pop(a);
	stack_push(b, a_top);
	ft_printf("pb\n");
}
