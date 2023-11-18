/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:12:06 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/18 07:12:38 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int	i;

	a->top = -1;
	b->top = -1;
	i = 1;
	while (i < argc)
	{
		if (!str_is_numeric(argv[i]))
		{
			ft_putstr_fd("Error\n", STDERR_FD);
			return (-1);
		}
		stack_push(b, ft_atoi(argv[i]));
		++i;
	}
	i = 1;
	while (i < argc)
	{
		pa(a, b);
		++i;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (init_stacks(&a, &b, argc, argv) == -1)
		return (-1);
}
