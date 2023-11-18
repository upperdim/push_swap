/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:12:06 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/18 03:49:02 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int	i;

	i = 1;
	while (i <= argc)
	{
		if (!str_is_numeric(argv[i]))
			return (1);
		stack_push(&b, atoi(argv[i]));
		++i;
	}
	i = 1;
	while (i <= argc)
	{
		pa(&a, &b);
		++i;
	}
	
	// Initially contains random amount if numbers
	
	// Initially empty
	

	// Goal: = 
}
