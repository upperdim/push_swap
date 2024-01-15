/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:08:46 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/13 16:09:58 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Return number of elements present in the stack. */
int	stack_get_size(t_stack *s)
{
	if (s == NULL)
		exit_error(s);
	return (s->top + 1);
}
