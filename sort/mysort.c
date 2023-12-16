/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:02:42 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/16 19:35:41 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
   Return number of operations it is needed to 
   bring the element at `target_idx` on top of stack `s`.
*/
static int	cost_to_top(t_stack *s, int target_idx)
{
	if (target_idx > s->top + 1)
		exit_error();
	if (target_idx == s->top + 1)
		return (0);
	if (target_idx >= s-> top / 2)
		return (s->top - target_idx);
	else
		return (target_idx + 1);
}

/* 
   Return the index which `num` will be placed on top of at stack `b`.
   Example: b-> top will be returned if we want num at index 0.
*/
static int	find_target_idx(t_stack *b, int num)
{
	int i;
	int	smallest_elem_idx;
	int	largest_elem_idx;

	smallest_elem_idx = stack_get_smallest_elem_idx(b);
	if (num < b->data[smallest_elem_idx])
	{
		if (smallest_elem_idx == 0)
			return (b->top);
		else
			return (smallest_elem_idx - 1);
	}
	largest_elem_idx = stack_get_largest_elem_idx(b);
	if (num > b->data[largest_elem_idx])
		return (largest_elem_idx);
	i = 1;
	while (i <= b->top)
	{
		if (num > b->data[i - 1] && num < b->data[i])
			return (i - 1);
		++i;
	}
	if (num > b->data[b->top] && num < b->data[0])
		return (b->top);
	return (exit_error(), 1337);
}

/* 
   Move element with index `a_elem_idx` in stack `a` 
   to the correct position in stack `b`.
*/
static void	a_to_b(t_stack *a, t_stack *b, int a_elem_idx, int b_target_idx)
{
	stack_move_elem_to_top(a, a_elem_idx, 'a');
	stack_move_elem_to_top(b, b_target_idx, 'b');
	pb(a, b);
}

/* 
   Create a `costs` array which contain the cost of putting each element in
   stack a into correct position in stack b. 
   Indexes in costs array and stack a data array correspond to the same element.
*/
static int	*calculate_costs_a(t_stack *a, t_stack *b)
{
	int	*costs;
	int	tmp_target_idx;
	int	i;

	costs = (int *) ft_calloc(a->top + 1, sizeof(int));
	if (costs == NULL)
		exit_error();
	i = 0;
	while (i <= a->top)
	{
		tmp_target_idx = find_target_idx(b, a->data[i]);
		costs[i] = cost_to_top(a, i) + cost_to_top(b, tmp_target_idx) + 1;
		++i;
	}
	return (costs);
}

/* 
   End part of the sort algorithm where sorted content is 
   put into stack a correctly.
*/
static void	end_correction(t_stack *a, t_stack *b)
{
	void	(*a_end_correction_direction_op)(t_stack *s);
	int		i;

	while (!stack_is_empty(b))
		pa(a, b);
	if (stack_get_smallest_elem_idx(a) < a->top / 2)
		a_end_correction_direction_op = rra;
	else
		a_end_correction_direction_op = ra;
	i = 0;
	while (i < a->top && !stack_is_sorted_asc(a))
	{
		a_end_correction_direction_op(a);
		++i;
	}
}

void	mysort(t_stack *a, t_stack *b)
{
	int	*costs;
	int	a_smallest_cost_idx;
	int	b_target_idx;

	pb(a, b);
	pb(a, b);
	while (!stack_is_empty(a))
	{
		costs = calculate_costs_a(a, b);
		a_smallest_cost_idx = arr_min_idx(costs, a->top + 1);
		b_target_idx = find_target_idx(b, a->data[a_smallest_cost_idx]);
		a_to_b(a, b, a_smallest_cost_idx, b_target_idx);
		free(costs);
	}
	end_correction(a, b);
}
