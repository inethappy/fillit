NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
SOURCES = fill.c tetr_make.c map.c valid.c
OBJECTS = $(SOURCES:.c=.o)

INC = $(INC_DIR)libft.a
INC_DIR = libft/
INCLUDES = $(INC_DIR)includes/
INC_FLAGC = -L $(INC_DIR) -lft

all: $(NAME) 

$(NAME):
	$(CC) $(FLAGS) $(SOURCES) -I $(INCLUDES) $(INC_FLAGC) -o fillit

clean:
	rm -f $(OBJECTS)
	make clean -C $(INC_DIR)

fclean: clean
	rm -rf $(NAME)

re:	fclean all