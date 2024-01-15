/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_rots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:06:12 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:13:18 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
   Perform rr until both a and b are supposed to move up.
   Perform rrr until both a and b are supposed to move down.
*/
void	common_rots(t_stack *a, t_stack *b, int *p_b_elem_i, int *p_a_target_i)
{
	int	a_rot_dir;
	int	b_rot_dir;

	a_rot_dir = stack_get_rotation_direction(a, *p_a_target_i, 'a');
	b_rot_dir = stack_get_rotation_direction(b, *p_b_elem_i, 'b');
	if (a_rot_dir == RA && b_rot_dir == RB)
	{
		while (!(*p_b_elem_i == b->top) && !(*p_a_target_i == a->top))
		{
			++(*p_b_elem_i);
			++(*p_a_target_i);
			rr(a, b, TRUE);
		}
	}
	else if (a_rot_dir == RRA && b_rot_dir == RRB)
	{
		while (*p_b_elem_i >= 0 && *p_a_target_i >= 0)
		{
			--(*p_b_elem_i);
			--(*p_a_target_i);
			rrr(a, b, TRUE);
		}
	}
}
