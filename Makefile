# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okuchko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 16:03:56 by okuchko           #+#    #+#              #
#    Updated: 2019/01/16 16:05:31 by okuchko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
SOURCES = fill.c tetr_make.c map.c valid.c backtracking.c
OBJECTS = $(SOURCES:.c=.o)

INC = $(INC_DIR)libft.a
INC_DIR = libft/
INCLUDES = $(INC_DIR)includes/
INC_FLAGC = -L $(INC_DIR) -lft

all: $(NAME) 

$(NAME): $(INC) $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(INC_FLAGC) -o $(NAME)
$(INC):
	make -C $(INC_DIR)


HEADER_FLAGS =		-I $(INCLUDES)  -I fillit.h
$(OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

clean:
	rm -f $(OBJECTS)
	make clean -C $(INC_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(INC_DIR)

re:	fclean all
