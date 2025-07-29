NAME = libft_printf.a
LIBFT = libft/
CC = cc
CFLAGS = -Wall -Wextra -Werror -I &(LIBFT)
PF_OBJS

all: $(NAME) $(LIBFT)

$(NAME): $(PF_OBJS)

clean:
	rm -rf *.o

clean:
	make -C ./libft clean
	rm *.c

fclean: clean
	make -C ./libft fclean
	rm *.a
