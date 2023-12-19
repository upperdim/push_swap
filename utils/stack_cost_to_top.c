/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cost_to_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:02:49 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/18 16:07:48 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
   Return number of operations it is needed to 
   bring the element at `target_idx` on top of stack `s`.
*/
int	cost_to_top(t_stack *s, int target_idx)
{
	if (target_idx > s->top + 1)
		exit_error();
	if (target_idx == s->top + 1)
		return (0);
	if (target_idx >= s-> top / 2)
		return (s->top - target_idx);
	else
		return (target_idx + 1);
}
