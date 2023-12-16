# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 02:26:24 by tunsal            #+#    #+#              #
#    Updated: 2023/12/16 11:36:51 by tunsal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STACK_FOLDER				= stack
STACK_PREFIX				= stack_
STACK_SRCS					= $(STACK_FOLDER)/$(STACK_PREFIX)pop.c $(STACK_FOLDER)/$(STACK_PREFIX)push.c $(STACK_FOLDER)/$(STACK_PREFIX)rev_rotate.c $(STACK_FOLDER)/$(STACK_PREFIX)rotate.c $(STACK_FOLDER)/$(STACK_PREFIX)swap.c $(STACK_FOLDER)/$(STACK_PREFIX)is_empty.c

OPS_FOLDER					= operations
OPS_SRCS					= $(OPS_FOLDER)/pa.c $(OPS_FOLDER)/pb.c $(OPS_FOLDER)/ra.c $(OPS_FOLDER)/rb.c $(OPS_FOLDER)/rr.c $(OPS_FOLDER)/rra.c $(OPS_FOLDER)/rrb.c $(OPS_FOLDER)/rrr.c $(OPS_FOLDER)/sa.c $(OPS_FOLDER)/sb.c $(OPS_FOLDER)/ss.c

UTILS_FOLDER				= utils
UTILS_SRCS					= $(UTILS_FOLDER)/str_is_numeric.c $(UTILS_FOLDER)/stack_print.c $(UTILS_FOLDER)/stack_get_smallest_elem_idx.c $(UTILS_FOLDER)/stack_get_largest_elem_idx.c $(UTILS_FOLDER)/stack_is_sorted_asc.c $(UTILS_FOLDER)/exit_error.c $(UTILS_FOLDER)/arr_min_idx.c $(UTILS_FOLDER)/stack_move_elem_to_top.c $(UTILS_FOLDER)/arr_print.c

SORT_FOLDER					= sort
SORT_SRCS					= $(SORT_FOLDER)/mysort.c $(SORT_FOLDER)/sort3.c $(SORT_FOLDER)/sortn.c

SRCS						= push_swap.c $(STACK_SRCS) $(OPS_SRCS) $(UTILS_SRCS) $(SORT_SRCS)
OBJS						= ft_printf/libftprintf.a $(SRCS:.c=.o)
NAME						= push_swap

CC							= gcc
CFLAGS						= -g -Wall -Wextra -Werror

all:						$(NAME)

$(NAME):					$(OBJS)

ft_printf/libftprintf.a:
							make -C ./ft_printf all

clean:						
							make -C ./ft_printf clean
							rm -f $(OBJS)

fclean:						clean
							make -C ./ft_printf fclean
							rm -f $(NAME)

re:							fclean all