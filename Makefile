NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
SOURCES = main.c tetr_make.c map.c valid.c
OBJECTS = $(SOURCES:.c=.o)

INC = $(INC_DIR)libft.a
INC_DIR = libft/
INCLUDES = $(INC_DIR)includes/
INC_FLAGC = -L $(INC_DIR) -lft

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SOURCES) -I $(INCLUDES) $(INC_FLAGC)

$(INC):
	make $(INC_DIR)

clean:
	rm -f $(OBJECTS)
	make clean $(INC_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean $(INC_DIR)

re:	fclean all