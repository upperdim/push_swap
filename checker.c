/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:35:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/13 15:54:16 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

void	exec_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(a, b, FALSE);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(a, b, FALSE);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(a, FALSE);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(b, FALSE);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(a, b, FALSE);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(a, FALSE);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(b, FALSE);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(a, b, FALSE);
	else if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(a, FALSE);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(b, FALSE);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(a, b, FALSE);
	else
		exit_error(a);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	*read_line;

	init_stacks(&a, &b, argc, argv);
	read_line = get_next_line(STDIN_FD);
	while (read_line != NULL)
	{
		exec_cmd(&a, &b, read_line);
		free(read_line);
		read_line = get_next_line(STDIN_FD);
	}
	if (stack_is_sorted_asc(&a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
