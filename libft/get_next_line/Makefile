NAME = get_next_line.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=100
SRC_FILES = get_next_line.c      \
			get_next_line_utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)
HEADER = get_next_line.h
RM = rm -rf
all:	$(NAME)
%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< 
$(NAME):	$(OBJ_FILES)
		ar crs $(NAME) $(OBJ_FILES)
clean:
	$(RM) $(OBJ_FILES)
fclean: clean
		$(RM) $(NAME)
re: fclean all
.PHONY: clean fclean re

