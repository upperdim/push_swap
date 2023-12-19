/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mid_num_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:54:30 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/18 16:12:24 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Return the first index where `picked` is false. Return -1 on error. */
static int	get_smallest_available_idx(int	*picked, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!picked)
			return (i);
		++i;
	}
	return (-1);
}

/* Find the index of the middle number when elements are in ascending order. */
int		stack_find_mid_number_idx(t_stack *s)
{
	int	i;
	int	j;
	int	*picked;
	int	smallest_idx;

	picked = (int *) ft_calloc(s->top + 1, sizeof(int));
	if (picked == NULL)
		exit_error();
	i = 0;
	while (i <= s->top / 2)
	{
		smallest_idx = get_smallest_available_idx(picked, s->top + 1);
		j = 0;
		while (j <= s->top)
		{
			if (s->data[j] < s->data[smallest_idx] && !picked[j])
				smallest_idx = j;
			++j;
		}
		picked[smallest_idx] = 1;
		++i;
	}
	free(picked);
	return (smallest_idx);
}

/* Count how many numbers are there before the middle number. */
int	stack_count_nums_before_mid_num(t_stack *s, int mid_num_idx)
{
	int	count;
	int	i;

	if (mid_num_idx < 0)
		mid_num_idx = stack_find_mid_number_idx(s);
	count = 0;
	i = 0;
	while (i <= s->top)
	{
		if (s->data[i] < s->data[mid_num_idx])
			++count;
		++i;
	}
	return (count);
}
