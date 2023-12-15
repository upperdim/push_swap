/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:13:11 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/15 19:11:28 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Swap the top element with the element below it.
	If there are not at least 2 elements, do nothing.
*/
void	stack_swap(t_stack *s)
{
	int	first;
	int	second;

	if (s == NULL)
	{
		exit_error();
	}
	if (stack_is_empty(s))
		return ;
	first = stack_pop(s);
	second = stack_pop(s);
	stack_push(s, first);
	stack_push(s, second);
}
