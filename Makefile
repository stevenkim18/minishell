CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = minishell

GNL = get_next_line.c get_next_line_utils.c
GNL_DIR = ./src/gnl/
GNLS = $(addprefix $(GNL_DIR), $(GNL))

SRC = main.c
SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR), $(SRC))

UTIL = ft_handle_error.c ft_handle_pipe.c ft_handle_process.c ft_handle_signal.c ft_handle_data.c
UTIL_DIR = ./src/utils/
UTILS = $(addprefix $(UTIL_DIR), $(UTIL))

COMMAND = ft_handle_command.c ft_exec_command.c
COMMAND_DIR = ./src/command/
COMMANDS = $(addprefix $(COMMAND_DIR), $(COMMAND))

LIB_H = -I ./src/libft
LIB = libft.a

TEST_NAME = test.out
TEST = test.ft_trim_str.c test.ft_handle_error.c test.ft_handle_pipe.c test.ft_handle_data.c
TEST_DIR = ./src/test/
TESTS = $(addprefix $(TEST_DIR), $(TEST))
TEST_H = -I ~/.brew/include
TEST_LIB = -L ~/.brew/lib -lcriterion

INCLUDE = -I ./include

SRC_OBJ = $(SRCS:%.c=%.o)
GNL_OBJ = $(GNLS:%.c=%.o)
COMMAND_OBJ = $(COMMANDS:%.c=%.o)
UTIL_OBJ = $(UTILS:%.c=%.o)
TEST_OBJ = $(TESTS:%.c=%.o)


LEAK = valgrind
LEAK_FLAG = --leak-check=full --track-origins=yes -s
LEAK_PREFIX = ./
LEAK_OBJ = $(addprefix $(LEAK_PREFIX), $(NAME))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(SRC_OBJ) $(GNL_OBJ) $(COMMAND_OBJ) $(UTIL_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(LIB) $(SRC_OBJ) $(COMMAND_OBJ) $(UTIL_OBJ) $(GNL_OBJ) $(INCLUDE) $(LIB_H) -g -o $(NAME)

test: $(GNL_OBJ) $(COMMAND_OBJ) $(TEST_OBJ) $(SRC_OBJ) $(UTIL_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(LIB) $(GNL_OBJ) $(COMMAND_OBJ) $(UTIL_OBJ) $(TEST_OBJ) $(TEST_LIB) $(INCLUDE) $(LIB_H) -o$(TEST_NAME)

$(LIB):
	cd ./src/libft; make bonus
	cp ./src/libft/libft.a libft.a

.c.o:
	$(CC) $(CFLAGS) $(LIB_H) $(INCLUDE) $(TEST_H) -o $@ -c $<

clean:
	cd ./src/libft; make fclean
	rm -rf $(SRC_OBJ) $(GNL_OBJ) $(COMMAND_OBJ) $(TEST_OBJ) $(UTIL_OBJ) $(LIB)

fclean : clean
	rm -rf $(NAME) $(TEST_NAME)

norm :
	norminette $(TEST) $(SRCS) $(GNLS) $(COMMANDS) ./include/minishell.h

re: fclean all

leaks: re
	$(LEAK) $(LEAK_FLAG) $(LEAK_OBJ)

.PHONY: clean fclean all re
