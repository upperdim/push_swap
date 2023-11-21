/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:13:24 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/21 09:08:49 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Push element `new` to the top of stack `s`. */
void	stack_push(t_stack *s, int new)
{
	if (s == NULL)
	{
		exit_error();
	}
	s->data[++s->top] = new;
}
