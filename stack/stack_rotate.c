/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:13:17 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/15 15:13:43 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Shift all elements of the stack up by 1.
	First element goes up, rotates around, and becomes the last one.
*/
void	stack_rotate(t_stack *s)
{
	size_t	i;
	int		old_top;

	old_top = s->data[s->top];
	i = s->top;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		--i;
	}
	s->data[0] = old_top;
}
