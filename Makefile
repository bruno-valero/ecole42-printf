NAME = libprintf.a
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I &(LIBFT)

SRCS = conversion_ntoa_support.c\
	conversion_ntoa.c\
	flags_get_corresponding_flag.c\
	flags_valid_flags.c\
	ft_printf.c\
	print.c\
	text_input_translation_support.c\
	text_input_translation.c

PF_OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(PF_OBJS) $(LIBFT)
	@$(eval LIBFT_OBJS := $(shell ar -t $(LIBFT)))
	@ar rcs $(NAME) $(OBJ) $(addprefix libft/, $(LIBFT_OBJS))

clean:
	@rm -rf *.o

clean:
	@rm *.o
	@make -C libft clean

fclean: clean
	rm *.a
	@make -C libft fclean

re:
