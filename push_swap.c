/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:12:06 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/21 07:50:53 by tunsal           ###   ########.fr       */
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
		pb(a, b);
		++i;
	}
	return (0);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
	{
		if (s->data[i] < s->data[i + 1])
			return (0);
		++i;
	}
	return (1);
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

int		search_smallest_elem_idx(t_stack *s)
{
	int	largest_elem_idx;
	int	i;

	largest_elem_idx = 0;
	i = 0;
	while (i <= s->top)
	{
		if (s->data[i] < s->data[largest_elem_idx])
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
		largest_elem_idx_a = search_smallest_elem_idx(a);
		if (largest_elem_idx_a > a->top / 2)
		{
			i = largest_elem_idx_a;
			while (i < a->top)
			{
				ra(a);
				ft_printf("ra\n");
				++i;
			}
			pa(a, b);
			ft_printf("pa\n");
		}
		else
		{
			i = largest_elem_idx_a;
			while (i >= 0)
			{
				rra(a);
				ft_printf("rra\n");
				--i;
			}
			pa(a, b);
			ft_printf("pa\n");
		}
	}
	while (b->top > -1)
	{
		pb(a, b);
		ft_printf("pb\n");
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
	if (is_sorted(&a))
		return (0);
	mysort1(&a, &b);
	stack_print(&a, "a");
	stack_print(&b, "b");
}
