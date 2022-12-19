SRC		=	get_next_line.c get_next_line_utils.c

INC		=	get_next_line.h

OBJ		=	$(patsubst %.c, %.o, $(SRC))

NAME	=	./gnl

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3
all: clearscreen $(NAME)
	$(NAME)

leaks: clearscreen $(NAME)
	valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clearscreen:
	clear

$(OBJ): %.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re