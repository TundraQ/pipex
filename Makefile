NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_FILES = pipex.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC_FILES_BONUS = pipex_bonus.c
OBJ_FILES_BONUS = $(SRC_FILES_BONUS:.c=.o)
HEADER = pipex.h
RM = rm -rf
all:	libft $(NAME)

libft:  libft/libft.a

libft/libft.a:
	$(MAKE) -C libft

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ libft/libft.a -o $@

clean:
	$(MAKE) fclean -C libft
	$(RM) $(OBJ_FILES)
	$(RM) $(OBJ_FILES_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

$(NAME_BONUS): $(OBJ_FILES_BONUS)
	$(CC) $(CFLAGS) $^ libft/libft.a -o $@

bonus: libft $(NAME_BONUS)

.PHONY: libft all clean fclean re
