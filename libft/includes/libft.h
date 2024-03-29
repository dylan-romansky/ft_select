/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:47:25 by dromansk          #+#    #+#             */
/*   Updated: 2019/10/26 02:26:59 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <float.h>
# include <inttypes.h>
# include "printf.h"

# define BUFF_SIZE 69420

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	struct s_node	*top;
}					t_stack;

void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					chr_index(char *s, int c);
int					chr_n_index(char *s, int c, size_t len);
char				*ft_strndup(const char *s1, size_t n);
long double			ft_sqrt(int square, int precision);
long long			ft_factorial(int a);
int					ft_permutations(int n, int r);
char				base_table(int i);
void				ft_putnbr_base(int value, int base);
char				*ft_itoa_base(int value, int base);
char				*ft_ltoa_base(long long value, int base);
char				*ft_ltoa(long long n);
char				*ft_strupper(char *s);
char				*ft_strlower(char *s);
char				*ft_ftoa(double f, size_t prec);
char				*ft_lftoa(long double f, size_t prec);
char				*swap_n_free(char *new, char **old);
char				*ft_strjoin_len(char const *s1, char const *s2, size_t len1,
		size_t len2);
int					ft_isupper(char c);
int					ft_islower(char c);
int					number_length(long long n);
long long			ft_power(int n, int p);
void				print_bin(unsigned long n, int size);
char				*ft_strwht(char *s);
char				**array_join(char **sentence, char *word);
int					ft_new_line(char **s, char **line, int fd, int ret);
int					get_next_line(const int fd, char **line);
struct s_stack		*init_stack(void);
void				*pop(struct s_stack *stack);
void				push(struct s_stack *stack, void *content);
void				*peek(struct s_stack *stack);
int					is_empty(struct s_stack *stack);

#endif
