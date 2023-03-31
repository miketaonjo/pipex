# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:48:37 by mcloarec          #+#    #+#              #
#    Updated: 2022/09/01 18:24:05 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_bzero.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_memcpy.c
SRCS += ft_memset.c
SRCS += ft_strlen.c
SRCS += ft_strlcpy.c
SRCS += ft_memmove.c
SRCS += ft_toupper.c
SRCS += ft_tolower.c
SRCS += ft_strlcat.c
SRCS += ft_strchr.c
SRCS += ft_strrchr.c
SRCS += ft_strncmp.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_strnstr.c
SRCS += ft_atoi.c
SRCS += ft_calloc.c
SRCS += ft_strdup.c
SRCS += ft_substr.c
SRCS += ft_strjoin.c
SRCS += ft_strtrim.c
SRCS += ft_split.c
SRCS += ft_itoa.c
SRCS += ft_strmapi.c
SRCS += ft_striteri.c
SRCS += ft_putchar_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_printf.c
SRCS += ft_printunsigned.c
SRCS += ft_printchar.c
SRCS += ft_printnbr.c
SRCS += ft_printpercent.c
SRCS += ft_printstr.c
SRCS += ft_printhexa.c
SRCS += ft_printptr.c
SRCS += get_next_line.c
SRCS += get_next_line_utils.c

SRCS_BONUS += ft_lstnew.c
SRCS_BONUS += ft_lstadd_front.c
SRCS_BONUS += ft_lstsize.c
SRCS_BONUS += ft_lstlast.c
SRCS_BONUS += ft_lstadd_back.c
SRCS_BONUS += ft_lstdelone.c
SRCS_BONUS += ft_lstclear.c
SRCS_BONUS += ft_lstiter.c
SRCS_BONUS += ft_lstmap.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME =	libft.a

CC =	ar rcs

RM =	rm -f

CFLAGS =	-g3 -Wall -Wextra -Werror

all: $(NAME)

.c.o:
		gcc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	$(CC) $(NAME) $(OBJS_BONUS)

clean:	
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
