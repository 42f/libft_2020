/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:13:26 by bvalette          #+#    #+#             */
/*   Updated: 2020/05/22 16:57:49 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
**  MEMORIES FUNCTIONS
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);

/*
**  CHAR FUNCTIONS
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**  STRINGS FUNCTIONS
*/

size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
																	size_t len);
long long int		ft_atoi(const char *str);
int					ft_atoi_base(const char *str, char *base);
char				*ft_strdup(const char *s1);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);

/*
**  EXTA FUNCTIONS
*/

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(long long int n);
char				*ft_itoa_base(long long n, char *base);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putnbr(int n);
void				ft_putstr(char *s);
int					ft_putchar(wchar_t c);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_base(long long int nbr, char *base);

/*
**  BITS FUNCTIONS
*/

unsigned int		ft_reversebits(unsigned int num);

/*
**	LISTS FUNCTIONS
*/

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
														void (*del)(void *));

/*
**  OTHER 42 PROJECTS FUNCTIONS
*/

/*
**  GET NEXT LINE IS
**	FUNCTION THAT READS ONE LINE AT EACH CALL FROM A GIVEN FD
**	CAN BE CALLED WITH DIFFERENT FD EVERYTIME AND KEEP READING THE FILES
**	LINE BY LINE WITHOUT MIXING DIFFERENT FILES
*/

typedef struct		s_gnl_l
{
	int				fd;
	char			*ct;
	struct s_gnl_l	*next;
}					t_gnl_l;

t_gnl_l				*ft_create_node(int new_fd, char *ct);
t_gnl_l				*ft_lst_manager(t_gnl_l *cursor, int fd_to_find);
t_gnl_l				*ft_free_fd_cursor(t_gnl_l *fd_head, int fd);
int					get_next_line(int fd, char **line);
char				*ft_gnl_strchr(const char *s, int c);
size_t				ft_gnl_strlcat(char *dst, const char *src, size_t dstsize);

#endif
