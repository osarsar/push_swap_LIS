# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 17:40:18 by osarsar           #+#    #+#              #
#    Updated: 2023/04/26 15:55:52 by osarsar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push.c			\
	swap.c				\
	rotate.c			\
	reverse_rotate.c	\
	push_swap.c			\
	analyse_stack.c		\
	push_swap_utils1.c	\
	push_swap_utils2.c	\
	push_swap_utils3.c	\
	push_swap_utils4.c	\

NAME = libft.a

%.o : %.c push_swap.h
	@echo "Compiling: $<"
	@cc -Wall -Werror -Wextra -c $< -o $@

$(NAME) : $(SRCS:.c=.o)
	@make -C libft
	@make bonus -C libft 
	@cp libft/libft.a .
	@ar -r $(NAME) $(SRCS:.c=.o)
	@cc push_swap.c libft.a -o push_swap
	@echo "Libft created !"

all : $(NAME)

clean :
	@rm -rf $(SRCS:.c=.o) $(SRCSB:.c=.o)
	@make clean -C libft
	@make clean -C push_swap_bonus
	@echo "objs erased !"

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@make fclean -C push_swap_bonus
	@echo "libft.a erased !"

re : fclean all

bonus :
	@make -C push_swap_bonus