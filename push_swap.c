/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:12:06 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/13 09:58:20 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_duplicates(t_stack *s)
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

void	mysort(t_stack *a, t_stack *b)
{
	int	smallest_elem_idx_a;
	int	i;

	while (a->top > -1)
	{
		smallest_elem_idx_a = stack_get_smallest_elem_idx(a);
		if (smallest_elem_idx_a > a->top / 2)
		{
			i = smallest_elem_idx_a;
			while (i < a->top)
			{
				ra(a);
				++i;
			}
			pb(a, b);
		}
		else
		{
			i = smallest_elem_idx_a;
			while (i >= 0)
			{
				rra(a);
				--i;
			}
			pb(a, b);
		}
	}
	while (b->top > -1)
		pa(a, b);
}

void	sort2(t_stack *s)
{
	if (s->data[1] > s->data[0])
		sa(s);
}

/* Sorts stacks with 3 elements. */
void	sort3(t_stack* s)
{
	int largest_elem_idx;

	largest_elem_idx = stack_get_largest_elem_idx(s);
	if (largest_elem_idx == 0)
	{
		sa(s);
		return ;
	}
	else if (largest_elem_idx == 2)
	{
		ra(s);
		if (s->data[2] > s->data[1])
			sa(s);
		return ;
	}
	else{
		rra(s);
		if (s->data[2] > s->data[1])
			sa(s);
	}
}

/* Sort stack a with element count n. */
void	sort_n(t_stack *a, t_stack *b, int n)
{
	int	smallest_idx;
	int	i;

	if (n == 3)
	{
		sort3(a);
		return ;
	}
	smallest_idx = stack_get_smallest_elem_idx(a);
	i = 0;
	if (smallest_idx > a->top / 2)
	{
		while (i++ < n - smallest_idx - 1)
			ra(a);
	}
	else
	{
		while (i++ <= smallest_idx)
			rra(a);
	}
	if (stack_is_sorted_asc(a))
		return ;
	pb(a, b);
	sort_n(a, b, n - 1);
	pa(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	init_stacks(&a, &b, argc, argv);

	// stack_print(&a, "a");
	// stack_print(&b, "b");

	if (stack_is_sorted_asc(&a))
		return (0);
	if (a.top == 1)
		sort2(&a);
	else if (a.top == 2)
		sort3(&a);
	else
		sort_n(&a, &b, a.top + 1);

	// stack_print(&a, "a");
	// stack_print(&b, "b");
	return (0);
}
