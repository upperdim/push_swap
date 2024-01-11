/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:09:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/01/11 19:51:07 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>

# define TRUE 1
# define FALSE 0

# define STDIN_FD 0
# define STDERR_FD 2

# define RA 101
# define RRA 102
# define RB 103
# define RRB 104

typedef struct s_stack {
	int				top;
	int				*data;
	struct s_stack	*other_stack;
}	t_stack;

/* Sort functions */
void	sort3(t_stack *s);
void	sortn(t_stack *a, t_stack *b, int n);
void	mysort(t_stack *a, t_stack *b);

/* Utility functions */
long	ft_atoi_l(const char *str);
int		str_is_numeric(char *s);
int		str_contains(char *str, char target);
int		ft_strncmp(char *s1, char *s2, size_t cmp_lim);
int		arr_min_idx(int *arr, int size, int max_check_idx, t_stack *fre_on_err);
void	arr_print(int *arr, int size, char *name, t_stack *free_on_err);
void	stack_print(t_stack *s, char *name);
int		stack_get_smallest_elem_idx(t_stack *s);
int		stack_get_largest_elem_idx(t_stack *s);
int		stack_is_sorted_asc(t_stack *s);
void	stack_move_elem_to_top(t_stack *s, int elem_idx, char stack_name);
int		stack_get_rotation_direction(t_stack *s, int elem_idx, char stack_name);
int		cost_to_top(t_stack *s, int target_idx);
int		stack_find_mid_number_idx(t_stack *s);
int		stack_count_nums_before_mid_num(t_stack *s, int mid_num_idx);
int		stack_find_target_idx(t_stack *s, int num);
void	common_rots(t_stack *a, t_stack *b, int *p_b_elem_i, int *p_a_target_i);
void	exit_error(t_stack *s);
void	init_stacks(t_stack *a, t_stack *b, int argc, char *argv[]);

/* Basic stack operations */
int		stack_pop(t_stack *s);
void	stack_push(t_stack *s, int new);
void	stack_rev_rotate(t_stack *s);
void	stack_rotate(t_stack *s);
void	stack_swap(t_stack *s);
int		stack_is_empty(t_stack *s);

/* Ecole 42 stack operations */
void	pa(t_stack *a, t_stack *b, int print);
void	pb(t_stack *a, t_stack *b, int print);
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b, int print);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b, int print);
void	sa(t_stack *a, int print);
void	sb(t_stack *a, int print);
void	ss(t_stack *a, t_stack *b, int print);

#endif