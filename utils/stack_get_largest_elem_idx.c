/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_largest_elem_idx.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:24:22 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/21 08:24:47 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Return index of the largest element in the stack. */
int		stack_get_largest_elem_idx(t_stack *s)
{
	int	largest_elem_idx;
	int	i;

	largest_elem_idx = 0;
	i = 0;
	while (i <= s->top)
	{
		if (s->data[i] > s->data[largest_elem_idx])
		{
			largest_elem_idx = i;
		}
		++i;
	}
	return (largest_elem_idx);
}
