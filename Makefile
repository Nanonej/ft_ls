# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 16:18:14 by aridolfi          #+#    #+#              #
#    Updated: 2017/01/28 11:23:59 by aridolfi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME	= ft_ls

# Compilation
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# Directories
SRCDIR	= srcs
OBJDIR	= objs
INCDIR	= ./includes
LIBDIR	= ./libft

# Sources && Objs
SRCS	= 					\
			arraylist.c		\
			check_error.c	\
			free.c			\
			main.c			\
			get_info.c		\
			init.c			\


OBJS	= $(SRCS:.c=.o)

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

.PHONY			:	clean

# **************************************************************************** #

# Rules

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					@make -C ./libft
		  			@$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a -I$(INCDIR) -I ./libft -I ./libft/printf
					@echo ""
					@cat cake.ascii
					@echo ""

%.o 			: 	$(SRCDIR)/%.c
					@echo "--$(LOG_CLEAR)$(LOG_GREEN)$(NAME)$(LOG_NOCOLOR) ........................ $(LOG_VIOLET)$<$(LOG_NOCOLOR)$(LOG_UP)"
					@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^ -I$(INCDIR) -I ./libft -I ./libft/printf

clean			:
					@make clean -C ./libft
					@rm -f $(OBJS)

fclean			:	clean
					@make fclean -C ./libft
					@rm -f $(NAME)

re				:	fclean all
