NAME1 = push_swap

NAME2 = checker

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/

CC = gcc
FLAGS = -Wall -Werror -Wextra
INC = -I$(HEAD_DIR)

HEAD_FLS = push_swap.h\

HEAD_DIR = ./inc/
HEADER = $(addprefix $(HEAD_DIR), $(HEAD_FLS))

SRC_DIR = ./src/
SRC1_FLS = \
	start.c\
	stack.c\
	parsing.c\
	indx.c\
	sort.c\
	sort_a.c\
	sort_b.c\
	way.c\
	ops_que.c\
	ops1.c\
	ops2.c\
	utils1.c\
	push_swap.c

SRC2_FLS = \
	start.c\
	stack.c\
	parsing.c\
	indx.c\
	sort.c\
	sort_a.c\
	sort_b.c\
	way.c\
	ops_que.c\
	ops1.c\
	ops2.c\
	utils1.c\
	checker.c

SRC1 = $(SRC_DIR) $(SRC1_FLS)
SRC2 = $(SRC_DIR) $(SRC2_FLS)
OBJ_DIR = obj/
OBJ1_FLS = $(patsubst %.c, %.o, $(SRC1_FLS))
OBJ2_FLS = $(patsubst %.c, %.o, $(SRC2_FLS))
OBJ1	= $(addprefix $(OBJ_DIR), $(OBJ1_FLS))
OBJ2	= $(addprefix $(OBJ_DIR), $(OBJ2_FLS))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(LIBFT) $(OBJ_DIR) $(OBJ1)
	@$(CC) $(FLAGS) $(LIBFT) $(INC) $(OBJ1) -o $(NAME1)
	@echo "$(GREEN)$(NAME1) CREATED!$(RESET)"

$(NAME2): $(LIBFT) $(OBJ_DIR) $(OBJ2)
	@$(CC) $(FLAGS) $(LIBFT) $(INC) $(OBJ2) -o $(NAME2)
	@echo "$(GREEN)$(NAME2) CREATED!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	@$(CC) $(FLAGS) -c $(INC) $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)LIBFT OK!$(RESET)"

clean:
	@make -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)CLEAR!$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME1) $(NAME2)
	@echo "$(GREEN)EXTRA CLEAR!$(RESET)"

re:	fclean all
