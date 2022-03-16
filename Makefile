NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_FILES = pipex.c
OBJ_FILES = $(SRC_FILES:.c=.o)
HEADER = pipex.h
RM = rm -rf
all:	libft $(NAME)
libft:  libft/libft.a
libft/libft.a:
	$(MAKE) -C libft
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ libft/libft.a -o $@
clean:
	$(MAKE) fclean -C libft
	$(RM) $(OBJ_FILES)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: libft all clean fclean re
