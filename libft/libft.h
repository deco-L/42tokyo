#ifndef	LIBFT_H
#define	LIBFT_H


# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *nprt);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);

#endif