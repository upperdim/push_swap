/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:22:42 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:07:36 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_stack *a, t_stack *b, int print)
{
	stack_rev_rotate(a);
	stack_rev_rotate(b);
	if (print)
		ft_printf("rrr\n");
}
