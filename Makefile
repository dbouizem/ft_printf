# PROJECT
NAME		= libftprintf.a
TEST		= program

# COMPILER & FLAGS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# DIRECTORIES & FILES
OBJ_DIR		= objs
OBJ_BONUS_DIR	= objs_bonus
INC_DIR		= includes
HEADER		= $(INC_DIR)/ft_printf.h
HEADER_BONUS	= $(INC_DIR)/ft_printf_bonus.h
TMP_LIBFT_DIR	= .tmp_libft_objs

LIBFT_PATH	= libft
LIBFT_LIB	= $(LIBFT_PATH)/libft.a

# SOURCES
SRCS =	srcs/ft_printf.c \
		srcs/parsing/parse_format.c \
		srcs/handles/handle_char.c \
		srcs/handles/handle_string.c \
		srcs/handles/handle_pointer.c \
		srcs/handles/handle_hex.c \
		srcs/handles/handle_int.c \
		srcs/handles/handle_uint.c \
		srcs/handles/handle_dispatch_format.c \
		srcs/handles/handle_invalid_specifier.c \
		srcs/utils/ft_print_char.c \
		srcs/utils/ft_print_str.c \
		srcs/utils/ft_print_hex.c \
		srcs/utils/ft_itoa_print.c \
		srcs/utils/ft_ulltoa_base.c

SRCS_BONUS =	srcs/ft_printf.c \
				srcs_bonus/parsing/parse_format_bonus.c \
				srcs_bonus/handles/handle_char_bonus.c \
				srcs_bonus/handles/handle_string_bonus.c \
				srcs_bonus/handles/handle_pointer_bonus.c \
				srcs_bonus/handles/handle_hex_bonus.c \
				srcs_bonus/handles/handle_int_bonus.c \
				srcs_bonus/handles/handle_uint_bonus.c \
				srcs_bonus/handles/handle_dispatch_format_bonus.c \
				srcs/handles/handle_invalid_specifier.c \
				srcs/utils/ft_print_char.c \
				srcs/utils/ft_print_str.c \
				srcs/utils/ft_print_hex.c \
				srcs/utils/ft_itoa_print.c \
				srcs/utils/ft_ulltoa_base.c \
				srcs_bonus/parsing/parse_flags_bonus.c \
				srcs_bonus/parsing/parse_width_precision_bonus.c \
				srcs_bonus/parsing/parse_length_bonus.c \
				srcs_bonus/handles/handle_reset_data_bonus.c \
				srcs_bonus/get_value/get_signed_value_bonus.c \
				srcs_bonus/get_value/get_unsigned_value_bonus.c \
				srcs_bonus/get_value/get_wc_utf8_bonus.c \
				srcs_bonus/get_value/get_wstr_utf8_bonus.c \
				srcs_bonus/applys/apply_width_bonus.c \
				srcs_bonus/applys/apply_precision_bonus.c \
				srcs_bonus/applys/apply_precision_int_bonus.c \
				srcs_bonus/applys/apply_sign_bonus.c \
				srcs_bonus/applys/apply_hash_bonus.c \
				srcs_bonus/utils/ft_strfill_bonus.c \
				srcs_bonus/utils/ft_wcrtomb_bonus.c

TEST_SRC =	main.c \
			tester/cheker.c \
			tester/cheker_bonus.c

# OBJECTS
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS	= $(SRCS_BONUS:%.c=$(OBJ_BONUS_DIR)/%.o)
TEST_OBJ	= $(TEST_SRC:%.c=$(OBJ_DIR)/%.o)

# COLORS
MAGENTA	= \033[0;35m
GREEN	= \033[0;32m
RED		= \033[0;31m
BOLD	= \033[1m
RESET	= \033[0m

# RULES
all: $(NAME)

$(LIBFT_LIB):
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@rm -f $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@mkdir -p $(TMP_LIBFT_DIR)
	@cd $(TMP_LIBFT_DIR) && ar x ../$(LIBFT_LIB)
	@for f in $(TMP_LIBFT_DIR)/*.o; do \
		b=$$(basename $$f); \
		case $$b in \
			ft_printf.o|parse_format.o|ft_print_char.o|ft_print_str.o|ft_print_ptr.o|ft_print_int.o|ft_print_u_int.o|ft_print_hex.o) ;; \
			*) ar rcs $(NAME) $$f ;; \
		esac; \
	done
	@rm -rf $(TMP_LIBFT_DIR)
	@ranlib $(NAME)
	@echo "$(BOLD)$(GREEN)✅ ft_printf ready$(RESET)"

bonus: $(LIBFT_LIB) $(OBJS_BONUS)
	@rm -f $(NAME)
	@ar rcs $(NAME) $(OBJS_BONUS)
	@mkdir -p $(TMP_LIBFT_DIR)
	@cd $(TMP_LIBFT_DIR) && ar x ../$(LIBFT_LIB)
	@for f in $(TMP_LIBFT_DIR)/*.o; do \
		b=$$(basename $$f); \
		case $$b in \
			ft_printf.o|parse_format.o|ft_print_char.o|ft_print_str.o|ft_print_ptr.o|ft_print_int.o|ft_print_u_int.o|ft_print_hex.o) ;; \
			*) ar rcs $(NAME) $$f ;; \
		esac; \
	done
	@rm -rf $(TMP_LIBFT_DIR)
	@ranlib $(NAME)
	@echo "$(BOLD)$(GREEN)✅ ft_printf bonus ready$(RESET)"

$(TEST): $(TEST_OBJ) $(NAME)
	@$(CC) $(CFLAGS) $(TEST_OBJ) -L. -lftprintf -o $(TEST)
	@echo "$(BOLD)$(GREEN)✅ program ready$(RESET)"

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_PATH) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: %.c $(HEADER) $(HEADER_BONUS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_PATH) -c $< -o $@

clean:
	@if [ -d "$(OBJ_DIR)" ] || [ -d "$(OBJ_BONUS_DIR)" ] || [ -d "$(TMP_LIBFT_DIR)" ]; then \
		echo "$(BOLD)$(MAGENTA)🧹 Cleaning ft_printf objects...$(RESET)"; \
		rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR) $(TMP_LIBFT_DIR); \
		echo "$(GREEN)✓ ft_printf objects cleaned$(RESET)"; \
	fi
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean

fclean: clean
	@if [ -f "$(NAME)" ] || [ -f "$(TEST)" ]; then \
		echo "$(BOLD)$(MAGENTA)🗑️  Removing ft_printf outputs...$(RESET)"; \
		rm -f $(NAME) $(TEST); \
		echo "$(GREEN)✓ ft_printf outputs removed$(RESET)"; \
	fi
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus
