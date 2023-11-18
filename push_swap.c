/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:12:06 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/18 07:03:31 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_set_empty(t_stack *s)
{
	s->top = -1;
}

void	init_stacks(t_stack *a, t_stack *b)
{
	stack_set_empty(a);
	stack_set_empty(b);
}

int	main(int argc, char *argv[])
{
	(void) argv;
	t_stack	a;
	t_stack	b;
	int	i;

	init_stacks(&a, &b);
	i = 1;
	while (i < argc)
	{
		if (!str_is_numeric(argv[i]))
			return (1);
		stack_push(&b, ft_atoi(argv[i]));
		++i;
	}
	i = 1;
	while (i < argc)
	{
		pa(&a, &b);
		++i;
	}
	stack_print(&a, "a", 1);
	stack_print(&b, "b", 1);
}
