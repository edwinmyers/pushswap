/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:45:09 by nparker           #+#    #+#             */
/*   Updated: 2019/06/03 17:07:16 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# define BUFF_SIZE 50

int					get_next_line(const int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strncpy(char *str1, const char *str2, size_t len);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
int					ft_atoi(const char *str);
char				*ft_strncat(char *dst, const char *app, size_t len);
char				*ft_strchr(const char *str, int c);
char				*ft_strndup(const char *s1, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *source, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
int					ft_max(int x, int y);
int					count_lines(char **temp);
int					**ft_arr2alloc(int n, int m);
void				ft_arr2free(int **arr, int n);
int					ft_pow(int n, int power);
int					ft_hex_to_dec(char *str);
int					ft_min(int n, int m);
void				ft_free2dmass(char **res, int i);
int					ft_word_count(char const *str, char c);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstdel_begin(t_list **lst);
int					ft_lstlen(t_list *lst);
void				ft_pushback(t_list **head, t_list *elem);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst,
								void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef struct		s_vector
{
	int				*data;
	int				size;
	int				capacity;
}					t_vector;

t_vector			ft_vec_create(int size);
void				ft_vec_resize(t_vector *v);
void				ft_vec_push_back(t_vector *v, int elem);
int					ft_vec_at(t_vector v, int index);

#endif
