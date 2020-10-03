NAME = asm
CC = gcc
# FLAGS = -Wall -Wextra -Werror -O2

LIBFT_DIR = libft-21
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_H = $(LIBFT_DIR)/inc

FT_PRINTF_DIR = ft_printf-21
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

ASM_DIR = asm-21
ASM_SRC = $(ASM_DIR)/*.c

all: $(NAME)

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

$(FT_PRINTF): $(FT_PRINTF_DIR)
	make -C $(FT_PRINTF_DIR)

$(NAME): $(LIBFT) $(FT_PRINTF) $(ASM_SRC)
	$(CC) $(FLAGS) $(ASM_SRC) $(FT_PRINTF) $(LIBFT) -o $(NAME) -I $(LIBFT_H) -I .

clean:
	rm -f $(NAME)

fclean: clean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
