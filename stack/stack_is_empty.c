/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:08:24 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/21 17:51:31 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Return whether stack is empty or not. */
int	stack_is_empty(t_stack *s)
{
	if (s == NULL)
	{
		return (exit_error(), 1337);
	}
	return (s->top == -1);
}
