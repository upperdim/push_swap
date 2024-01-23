/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:23:12 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:24:26 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_duplicates(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->top)
	{
		j = i + 1;
		while (j <= s->top)
		{
			if (s->data[i] == s->data[j])
				exit_error(s);
			++j;
		}
		++i;
	}
}

static int	count_arg_nums(t_stack *b, int argc, char *argv[])
{
	int		i;
	int		j;
	char	**splits;
	int		num_count;

	num_count = 0;
	i = 1;
	while (i < argc)
	{
		splits = ft_split(argv[i], ' ');
		j = 0;
		while (splits[j] != NULL)
		{
			if (!str_is_numeric(splits[j]))
				exit_error(b);
			++num_count;
			free(splits[j++]);
		}
		free(splits[j]);
		free(splits);
		++i;
	}
	return (num_count);
}

static void	push_args_to_b(t_stack *b, int argc, char *argv[])
{
	int		i;
	int		j;
	char	**splits;
	long	num_to_push;

	i = 0;
	while (++i < argc)
	{
		splits = ft_split(argv[i], ' ');
		j = 0;
		while (splits[j] != NULL)
		{
			if (!str_is_numeric(splits[j]))
				exit_error(b);
			num_to_push = ft_atoi_l(splits[j]);
			if (num_to_push < INT_MIN || num_to_push > INT_MAX)
				exit_error(b);
			stack_push(b, (int) num_to_push);
			free(splits[j++]);
		}
		free(splits[j]);
		free(splits);
	}
}

void	init_stacks(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int	arg_nums_count;

	a->other_stack = b;
	b->other_stack = a;
	a->top = -1;
	b->top = -1;
	arg_nums_count = count_arg_nums(b, argc, argv);
	a->data = (int *) ft_calloc(arg_nums_count, sizeof(int));
	b->data = (int *) ft_calloc(arg_nums_count, sizeof(int));
	if (a->data == NULL || b->data == NULL)
		exit_error(a);
	push_args_to_b(b, argc, argv);
	while (!stack_is_empty(b))
	{
		stack_push(a, stack_pop(b));
	}
	check_duplicates(a);
}
