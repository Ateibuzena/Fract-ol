/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:13:53 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/08 13:10:38 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

// Definition of type t_size if not defined to libft
# ifndef T_SIZE
#  define T_SIZE

typedef unsigned int	t_size;

# endif

//Struct to counters
# ifndef S_NUMBERS
#  define S_NUMBERS

typedef struct s_numbers
{
	int	x;
	int	y;
	int	h;
	int	w;
	int	i;
	int	j;
	int	n;
	int	s;
	int	t;
}	t_numbers;

# endif

//Struct to split
# ifndef S_SPLIT
#  define S_SPLIT

typedef struct s_split
{
	char	**mtx;
	int		i;
	int		init;
	int		j;
	int		word;
}	t_split;

# endif

//Struct to libft_bonus
# ifndef S_LIST
#  define S_LIST

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

# endif

// Struct to ft_itoa
# ifndef ITOA
#  define ITOA

typedef struct Itoa
{
	long	i;
	char	*ptr;
	char	*temp;
	int		index;
}	t_Itoa;

# endif

// Struct to ft_printf
# ifndef S_FORMAT
#  define S_FORMAT

typedef struct s_format
{
	char				id;
	int					(*func)(va_list args);
	struct s_format		*next;
}	t_format;

# endif

// Struct to get_netx_line_bonus
# ifndef S_FDNODE
#  define S_FDNODE

typedef struct s_fdnode
{
	char			*buffer;
	int				fd;
	struct s_fdnode	*next;
}	t_fdnode;

# endif

// Buffer to get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

/*SRC/D_ASCII/*/
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
bool		ft_isspace(char c);

/*SRC/D_FDS/*/
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*SRC/D_GET_NEXT_LINE/*/

char		*get_next_line(int fd);
void		ft_free_all_nodes(t_fdnode **list);
char		*ft_freenode(t_fdnode **list, int fd);
t_fdnode	*ft_newnode(int fd);
char		*ft_strjoin_getnextline(char *s1, char *s2);
char		*ft_free(char *ptr);

/*SRC/D_LISTS/*/
t_list		*ft_lstnew(void *ptr);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*SRC/D_MEMORY/*/
void		*ft_memset(void *array, int value, t_size len);
void		ft_bzero(void *array, t_size len);
void		*ft_memcpy(void *dst, const void *src, t_size n);
void		*ft_memmove(void *dst, const void *src, t_size len);
void		*ft_memchr(const void *s, int c, t_size n);
int			ft_memcmp(const void *s1, const void *s2, t_size n);
void		*ft_calloc(t_size count, t_size size);

/*SRC/D_PRINTF/*/
int			ft_printf(const char *format, ...);
int			ft_init_handlers(t_format **head);
int			ft_add_handler(t_format **lst, char id, int (*func)(va_list));
void		ft_free_handlers(t_format *list);
int			ft_call_handler(t_format *formats, char id, va_list args);
int			ft_putchar_printf(char c);
int			ft_handle_char(va_list args);
int			ft_putstr_printf(char *s);
int			ft_handle_string(va_list args);
int			ft_handle_digits(va_list args);
int			ft_handle_integer(va_list args);
int			ft_handle_unsigned(va_list args);
int			ft_puthex_printf(unsigned long n, int uppercase);
int			ft_handle_hex_lower(va_list args);
int			ft_handle_hex_upper(va_list args);
int			ft_handle_pointer(va_list args);
int			ft_handle_percent(va_list args);

/*SRC/D_STRINGS/*/
char		*ft_strncpy(char *dest, const char *src, size_t n);
t_size		ft_strlen(const char *s);
t_size		ft_strlcpy(char *dst, const char *src, t_size dstsize);
char		*ft_strcpy(char *dst, const char *src);
t_size		ft_strlcat(char *dst, const char *src, t_size dstsize);
char		*ft_strcat(char *dst, const char *src);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
int			ft_strncmp(const char *s1, const char *s2, t_size n);
char		*ft_strnstr(const char *hay, const char *need, t_size len);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_substr(char const *s, unsigned int start, t_size len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strisnumber(char *str);

/*SRC/*/
int			ft_atoi(const char *str);
char		**ft_split(char const *str, char c);
char		*ft_itoa(int n);
void		ft_freedouble(char **ptr);
void		ft_freedouble_array(int **array, int len);
void		ft_free_partialdouble(char **arr, int size);
int			ft_strlen_double(char **str);
long		ft_strtol(const char *str, char **endptr, int base, int *error);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char		*ft_strclean(const char *str, char to_clean);
char		**ft_clean_double(char **original, char to_clean);

/*ft_strtol_utils.c*/
int			ft_check_overflow(long result, int digit, int base, int sign);
int			ft_get_digit(char c);
long		ft_handle_overflow(int *error, int sign);

// End of LIBFT_H
#endif
