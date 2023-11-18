/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:09:04 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/18 02:24:25 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

# ifndef STACK_SIZE
#  define STACK_SIZE 100
# endif

typedef struct t_stack {
	int	top;
	int	data[STACK_SIZE];
}	t_stack;

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