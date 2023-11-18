/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:09:04 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/18 07:13:05 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"

# ifndef STACK_SIZE
#  define STACK_SIZE 100
# endif

# define STDERR_FD 2

typedef struct stack {
	int	top;
	int	data[STACK_SIZE];
}	t_stack;

int		str_is_numeric(char *s);
void	stack_print(t_stack *s, char *name, int print_name);

int		stack_pop(t_stack *s);
void	stack_push(t_stack *s, int new);
void	stack_rev_rotate(t_stack *s);
void	stack_rotate(t_stack *s);
void	stack_swap(t_stack *s);

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