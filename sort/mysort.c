/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:02:42 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/21 17:48:22 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*  Return the index which `num` will be placed on top of at stack `s`. */
static int	find_target_idx(t_stack *s, int num)
{
	int i;
	int	smallest_elem_idx;
	int	largest_elem_idx;

	smallest_elem_idx = stack_get_smallest_elem_idx(s);
	if (num < s->data[smallest_elem_idx])
		return (smallest_elem_idx);
	largest_elem_idx = stack_get_largest_elem_idx(s);
	if (num > s->data[largest_elem_idx])
	{
		if (largest_elem_idx == 0)
			return (s->top);
		else
			return (largest_elem_idx - 1);
	}
	i = 1;
	while (i <= s->top)
	{
		if (num < s->data[i - 1] && num > s->data[i])
			return (i - 1);
		++i;
	}
	if (num < s->data[s->top] && num > s->data[0])
		return (s->top);
	return (exit_error(), 1337);
}

/* 
   Move element with index `b_elem_idx` in stack `b`
   to the correct position in stack `a`.
*/
static void	b_to_a(t_stack *a, t_stack *b, int b_elem_idx, int a_target_idx)
{
	int	a_rot_dir;
	int	b_rot_dir;

	a_rot_dir = stack_get_rotation_direction(a, a_target_idx, 'a');
	b_rot_dir = stack_get_rotation_direction(b, b_elem_idx, 'b');
	if (a_rot_dir == RA && b_rot_dir == RB)
		while (!(b_elem_idx == b->top) && !(a_target_idx == a->top))
		{
			++b_elem_idx;
			++a_target_idx;
			rr(a, b);
		}
	else if (a_rot_dir == RRA && b_rot_dir == RRB)
		while (b_elem_idx >= 0 && a_target_idx >= 0)
		{
			--b_elem_idx;
			--a_target_idx;
			rrr(a, b);
		}
	stack_move_elem_to_top(b, b_elem_idx, 'b');
	stack_move_elem_to_top(a, a_target_idx, 'a');
	pa(a, b);
}

/* 
   Create a `costs` array which contain the cost of putting each element in
   stack a into correct position in stack b. 
   Indexes in costs array and stack a data array correspond to the same element.
*/
static void	calculate_costs_b(t_stack *a, t_stack *b, int *costs)
{
	int	tmp_target_idx;
	int	i;

	i = 0;
	while (i <= b->top)
	{
		tmp_target_idx = find_target_idx(a, b->data[i]);
		costs[i] = cost_to_top(b, i) + cost_to_top(a, tmp_target_idx) + 1;
		++i;
	}
}

/* 
   End part of the sort algorithm where sorted content is 
   put into stack a correctly.
*/
static void	end_correction(t_stack *a)
{
	void	(*a_end_correction_direction_op)(t_stack *s);
	int		i;

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

/*
   Transfer elements of stack a to stack b. 
   Elements bigger than the median value will be on top, and rest will be at
   the bottom half of stack b.
*/
void	a_to_b_split_to_2(t_stack *a, t_stack *b, int a_mid_num_idx)
{
	while (!stack_is_empty(a))
	{
		if (a->data[a->top] <= a->data[a_mid_num_idx])
		{
			pb(a, b);
			rb(b);
		}
		else
			pb(a, b);
	}
}

void	mysort(t_stack *a, t_stack *b)
{
	int	*costs;
	int	b_smallest_cost_idx;
	int	a_target_idx;
	int	curr_costs_max;
	int	a_mid_num_idx;
	
	a_mid_num_idx = stack_find_mid_number_idx(a);
	a_to_b_split_to_2(a, b, a_mid_num_idx);
	costs = (int *) ft_calloc(b->top + 1, sizeof(int));
	if (costs == NULL)
		exit_error();
	curr_costs_max = b->top + 1;
	pa(a, b);
	pa(a, b);
	while (!stack_is_empty(b))
	{
		calculate_costs_b(a, b, costs);
		b_smallest_cost_idx = arr_min_idx(costs, b->top + 1, curr_costs_max);
		a_target_idx = find_target_idx(a, b->data[b_smallest_cost_idx]);
		b_to_a(a, b, b_smallest_cost_idx, a_target_idx);
		--curr_costs_max;
	}
	end_correction(a);
	free(costs);
}
