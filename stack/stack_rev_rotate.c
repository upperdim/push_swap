/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:12:53 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/21 09:09:28 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Shift all elements of the stack down by 1.
	Last element goes down, rotates around, and becomes the top.
*/
void	stack_rev_rotate(t_stack *s)
{
	int	i;
	int	old_bottom;

	if (s == NULL)
	{
		exit_error();
	}
	old_bottom = s->data[0];
	i = 0;
	while (i < s->top)
	{
		s->data[i] = s->data[i + 1];
		++i;
	}
	s->data[s->top] = old_bottom;
}
