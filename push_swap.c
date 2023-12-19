/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:12:06 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/18 13:58:45 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i <= s->top)
	{
		j = i + 1;
		while (j < s->top)
		{
			if (s->data[i] == s->data[j])
				exit_error();
			++j;
		}
		++i;
	}
}

void	init_stacks(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int	i;

	a->top = -1;
	b->top = -1;
	i = 1;
	while (i < argc)
	{
		if (!str_is_numeric(argv[i]))
			exit_error();
		stack_push(b, ft_atoi(argv[i]));
		++i;
	}
	i = 1;
	while (i < argc)
	{
		stack_push(a, stack_pop(b));
		++i;
	}
	check_duplicates(a);
}

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
			sa(&a);
	}
	else if (a.top == 2)
		sort3(&a);
	else if (a.top == 3 || a.top == 4)
		sortn(&a, &b, a.top + 1);
	else
		mysort(&a, &b);
	return (0);
}
