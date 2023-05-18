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

// // strchr
// int main(void)
// {
// 	char *s = "libft-test-tokyo";
// 	if(strchr(s, 'i' - 256))
// 		printf("Yes\n");
// 	else
// 		printf("No\n");
// 	if (ft_strchr(s, 'l' + 256))
// 		printf("Yes\n");
// 	else
// 		printf("NO\n");
// 	printf("strchr : %p\n", strchr(s, 'i' - 256));
// 	printf("ft_strchr : %p\n", ft_strchr(s, 'l' + 256));
// 	printf("strrchr : %p\n", strrchr(s, 'l'));
// 	printf("ft_strrchr : %p\n", ft_strrchr(s, 'l'));
// 	return (0);
// }

// // memmove
// int	main(void)
// {
// 	char	*src = malloc(20);
// 	for (int i = 0; i < 100; i++)
// 		src[i] = i + '0';
// 	char	*dst = malloc(20);
// 	printf("memmove : %s\n", (char *)memmove(dst, src, 10));
// 	printf("ft_memmove : %s\n", (char *)ft_memmove(dst, src, 10));
// 	return (0);
// }

// // strlcat
// int	main(void)
// {
// 	char	*dest1 = calloc(100, sizeof(char));
// 	char	*dest2 = calloc(100, sizeof(char));
// 	char *src1 = calloc(100, sizeof(char));
// 	char *src2 = calloc(100, sizeof(char));
// 	for (int i = 0; i < 99; i++)
// 	{
// 		src1[i] = i + 1;
// 		src2[i] = i + 1;
// 	}
// 	printf("strlcat : %zu\n", strlcat(NULL, src1, 0));
// 	printf("ft_strlcat : %zu\n", ft_strlcat(NULL, src2, 0));
// 	// printf("strlcat : %zu\n", strlcat(dest1, NULL, 0));
// 	// printf("ft_strlcat : %zu\n", ft_strlcat(dest2, NULL, 0));
// }

// strncmp
int	main(void)
{
	char *str = "libft";
	char *cmp = "libft-test-tokyo";
	int	len = strlen(str);
	char *cmp2 = calloc(10, 1);
	strlcpy(cmp2, "libft", 10);

	cmp2[5] = -1;
	printf("strncmp : %d\n", strncmp(str, cmp, len));
	printf("ft_strncmp : %d\n", ft_strncmp(str, cmp, len));
	return (0);
}
