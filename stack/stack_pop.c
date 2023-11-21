/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:13:28 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/21 09:15:09 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Pop an element from the top of stack `s` and return it. */
int	stack_pop(t_stack *s)
{
	if (s == NULL || s->top <= -1)
	{
		exit_error();
	}
	return (s->data[s->top--]);
}
