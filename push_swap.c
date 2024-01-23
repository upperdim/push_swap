/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:12:06 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/13 16:11:50 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	init_stacks(&a, &b, argc, argv);
	if (stack_is_sorted_asc(&a))
		;
	else if (stack_get_size(&a) == 2)
	{
		if (a.data[1] > a.data[0])
			sa(&a, TRUE);
	}
	else if (stack_get_size(&a) == 3)
		sort3(&a);
	else if (stack_get_size(&a) == 4 || stack_get_size(&a) == 5)
		sortn(&a, &b, a.top + 1);
	else
		mysort(&a, &b);
	free(a.data);
	free(b.data);
	return (0);
}
