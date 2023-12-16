/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move_elem_to_top.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:58:51 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/16 10:59:01 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Move elem with `elem_idx` in stack `s` to the top. */
void	stack_move_elem_to_top(t_stack *s, int elem_idx)
{
	int	i;

	i = 0;
	if (elem_idx > s-> top / 2)
		while (i < s->top - elem_idx)
		{
			ra(s);
			++i;
		}
	else
		while (i <= elem_idx)
		{
			rra(s);
			++i;
		}
}
