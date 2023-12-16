/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_min_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:11:39 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/16 10:14:55 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Return index of smallest element in `arr`. */
int	arr_min_idx(int *arr, int size)
{
	int	smallest_elem_idx;
	int	i;

	if (size < 0)
		exit_error();
	smallest_elem_idx = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] < arr[smallest_elem_idx])
			smallest_elem_idx = i;
		++i;
	}
	return (smallest_elem_idx);
}
