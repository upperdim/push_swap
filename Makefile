# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 02:26:24 by tunsal            #+#    #+#              #
#    Updated: 2023/11/18 03:51:34 by tunsal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTILS_FOLDER				= utils
UTILS_SRCS					= $(UTILS_FOLDER)/str_is_numeric.c

STACK_FOLDER				= stack
STACK_PREFIX				= stack_
STACK_SRCS					= $(STACK_FOLDER)/$(STACK_PREFIX)pop.c $(STACK_FOLDER)/$(STACK_PREFIX)push.c $(STACK_FOLDER)/$(STACK_PREFIX)rev_rotate.c $(STACK_FOLDER)/$(STACK_PREFIX)rotate.c $(STACK_FOLDER)/$(STACK_PREFIX)swap.c

OPS_FOLDER					= operations
OPS_SRCS					= $(OPS_FOLDER)/pa.c $(OPS_FOLDER)/pb.c $(OPS_FOLDER)/ra.c $(OPS_FOLDER)/rb.c $(OPS_FOLDER)/rr.c $(OPS_FOLDER)/rra.c $(OPS_FOLDER)/rrb.c $(OPS_FOLDER)/rrr.c $(OPS_FOLDER)/sa.c $(OPS_FOLDER)/sb.c $(OPS_FOLDER)/ss.c

SRCS						= push_swap.c $(STACK_SRCS) $(OPS_SRCS) $(UTILS_SRCS)
OBJS						= $(SRCS:.c=.o)
NAME						= push_swap

CC							= gcc
CFLAGS						= -Wall -Wextra -Werror

all:						ft_printf/libftprintf.a $(NAME)

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