/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_rotation_direction.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:08:06 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/22 15:06:20 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
   Return in which direction element with index `elem_idx` should be rotated 
   in order to be placed at the top of the stack `s`.
*/
int	stack_get_rotation_direction(t_stack *s, int elem_idx, char stack_name)
{
	if (stack_name == 'a')
	{
		if (elem_idx >= s->top / 2)
			return (RA);
		else
			return (RRA);
	}
	else if (stack_name == 'b')
	{
		if (elem_idx >= s->top / 2)
			return (RB);
		else
			return (RRB);
	}
	else
		return (exit_error(s), 1337);
}