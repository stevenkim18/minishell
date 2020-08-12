/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:27:04 by dakim             #+#    #+#             */
/*   Updated: 2020/07/27 16:10:38 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdbool.h>

int				ft_atoi(char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nelem, size_t elsize);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strlen(char *str);
int				ft_strlen_w(wchar_t *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
t_list			*ft_lstclear_front_bonus(t_list **list);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstnew_bonus(void *content);
int				ft_lstadd_back_bonus(t_list **lst, t_list *new);

int				ft_check_char(char *delimiter, char c);
void			ft_lst_putstr_fd(t_list *lst, int fd);
int				ft_putnbr_fd_return_int(int n, int fd);

int				ft_putnbr_fd_unsigned_int(unsigned int n, int fd);
int				ft_putnbr_fd_unsigned_int_h(unsigned short n, int fd);
int				ft_putnbr_fd_unsigned_int_hh(unsigned char n, int fd);
int				ft_putnbr_fd_unsigned_int_l(unsigned long n, int fd);
int				ft_putnbr_fd_unsigned_int_ll(unsigned long long n, int fd);

int				ft_putstr_fd_int(char *s, int fd);

int				ft_putnbr_fd_only_number(int n, int fd);
int				ft_putnbr_fd_only_number_h(short n, int fd);
int				ft_putnbr_fd_only_number_hh(char n, int fd);
int				ft_putnbr_fd_only_number_l(long n, int fd);
int				ft_putnbr_fd_only_number_ll(long long n, int fd);

int				ft_get_digit_i(int n, int base);
int				ft_get_digit_h(short n, short base);
int				ft_get_digit_hh(char n, char base);
int				ft_get_digit_l(long n, long base);
int				ft_get_digit_ll(long long n, long long base);

int				ft_get_digit_uhh(unsigned char n, unsigned char base);
int				ft_get_digit_uh(unsigned short n, unsigned short base);
int				ft_get_digit_ui(unsigned int n, unsigned int base);
int				ft_get_digit_ul(unsigned long n, unsigned long base);
int				ft_get_digit_ull(unsigned long long n,
								unsigned long long base);
int				ft_get_dight_zu(size_t n, size_t base);

int				ft_putnbr_action_ui(unsigned int value, int fd,
								unsigned int base, bool is_capital);
int				ft_putnbr_action_ul(unsigned long value, int fd,
								unsigned long base, bool is_capital);
int				ft_putnbr_action_ull(unsigned long long value, int fd,
								unsigned long long base, bool is_capital);
int				ft_putnbr_base_uh(unsigned short value, int fd,
							unsigned short base, bool is_capital);
int				ft_putnbr_base_uhh(unsigned char value, int fd,
							unsigned char base, bool is_capital);

int				ft_putnbr_base_ui(unsigned int value, int fd,
							unsigned int base, bool is_capital);
int				ft_putnbr_base_ul(unsigned long value, int fd,
									unsigned long base, bool is_capital);
int				ft_putnbr_base_ull(unsigned long long value, int fd,
							unsigned long long base, bool is_capital);
int				ft_putnbr_base_l(long value, int fd,
									long base, bool is_capital);
int				ft_putnbr_action_uh(unsigned short value, int fd,
								unsigned short base, bool is_capital);
int				ft_putnbr_action_uhh(unsigned char value, int fd,
								unsigned char base, bool is_capital);

#endif
