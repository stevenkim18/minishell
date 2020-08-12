CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = minishell

GNL = get_next_line.c get_next_line_utils.c
GNL_DIR = ./src/gnl/
GNLS = $(addprefix $(GNL_DIR), $(GNL))

SRC = main.c
SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR), $(SRC))

PARSING = ft_handle_parsing.c
PARSING_DIR = ./src/parsing/
PARSINGS = $(addprefix $(PARSING_DIR), $(PARSING))

LIB_H = -I ./src/libft
LIB = libft.a

TEST_NAME = test
TEST =
TEST_DIR = ./src/test/
TESTS = $(addprefix $(TEST_DIR), $(TEST))
TEST_H = -I ~/.brew/include
TEST_LIB = -L ~/.brew/lib -lcriterion


INCLUDE = -I ./include

SRCS_OBJ = $(SRCS:%.c=%.o)
GNL_OBJ = $(GNLS:%.c=%.o)
PARSING_OBJ = $(PARSINGS:%.c=%.o)
TEST_OBJ = $(TESTS:%.c=%.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(SRCS_OBJ) $(GNL_OBJ) $(PARSING_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(LIB) $(SRCS_OBJ) $(PARSING_OBJ) $(GNL_OBJ) -o $(NAME)

test: $(GNL_OBJ) $(PARSING_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(LIB) $(GNL_OBJ) $(PARSING_OBJ) $(TEST_OBJ) $(TEST_LIB) -o $(TEST_NAME)

$(LIB):
	cd ./src/libft; make bonus
	cp ./src/libft/libft.a libft.a

.c.o:
	$(CC) $(CFLAGS) $(LIB_H) $(INCLUDE) $(TEST_H) -o $@ -c $<

clean:
	cd ./src/libft; make fclean
	rm -rf $(SRCS_OBJ) $(GNL_OBJ) $(PARSING_OBJ) $(TEST_OBJ) $(LIB)

fclean : clean
	rm -rf $(NAME) $(TEST_NAME)

norm :
	norminette $(TEST) $(SRCS) $(GNLS) $(PARSINGS) ./include/minishell.h

re: fclean all

.PHONY: clean fclean all re
