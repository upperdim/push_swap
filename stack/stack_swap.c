/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:13:11 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/15 15:15:36 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Swap the top element with the element below it.
	If there are not at least 2 elements, do nothing.
*/
void	stack_swap(t_stack *s)
{
	int	first;
	int	second;

	if (s->top < 1)
		return ;
	first = pop(s);
	second = pop(s);
	push(s, first);
	push(s, second);
}
