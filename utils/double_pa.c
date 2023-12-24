/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:25:37 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/24 19:12:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Performs pa operation 2 times. */
void	double_pa(t_stack *a, t_stack *b)
{
	pa(a, b);
	pa(a, b);
}
