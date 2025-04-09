NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = ft_printf.c \
	handles/handle_char.c \
	handles/handle_string.c \
	handles/handle_pointer.c \
	handles/handle_hex.c \
	handles/handle_int.c \
	handles/handle_uint.c \
	handles/handle_invalid_specifier.c \
	apply/apply_width.c \
	apply/apply_precision.c \
	apply/apply_precision_int.c \
	apply/apply_sign.c \
	apply/apply_hash.c \
	utils/ft_print_char.c \
	utils/ft_print_str.c \
	utils/ft_print_hex.c \
	utils/ft_atoi.c \
	utils/ft_atoi_print.c \
	utils/ft_strfill.c \
	utils/ft_utoa.c \
	utils/ft_ulltoa_base.c \
	utils/get_args.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $@
	ar rcs $@ $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

%.o:%.c
	$(CC) $(FLAGES) -I$(LIBFT_PATH) -c $< -o $@

clean:
	@rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
