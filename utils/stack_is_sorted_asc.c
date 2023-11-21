/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:13:32 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/21 08:13:59 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Return whether stack is sorted in ascending order or not. */
int	stack_is_sorted_asc(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
	{
		if (s->data[i] < s->data[i + 1])
			return (0);
		++i;
	}
	return (1);
}
