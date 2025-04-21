# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 17:17:29 by dbouizem          #+#    #+#              #
#    Updated: 2025/04/21 19:53:58 by dbouizem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

SRCS = \
	ft_printf.c \
	parsing/parse_format.c \
	parsing/parse_flags.c \
	parsing/parse_width_precision.c \
	parsing/parse_length.c \
	get_value/get_signed_value.c \
	get_value/get_unsigned_value.c \
	get_value/get_wc_utf8.c \
	get_value/get_wstr_utf8.c \
	handles/handle_char.c \
	handles/handle_string.c \
	handles/handle_pointer.c \
	handles/handle_hex.c \
	handles/handle_int.c \
	handles/handle_uint.c \
	handles/handle_dispatch_format.c \
	handles/handle_invalid_specifier.c \
	handles/handle_reset_data.c \
	applys/apply_width.c \
	applys/apply_precision.c \
	applys/apply_precision_int.c \
	applys/apply_sign.c \
	applys/apply_hash.c \
	utils/ft_print_char.c \
	utils/ft_print_str.c \
	utils/ft_print_hex.c \
	utils/ft_strfill.c \
	utils/ft_ulltoa_base.c \
	utils/ft_wcrtomb.c \
	utils/ft_itoa_print.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: all

##build_m: all
##build_b: bonus

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@cp $(LIBFT_LIB) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_PATH) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus build_b build_m clean fclean re
