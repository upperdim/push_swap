/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:35:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:52:04 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

void	exec_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 3))
		pa(a, b, FALSE);
	else if (ft_strncmp(cmd, "pb\n", 3))
		pb(a, b, FALSE);
	else if (ft_strncmp(cmd, "ra\n", 3))
		ra(a, FALSE);
	else if (ft_strncmp(cmd, "rb\n", 3))
		rb(b, FALSE);
	else if (ft_strncmp(cmd, "rr\n", 3))
		rr(a, b, FALSE);
	else if (ft_strncmp(cmd, "rra\n", 4))
		rra(a, FALSE);
	else if (ft_strncmp(cmd, "rrb\n", 4))
		rrb(b, FALSE);
	else if (ft_strncmp(cmd, "rrr\n", 4))
		rrr(a, b, FALSE);
	else if (ft_strncmp(cmd, "sa\n", 3))
		sa(a, FALSE);
	else if (ft_strncmp(cmd, "sb\n", 3))
		sb(b, FALSE);
	else if (ft_strncmp(cmd, "ss\n", 3))
		ss(a, b, FALSE);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char *read_line;

	init_stacks(&a, &b, argc, argv);
	read_line = get_next_line(STDIN_FD);
	while (read_line != NULL)
	{
		read_line = get_next_line(STDIN_FD);
		exec_cmd(&a, &b, read_line);
		free(read_line);
	}
	if (!stack_is_sorted_asc(&a))
		ft_printf("KO\n");
	else
		ft_printf("OK");
	return (0);
}
