# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 22:47:07 by aridolfi          #+#    #+#              #
#    Updated: 2017/01/28 11:25:44 by aridolfi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME	= libft.a

# Compilation
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# SRCS & OBJT
SRCS 	=	free_swap.c			\
			ft_atoi.c			\
			ft_bzero.c			\
			ft_digitcount.c		\
			ft_int_tab_bubble.c	\
 			ft_isalnum.c 		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_iswhitespace.c	\
			ft_itoa_base.c		\
			ft_itoa.c			\
			ft_lstadd.c			\
			ft_lstback.c		\
			ft_lstdel.c			\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_memalloc.c		\
			ft_memcat.c			\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memdel.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_memswap.c		\
			ft_putchar_fd.c		\
			ft_putchar.c		\
			ft_putendl_fd.c		\
			ft_putendl.c		\
			ft_putnbr_fd.c		\
			ft_putnbr.c			\
			ft_putstr_fd.c		\
			ft_putstr.c			\
			ft_putwchar_fd.c	\
			ft_putwchar.c		\
			ft_strcat.c			\
			ft_strchr.c			\
			ft_strclr.c			\
			ft_strcmp.c			\
			ft_strcpy.c			\
			ft_strdel.c			\
			ft_strdup.c			\
			ft_strequ.c			\
			ft_strfind.c		\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlen.c			\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strncat.c		\
			ft_strncmp.c		\
			ft_strncpy.c		\
			ft_strnequ.c		\
			ft_strnew.c			\
			ft_strnstr.c		\
			ft_strsplit.c		\
			ft_strrchr.c		\
			ft_strstr.c			\
			ft_strsub.c			\
			ft_strtrim.c		\
			ft_strupper.c		\
			ft_tolower.c		\
			ft_toupper.c		\
			get_next_line.c		\
			\
			printf/ft_printf.c	\
			printf/init.c		\
			printf/check.c		\
			printf/opt.c		\
			printf/conv_l.c		\
			printf/conv_n.c		\
			printf/conv_b.c		\
			printf/format.c		\

OBJT	= $(SRCS:.c=.o)

# **************************************************************************** #

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# Bonus

.PHONY:		all clean fclean re

# **************************************************************************** #

# Rules

all: $(NAME)

$(NAME): $(OBJT)
	@ar rc $(NAME) $(OBJT)
	@ranlib $(NAME)
	@echo "--$(LOG_CLEAR)$(LOG_GREEN)$(NAME)$(LOG_NOCOLOR) ........................ $(LOG_VIOLET)Cake Done$(LOG_NOCOLOR)$(LOG_UP)"

%.o: %.c
	@echo "--$(LOG_CLEAR)$(LOG_GREEN)$(NAME)$(LOG_NOCOLOR) ........................ $(LOG_VIOLET)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^ -I ./printf -I ./

clean:
	@rm -f $(OBJT)

fclean: clean
	@rm -f $(NAME)

re: fclean all
