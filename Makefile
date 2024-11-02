SRCS = printf.c print_int.c print_char.c print_string.c flags.c print_hex.c print_pointer.c print_percent.c utils.c printer.c
SRC_DIR = src
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(SRC_DIR)/, $(OBJS))
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) bonus

bonus: $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus