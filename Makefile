NAME = push_swap.all

SRCS = push_swap.clang

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = CC

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf (OBJ) $(BONUSOBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re bonus