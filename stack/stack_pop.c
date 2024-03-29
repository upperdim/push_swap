/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:13:28 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/22 15:03:37 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Pop an element from the top of stack `s` and return it. */
int	stack_pop(t_stack *s)
{
	if (s == NULL || stack_is_empty(s))
	{
		exit_error(s);
	}
	return (s->data[s->top--]);
}
