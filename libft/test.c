#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

// atoi
// int	main(void)
// {
// 	printf("%d\n", atoi("   --1	\t\v-123gajer"));
// }

// isalnum
// int	main(void)
// {
// 	int		num;
// 	char	c;

// 	c = '!';
// 	num = isalnum(c);
// 	printf("num : %d\n", num);
// 	return (0);
// }

// isdigit
// int	main(void)
// {
// 	printf("isdigit : %d,\n", isdigit('1'));
// 	return (0);
// }

// itoa
// int main(void)
// {
// 	char	result[10];

// 	itoa(10, result, 10);
// 	printf("%s\n", result);
// 	return (0);
// }

// int	main(void)
// {
// 	char	wk[1024];
// 	int i = 0;

// 	i = 12345;
// 	itoa(i, wk, 10);
// 	printf( "wk=%s\n", wk);
// 	// printf("strnstr : %s", strnstr("abcdefg", "de", 6));
// 	return (0);
// }

// strchr
int main(void)
{
	char *s = "libft-test-tokyo";
	if(strchr(s, 'i' - 256))
		printf("Yes\n");
	else
		printf("No\n");
	if (ft_strchr(s, 'l' + 256))
		printf("Yes\n");
	else
		printf("NO\n");
	printf("strchr : %p\n", strchr(s, 'i' - 256));
	printf("ft_strchr : %p\n", ft_strchr(s, 'l' + 256));
	printf("strrchr : %p\n", strrchr(s, '\0'));
	printf("ft_strrchr : %p\n", ft_strrchr(s, '\0'));
	return (0);
}