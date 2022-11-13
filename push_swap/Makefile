# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 02:54:48 by juaugry           #+#    #+#              #
#    Updated: 2022/10/23 13:28:29 by juaugry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC 			= 	cc

CFLAGS 		= 	-Wall -Wextra -Werror

CPPFLAG		= 	-MMD

RM 			=	rm -rf

SRCS 		= 	$(addprefix $(SRCS_PATH), \
				main.c\
				sort_center.c\
				args_to_stack.c\
				overflow.c\
				stack_fts.c\
				clear.c\
				parse.c\
				assign_data.c\
				update_data.c\
				moves_cost.c\
				init_sort.c\
				sorted.c\
				push.c\
				rotate.c\
				swap.c\
				reverse.c)

SRCS_PATH	=	./srcs/

OBJS		= 	$(SRCS:.c=.o)

DEPS		=  $(OBJS:.o=.d)

LIBFT_PATH	=	./libs/libft/

PATH_FLAGS	=	-L$(LIBFT_PATH)

LIBFT		=	$(LIBFT_PATH)libft.a

all 		:	$(NAME)

$(NAME)		:	$(OBJS)
					make -C $(LIBFT_PATH)
					$(CC) $(CFLAGS) $(OBJS) $(PATH_FLAGS) -o $@ $(LIBFT)

%.o:%.c
	$(CC) $(CPPFLAG) $(CFLAGS) -c $< -o $@

clean 		:
				@$(RM) $(OBJS) $(DEPS)
				@make clean -C $(LIBFT_PATH)

fclean 		: 	clean
				@$(RM) $(NAME)
				@$(RM) $(LIBFT)

re 			: 	fclean
				make all

.PHONY : all clean fclean re

-include $(DEPS)
