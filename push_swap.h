/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:09:04 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/15 19:09:24 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"

# ifndef STACK_SIZE
#  define STACK_SIZE 10000
# endif

# define STDERR_FD 2

typedef struct stack {
	int	top;
	int	data[STACK_SIZE];
}	t_stack;

int		str_is_numeric(char *s);
void	stack_print(t_stack *s, char *name);
int		stack_get_smallest_elem_idx(t_stack *s);
int		stack_get_largest_elem_idx(t_stack *s);
int		stack_is_sorted_asc(t_stack *s);
void	exit_error();

int		stack_pop(t_stack *s);
void	stack_push(t_stack *s, int new);
void	stack_rev_rotate(t_stack *s);
void	stack_rotate(t_stack *s);
void	stack_swap(t_stack *s);
int		stack_is_empty(t_stack *s);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *a);
void	ss(t_stack *a, t_stack *b);

#endif