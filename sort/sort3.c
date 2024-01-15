/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:00:49 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:11:26 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Sorts stacks with 3 elements. */
void	sort3(t_stack *s)
{
	int	largest_elem_idx;

	largest_elem_idx = stack_get_largest_elem_idx(s);
	if (largest_elem_idx == 0)
	{
		sa(s, TRUE);
		return ;
	}
	else if (largest_elem_idx == 2)
	{
		ra(s, TRUE);
		if (s->data[2] > s->data[1])
			sa(s, TRUE);
		return ;
	}
	else
	{
		rra(s, TRUE);
		if (s->data[2] > s->data[1])
			sa(s, TRUE);
	}
}
