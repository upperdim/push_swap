/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:34:00 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/16 11:38:54 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Return index of smallest element in `arr`. */
void	arr_print(int *arr, int size, char *name)
{
	int	i;

	if (size < 0)
		exit_error();
	if (name != NULL)
		ft_printf("%s = ", name);
	ft_printf("[");
	i = 0;
	while (i < size - 1)
	{
		ft_printf("%d, ", arr[i]);
		++i;
	}
	ft_printf("%d]\n", arr[size - 1]);
}
