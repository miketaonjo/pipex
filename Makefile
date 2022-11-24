# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:09:12 by mcloarec          #+#    #+#              #
#    Updated: 2022/10/13 17:54:49 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = mandatory/srcs/main.c
SRCS += mandatory/srcs/child.c
SRCS += mandatory/srcs/utils.c
SRCS += mandatory/srcs/path.c
SRCS += mandatory/srcs/init.c
SRCS += mandatory/srcs/free.c

SRCS_BONUS = bonus/srcs/main_bonus.c
SRCS_BONUS += bonus/srcs/child_bonus.c
SRCS_BONUS += bonus/srcs/path_bonus.c
SRCS_BONUS += bonus/srcs/init_bonus.c
SRCS_BONUS += bonus/srcs/free_bonus.c
SRCS_BONUS += bonus/srcs/utils_bonus.c
SRCS_BONUS += bonus/srcs/child_mult.c
SRCS_BONUS += bonus/srcs/free_mandatory.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = pipex

NAME_BONUS = pipex_bonus

CC = gcc

RM = rm -f

CFLAGS = -g3 -Wall -Wextra -Werror

all: $(NAME)

bonus: fclean $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		@make -sC libft
		echo "Libft compilation completed"
		$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
		echo "Pipex compilation completed"

$(NAME_BONUS): $(OBJS_BONUS)
		@make -sC libft
		echo "Libft compilation completed"
		$(CC) $(CFLAGS) $(OBJS_BONUS) -Llibft -lft -o $(NAME_BONUS)
		echo "Pipex bonus compilation completed"

clean:
		@make -sC libft clean
		$(RM) $(OBJS)
		$(RM) $(OBJS_BONUS)
		echo "clean done"

fclean:	clean
		@make -sC libft fclean
		$(RM) $(NAME)
		$(RM) $(NAME_BONUS)
		echo "fclean done"

re: fclean all

.SILENT:

.PHONY: all clean fclean re 
