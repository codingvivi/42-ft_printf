NAME = libftprintf.a

.DEFAULT_GOAL := all

CC = cc

CFLAGS = -Wall -Wextra -Werror -fPIE

AR = ar -rcs

RM = rm -rf

INCLUDES = -I./src

FILES = ft_printf \
		ft_pf_putchar_fd \
		ft_pf_putstr_fd \
		ft_pf_putptr_fd \
		ft_pf_putnbr_base_fd

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(FILES:%=$(SRC_DIR)/%.c)

OBJS = $(FILES:%=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
