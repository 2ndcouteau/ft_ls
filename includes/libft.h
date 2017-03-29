/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:38:35 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 19:42:49 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

# define BUFF_SIZE 1024

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Print Fonctions
*/
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_clair(char const *s);

/*
** Str Fonctions
*/
size_t				ft_strlen(const char *s);
size_t				ft_nbrlen(int nbr);

int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);

char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_bzero(void *s, size_t n);
void				ft_strclr(char *s);
void				ft_strdel(char **as);

/*
** Transform ASCII Fonctions
*/
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** IS (bool) Fonctions
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

/*
** Mem Fonctions
*/
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void *ptr, size_t size);
void				ft_memdel(void **ap);

/*
** List Fonctions
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

/*
** Files Fonctions
*/
bool				ft_file_exists(const char *filename);

/*
** Get_Next_Line
*/
int					get_next_line(int const fd, char **line);

#endif
