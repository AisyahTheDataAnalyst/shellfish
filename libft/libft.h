/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:17:13 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/19 11:12:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// 1024 bytes = 1KB
// 1024 bytes x 64KB = 65536 bytes
// 65536 bytes = 64KB
// 131072 bytes = 128KB
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 131072
# endif

// size_t, malloc&free&NULL, write&read, SIZE_MAX, ssize_t
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/types.h>

//// part 1 - libc functions ////
// character handling functions
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

// string manipulation functions
size_t	ft_array_size(char **s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// memory management functions
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// additional utility functions
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);

//// part 2  - additional functions (not in libc manual / custom) ////
// string manipulation and transformation
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	**ft_split_squote(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// file descriptor output functions
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//// bonus: linked list ////
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	char			**envp_array;
	char			**splitted_path;
	char			*export_name;
	char			*export_value;
}			t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void*(*f)(void *), void (*del)(void *));

// get_next_line.c
char	*get_next_line(int fd);
char	*ft_reading(int fd, char *call);
char	*ft_joining(char *call, char *buffer);
char	*ft_extract(char *call);
char	*ft_storage(char *call);

// get_next_line_utils.c
char	*ft_strjoin_gnl(char const *s1, char const *s2);

// ft_split helper
size_t	ft_wordcount(char const *s, char c);
void	ft_freewords(char **result, size_t i);

#endif 