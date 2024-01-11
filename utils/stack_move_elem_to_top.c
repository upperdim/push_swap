/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move_elem_to_top.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:58:51 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:10:01 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack *s, char stack_name)
{
	if (stack_name == 'a')
		ra(s, TRUE);
	else if (stack_name == 'b')
		rb(s, TRUE);
	else
		exit_error(s);
}

static void	reverse_rotate(t_stack *s, char stack_name)
{
	if (stack_name == 'a')
		rra(s, TRUE);
	else if (stack_name == 'b')
		rrb(s, TRUE);
	else
		exit_error(s);
}

/* Move elem with `elem_idx` in stack `s` to the top. */
void	stack_move_elem_to_top(t_stack *s, int elem_idx, char stack_name)
{
	int	i;

	i = elem_idx;
	if (elem_idx >= s-> top / 2)
	{
		while (i < s->top)
		{
			rotate(s, stack_name);
			++i;
		}
	}
	else
	{
		while (i >= 0)
		{
			reverse_rotate(s, stack_name);
			--i;
		}
	}
}
