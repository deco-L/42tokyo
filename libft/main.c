#include "libft.h"

int	main(void)
{
	char	dest[10] = "abcdefghi";
	char	src[13] = "jklmnopqrstu";

	printf("ft_atoi : %d\n",ft_atoi("   	\t\v-129851h3gajer"));
	printf("ft_isalnum : %d\n", ft_isalnum('!'));
	printf("ft_isalpha : %d\n", ft_isalpha('1'));
	printf("ft_isascii : %d\n", ft_isascii(200));
	printf("ft_isdigit : %d\n", ft_isdigit('a'));
	printf("ft_isprint : %d\n", ft_isprint('\n'));
	printf("ft_itoa : %s\n", ft_itoa(-100));
	printf("ft_memccpy : %p\n", ft_memccpy(dest, src, 'd', 9));
	printf("ft_memchr : %p\n", ft_memchr(dest, 'e', 9));
	printf("ft_memcmp : %d\n", ft_memcmp(dest, src, 14));
	printf("ft_memcpy : %s\n", (char *)ft_memcpy(dest, src, 2));
	ft_putstr_fd("ft_putchar_fd : ", 1);
	ft_putchar_fd('0', 1);
	printf("\n");
	ft_putstr_fd("ft_putstr_fd : ", 1);
	ft_putstr_fd(dest, 1);
	printf("\n");
	ft_putstr_fd("ft_putendl_fd : ", 1);
	ft_putendl_fd(src, 1);
	ft_putstr_fd("ft_putnbr_fd : ", 1);
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
	printf("ft_strchr : %p\n", ft_strchr(dest, 'e'));
	printf("ft_strlen : %zu\n", ft_strlen(dest));
	printf("ft_tolower : %c\n", ft_tolower('A'));
	printf("ft_toupper : %c\n", ft_toupper('c'));
	return (0);
}
