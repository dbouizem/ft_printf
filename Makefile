# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 17:17:29 by dbouizem          #+#    #+#              #
#    Updated: 2025/05/13 02:49:38 by dbouizem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST = program
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

SRCS = \
	ft_printf.c \
	parsing/parse_format.c \
	handles/handle_char.c \
	handles/handle_string.c \
	handles/handle_pointer.c \
	handles/handle_hex.c \
	handles/handle_int.c \
	handles/handle_uint.c \
	handles/handle_dispatch_format.c \
	handles/handle_invalid_specifier.c \
	utils/ft_print_char.c \
	utils/ft_print_str.c \
	utils/ft_print_hex.c \
	utils/ft_itoa_print.c \
	utils/ft_ulltoa_base.c \

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = \
	parsing/parse_flags_bonus.c \
	parsing/parse_width_precision_bonus.c \
	parsing/parse_length_bonus.c \
	handles/handle_reset_data_bonus.c \
	get_value/get_signed_value_bonus.c \
	get_value/get_unsigned_value_bonus.c \
	get_value/get_wc_utf8_bonus.c \
	get_value/get_wstr_utf8_bonus.c \
	applys/apply_width_bonus.c \
	applys/apply_precision_bonus.c \
	applys/apply_precision_int_bonus.c \
	applys/apply_sign_bonus.c \
	applys/apply_hash_bonus.c \
	utils/ft_strfill_bonus.c \
	utils/ft_wcrtomb_bonus.c \

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

TEST_SRC = main.c

TEST_OBJ = $(TEST_SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@cp $(LIBFT_LIB) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus: CFLAGS += -DBONUS
bonus: all $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@ranlib $(NAME)

$(TEST) : $(TEST_OBJ) $(NAME)
	$(CC) $(CFLAGS) $(TEST_OBJ) -L. -lftprintf -o $(TEST)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_PATH) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS) $(TEST_OBJ)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME) $(TEST)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re

