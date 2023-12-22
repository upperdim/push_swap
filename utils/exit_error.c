/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:13:20 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/22 15:10:00 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_error(t_stack *s)
{
	if (s != NULL)
	{
		if (s->other_stack != NULL && s->other_stack->data != NULL)
			free(s->other_stack->data);
		if (s->data != NULL)
			free(s->data);
	}
	ft_putstr_fd("Error\n", STDERR_FD);
	exit(EXIT_FAILURE);
}
