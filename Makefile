CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = minishell

GNL = get_next_line.c get_next_line_utils.c
GNL_DIR = ./src/gnl/
GNLS = $(addprefix $(GNL_DIR), $(GNL))

SRC = main.c
SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR), $(SRC))

TEST_NAME = test
TEST =
TEST_DIR = ./src/test/
TESTS = $(addprefix $(TEST_DIR), $(TEST))
TEST_H = -I ~/.brew/include
TEST_LIB = -L ~/.brew/lib -lcriterion

INCLUDE = -I ./include

SRCS_OBJ = $(SRCS:%.c=%.o)
GNL_OBJ = $(GNLS:%.c=%.o)
TEST_OBJ = $(TESTS:%.c=%.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(SRCS_OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(SRCS_OBJ) $(GNL_OBJ) -o $(NAME)

test: $(GNL_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(GNL_OBJ) $(TEST_OBJ) $(TEST_LIB) -o $(TEST_NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) $(TEST_H) -o $@ -c $<

clean:
	rm -rf $(SRCS_OBJ) $(GNL_OBJ)

fclean : clean
	rm -rf $(NAME)

norm :
	norminette $(TEST) $(SRCS) $(GNLS) ./include/minishell.h

re: fclean all

.PHONY: clean fclean all re
