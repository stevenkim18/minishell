C = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_check_char_bonus.c ft_get_digit_s_bonus.c ft_get_digit_n_bonus.c ft_putnbr_fd_bonus.c ft_putstr_fd_bonus.c ft_putnbr_base_n_bonus.c ft_putnbr_base_s_bonus.c ft_putnbr_base_action_bonus.c ft_get_digit_bonus_fin.c
SRCS_B =  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c  ft_lstiter.c ft_lstmap.c ft_check_char_bonus.c ft_lst_putstr_fd_bonus.c ft_lstadd_back_bonus.c ft_lstnew_bonus.c ft_putnbr_fd_h_bonus.c ft_putnbr_fd_hh_bonus.c ft_putnbr_fd_l_bonus.c ft_putnbr_fd_ll_bonus.c
OBJS = $(SRCS:%.c=%.o)
OBJS_B = $(SRCS_B:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
bonus: $(OBJS) $(OBJS_B)
	ar rc $(NAME) $(OBJS) $(OBJS_B)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
