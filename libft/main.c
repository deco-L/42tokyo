#include "libft.h"

int	main(void)
{
	char	dest[10] = "abcdefghi";
	char	src[5] = "abcd";

	printf("ft_atoi : %d\n",ft_atoi("   	\t\v-129851h3gajer"));
	printf("ft_isalnum : %d\n", ft_isalnum('!'));
	printf("ft_isalpha : %d\n", ft_isalpha('1'));
	printf("ft_isascii : %d\n", ft_isascii(200));
	printf("ft_isdigit : %d\n", ft_isdigit('a'));
	printf("ft_isprint : %d\n", ft_isprint('\n'));
	printf("ft_itoa : %s\n", ft_itoa(-100));
	printf("ft_memcpy : %s\n", ft_memcpy(dest, src, 3));
	printf(" : ft_putchar_fd");
	ft_putchar_fd('0', 1);
	printf("\n");
	return (0);
}
