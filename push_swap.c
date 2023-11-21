/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:12:06 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/21 06:44:33 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int	i;

	a->top = -1;
	b->top = -1;
	i = argc - 1;
	while (i > 0)
	{
		if (!str_is_numeric(argv[i]))
		{
			ft_putstr_fd("Error\n", STDERR_FD);
			return (-1);
		}
		stack_push(a, ft_atoi(argv[i]));
		--i;
	}
	return (0);
}

void	sort1(t_stack *a, t_stack *b)
{
	while (a->top != -1) {
		int tmp = stack_pop(a);
		while (b->top != -1 && b->data[b->top] < tmp) {
			stack_push(a, stack_pop(b));
		}
		stack_push(b, tmp);
	}
}

void	sort2_insert_top(t_stack *s, int top_elem)
{
	if (s->top == -1 || top_elem < s->data[s->top])
	{
		stack_push(s, top_elem);
		return ;
	}
	int temp = stack_pop(s);
	sort2_insert_top(s, top_elem);
	stack_push(s, temp);
}

void	sort2(t_stack *s)
{
	if (s->top > -1)
	{
		int top_elem = stack_pop(s);
		sort2(s);
		sort2_insert_top(s, top_elem);
	}
}

int		search_biggest_elem_idx(t_stack *s)
{
	int	largest_elem_idx;
	int	i;

	largest_elem_idx = 0;
	i = 0;
	while (i <= s->top)
	{
		if (s->data[i] > s->data[largest_elem_idx])
		{
			largest_elem_idx = i;
		}
		++i;
	}
	return (largest_elem_idx);
}

void	mysort1(t_stack *a, t_stack *b)
{
	int	largest_elem_idx_a;
	int	i;

	while (a->top > -1)
	{
		largest_elem_idx_a = search_biggest_elem_idx(a);
		i = 0;
		while (i < (a->top - largest_elem_idx_a))
		{
			ra(a);
			++i;
		}
		pa(a, b);
	}
	while (b->top > -1)
	{
		pb(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (init_stacks(&a, &b, argc, argv) == -1)
		return (-1);
		
	stack_print(&a, "a");
	stack_print(&b, "b");
	// ft_printf("before all\n");
	// sort1(&a, &b);
	// sort2(&a);
	mysort1(&a, &b);

	// ft_printf("after mysort1\n");
	stack_print(&a, "a");
	stack_print(&b, "b");
}
