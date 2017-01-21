# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 14:29:44 by tgauvrit          #+#    #+#              #
#    Updated: 2017/01/18 14:56:58 by tgauvrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			arraylist_test

CC =			clang

FLAGS =			-Wall -Werror -Wextra -g

HEADERS =		-I .

SRC_DIR =		./

OBJ_DIR_NAME =	obj
OBJ_DIR =		./$(OBJ_DIR_NAME)/

FILENAMES :=	arraylist test

OBJ_PATHS :=	$(addsuffix .o, $(FILENAMES))
OBJ_PATHS :=	$(addprefix $(OBJ_DIR),$(OBJ_PATHS))

all: $(NAME)

$(NAME): $(OBJ_PATHS)
	$(CC) $(FLAGS) $(HEADERS) $(OBJ_PATHS) -o $(NAME)

$(OBJ_PATHS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $(HEADERS) $< -o $@

clean:
	-/bin/rm -f $(OBJ_PATHS)
	/usr/bin/find . -name "$(OBJ_DIR_NAME)" -maxdepth 1 -type d -empty -delete

fclean: clean
	-/bin/rm -f  $(NAME)

re: fclean all
