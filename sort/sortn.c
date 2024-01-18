/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:00:39 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:11:08 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Sort stack a with element count n. */
void	sortn(t_stack *a, t_stack *b, int n)
{
	int	smallest_idx;

	if (n == 3)
	{
		sort3(a);
		return ;
	}
	smallest_idx = stack_get_smallest_elem_idx(a);
	stack_move_elem_to_top(a, smallest_idx, 'a');
	if (stack_is_sorted_asc(a))
		return ;
	pb(a, b, TRUE);
	sortn(a, b, n - 1);
	pa(a, b, TRUE);
}
