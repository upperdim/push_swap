/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:12:06 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:23:30 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	init_stacks(&a, &b, argc, argv);
	if (stack_is_sorted_asc(&a))
		return (0);
	if (a.top == 1)
	{
		if (a.data[1] > a.data[0])
			sa(&a, TRUE);
	}
	else if (a.top == 2)
		sort3(&a);
	else if (a.top == 3 || a.top == 4)
		sortn(&a, &b, a.top + 1);
	else
		mysort(&a, &b);
	free(a.data);
	free(b.data);
	return (0);
}
