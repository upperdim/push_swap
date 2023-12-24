/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find_target_idx.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:04:24 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/24 19:13:07 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*  Return the index which `num` will be placed on top of at stack `s`. */
int	stack_find_target_idx(t_stack *s, int num)
{
	int	i;
	int	smallest_elem_idx;
	int	largest_elem_idx;

	smallest_elem_idx = stack_get_smallest_elem_idx(s);
	if (num < s->data[smallest_elem_idx])
		return (smallest_elem_idx);
	largest_elem_idx = stack_get_largest_elem_idx(s);
	if (num > s->data[largest_elem_idx])
	{
		if (largest_elem_idx == 0)
			return (s->top);
		else
			return (largest_elem_idx - 1);
	}
	i = 1;
	while (i <= s->top)
	{
		if (num < s->data[i - 1] && num > s->data[i])
			return (i - 1);
		++i;
	}
	if (num < s->data[s->top] && num > s->data[0])
		return (s->top);
	return (exit_error(s), 1337);
}
