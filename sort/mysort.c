/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:02:42 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/16 11:03:26 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
   Return number of operations it is needed to 
   bring the element at `target_idx` on top of stack `s`.
*/
static int	cost(t_stack *s, int target_idx)
{
	if (target_idx <= s->top / 2)
		return (s->top - target_idx);
	else
		return (target_idx);
}

/* Return at which index `num` should be in stack `b`. Error=unreachable code*/
static int	find_target_idx(t_stack *b, int num)
{
	int i;

	if (num > b->data[b->top])
		return (b->top + 1);
	else if (b->data[0] > num)
		return (0);
	else
	{
		i = 1;
		while (i < b->top - 1)
		{
			if (num > b->data[i - 1] && num < b->data[i])
				return (i);
			++i;
		}
	}
	exit_error();
	return (1337);
}

/* 
   Move element with index `a_elem_idx` in stack `a` 
   to the correct position in stack `b`.
*/
static void	a_to_b(t_stack *a, t_stack *b, int a_elem_idx)
{
	stack_move_elem_to_top(a, a_elem_idx);
	stack_move_elem_to_top(b, find_target_idx(b, a->data[a_elem_idx]));
	pb(a, b);
}

void	mysort(t_stack *a, t_stack *b)
{
	int	*costs;
	int	smallest_cost_idx;
	int	i;
	int	target_idx;

	pb(a, b);
	pb(a, b);
	while (!stack_is_empty(a))
	{
		costs = (int *) ft_calloc(a->top + 1, sizeof(int));
		if (costs == NULL)
			exit_error();
		i = 0;
		while (i <= a->top)
		{
			target_idx = find_target_idx(b, a->data[i]);
			costs[i] = cost(a, i) + cost(b, target_idx) + 1;
			++i;
		}
		smallest_cost_idx = arr_min_idx(costs, a->top + 1);
		a_to_b(a, b, smallest_cost_idx);
		// put it into the correct place in stack B
	}
}
