/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_smallest_elem_idx.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:12:32 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/21 08:24:09 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Return index of the smallest element in the stack. */
int		stack_get_smallest_elem_idx(t_stack *s)
{
	int	smallest_elem_idx;
	int	i;

	smallest_elem_idx = 0;
	i = 0;
	while (i <= s->top)
	{
		if (s->data[i] < s->data[smallest_elem_idx])
		{
			smallest_elem_idx = i;
		}
		++i;
	}
	return (smallest_elem_idx);
}
