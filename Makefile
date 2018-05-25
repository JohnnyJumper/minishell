NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g
 
SRC_PATH = ./src/
EXE_PATH = ./bin/
INCLUDE_PATH = ./include/
LIBFT_PATH = ./libft/
OBJ_PATH = ./obj/
LIBFT = $(LIBFT_PATH)libft.a

SRC_NAME = main.c ft_utility.c ft_parse.c ft_init.c ft_builtins.c ft_builtins2.c

SRC = $(patsubst %, $(SRC_PATH)%, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(patsubst %, $(OBJ_PATH)%, $(OBJ_NAME))

all: $(NAME)

$(NAME): libs $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(DEBUG) $(OBJ) $(LIBFT)
	@mkdir -p $(EXE_PATH)
	@cp $(NAME) $(EXE_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ $(CFLAGS) $(DEBUG) -c $<

libs:
	@+make -C $(LIBFT_PATH)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(EXE_PATH)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: clean fclean 
