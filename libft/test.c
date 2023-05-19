#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

// // atoi
// int	main(void)
// {
// 	printf("atoi : %d\n", atoi("2147483650"));
// 	printf("ft_atoi : %d\n", ft_atoi("2147483650"));
// 	printf("atoi : %d\n", atoi("-2147483649"));
// 	printf("ft_atoi : %d\n", ft_atoi("-2147483649"));
// 	printf("atoi : %d\n", atoi("9223372036854775801"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775801"));
// 	printf("atoi : %d\n", atoi("-9223372036854775809"));
// 	printf("ft_atoi : %d\n", ft_atoi("-9223372036854775809"));
// 	printf("atoi : %d\n", atoi("1844674407370955161"));
// 	printf("ft_atoi : %d\n", ft_atoi("1844674407370955161"));
// 	printf("atoi : %d\n", atoi("18446744073709551616"));
// 	printf("ft_atoi : %d\n", ft_atoi("18446744073709551616"));
// }

// int	main(void)
// {
// 	printf("atoi : %d\n", atoi("2147483643"));
// 	printf("atoi : %d\n", atoi("2147483644"));
// 	printf("atoi : %d\n", atoi("2147483645"));
// 	printf("atoi : %d\n", atoi("2147483646"));
// 	printf("atoi : %d\n", atoi("2147483647"));
// 	printf("atoi : %d\n", atoi("2147483648"));
// 	printf("atoi : %d\n", atoi("2147483649"));
// 	printf("atoi : %d\n", atoi("2147483650"));
// 	printf("atoi : %d\n", atoi("4294967293"));
// 	printf("atoi : %d\n", atoi("4294967294"));
// 	printf("atoi : %d\n", atoi("4294967295"));
// 	printf("atoi : %d\n", atoi("4294967296"));
// 	printf("atoi : %d\n", atoi("4294967297"));
// 	printf("atoi : %d\n", atoi("4294967298"));
// 	printf("atoi : %d\n", atoi("4294967299"));
// 	printf("atoi : %d\n", atoi("4294967300"));
// 	printf("atoi : %d\n", atoi("9223372036854775805"));
// 	printf("atoi : %d\n", atoi("9223372036854775806"));
// 	printf("atoi_max : %d\n", atoi("9223372036854775807"));
// 	printf("atoi : %d\n", atoi("9223372036854775808"));
// 	printf("atoi : %d\n", atoi("9223372036854775809"));
// 	printf("atoi : %d\n", atoi("9223372036854775810"));
// 	printf("atoi : %d\n", atoi("9223372036854775811"));
// 	printf("atoi : %d\n", atoi("9223372036854775812"));
// 	printf("atoi : %d\n", atoi("-9223372036854775803"));
// 	printf("atoi : %d\n", atoi("-9223372036854775804"));
// 	printf("atoi : %d\n", atoi("-9223372036854775805"));
// 	printf("atoi : %d\n", atoi("-9223372036854775806"));
// 	printf("atoi : %d\n", atoi("-9223372036854775807"));
// 	printf("atoi_min : %d\n", atoi("-9223372036854775808"));
// 	printf("atoi : %d\n", atoi("-9223372036854775809"));
// 	printf("atoi : %d\n", atoi("-9223372036854775810"));
// 	printf("atoi : %d\n", atoi("-9223372036854775811"));
// 	printf("atoi : %d\n", atoi("-9223372036854775812"));
// 	printf("atoi : %d\n", atoi("-9223372036854775813"));
// 	printf("atoi : %d\n", atoi("-9223372036854775814"));
// 	printf("atoi : %d\n", atoi("10000000000000000000"));
// 	printf("atoi : %d\n", atoi("18446744073709551615"));
// 	printf("atoi : %d\n", atoi("18446744073709551616"));
// 	printf("atoi : %d\n", atoi("18446744073709551617"));
// 	// printf("atoi : %d\n", atoi("100000000000000000000"));
// 	// printf("atoi : %d\n", atoi("1000000000000000000000"));
// 	// printf("atoi : %d\n", atoi("10000000000000000000000"));
// 	printf("atoi : %d\n\n", atoi("10000000000000000000000000"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775807"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775808"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775809"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775810"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775811"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775812"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775813"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775814"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775815"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775816"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775817"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775818"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775819"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775820"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775821"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775822"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775823"));
// 	printf("ft_atoi : %d\n", ft_atoi("9223372036854775824"));
// 	printf("ft_atoi : %d\n", ft_atoi("10000000000000000000"));
// 	printf("ft_atoi : %d\n", ft_atoi("18446744073709551615"));
// 	printf("ft_atoi : %d\n", ft_atoi("18446744073709551616"));
// 	printf("ft_atoi : %d\n", ft_atoi("18446744073709551617"));
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

// // strncmp
// int	main(void)
// {
// 	char *str = "libft";
// 	char *cmp = "libft-test-tokyo";
// 	int	len = strlen(str);
// 	char *cmp2 = calloc(10, 1);
// 	strlcpy(cmp2, "libft", 10);

// 	cmp2[5] = -1;
// 	printf("strncmp : %d\n", strncmp(str, cmp, len));
// 	printf("ft_strncmp : %d\n", ft_strncmp(str, cmp, len));
// 	return (0);
// }

// // memchr
// int	main(void)
// {
// 	char *s = calloc(30, sizeof(char));
// 	memcpy(s, "libft-test-tokyo", 17);
// 	memcpy(s + 20, "acdfg", 5);

// 	printf("memchr : %p\n", memchr(s, '\0',30));
// 	printf("ft_memchr : %p\n", ft_memchr(s, '\0',30));
// 	return (0);
// }

// // strnstr
// int	main(void)
// {
// 	printf("strstr : %p\n", strnstr("", "", 0));
// 	printf("ft_strstr : %p\n", ft_strnstr("", "", 0));
// 	printf("strstr : %p\n", strnstr("libft-test-tokyo", "test", 10));
// 	printf("ft_strstr : %p\n", ft_strnstr("libft-test-tokyo", "test", 10));
// 	return (0);
// }

// // calloc
// int	main(void)
// {
// 	printf("calloc : %p\n", calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10));
// 	printf("calloc : %p\n", ft_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10));
// 	printf("size_t_MAX : %zu\n", SIZE_MAX / 10 + 1);
// 	return (0);
// }

// // substr
// int	main(void)
// {
// 	char *s = "libft-test-tokyo";
// 	printf("%s\n", ft_substr(s, 20, 100));
// }

// // strjoin
// int	main(void)
// {
// 	printf("strjoin : %s\n", ft_strjoin("hello", "world"));
// 	return (0);
// }

// split
int	main(void)
{
	char	**result;
	char	**result1;
	result = ft_split("hello,world,42,tokyo", ',');
	result1 = ft_split("\0aa\0bbb", '\0');
	for (int i = 0; i < 5; i++)
	{
		printf("ft_split : %s\n", result[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("result[%d] : %s\n", i, result1[i]);
	}
	return (0);
}

// int	main(void)
// {
// 	printf("|%s|\n", (ft_strtrim("hello world", "world"), "hello "));
// 	printf("|%s|\n", (ft_strtrim("hello world", "hello"), " world"));
// 	printf("|%s|\n", (ft_strtrim("hello world", ""), "hello world"));
// 	printf("|%s|\n", (ft_strtrim("", ""), ""));
// 	printf("|%s|\n", (ft_strtrim("    hello world     ", " "), "hello world"));
// 	printf("|%s|\n", (ft_strtrim(" \n\t\r    hello \n\t\r world     \r\t\n\t \r\n", " \n\t\r"), "hello \n\t\r world"));
// 	printf("|%s|\n", (ft_strtrim("hello world", "abcdefghijklmnopqrstuvwxyz"), " "));
// }

// int	main(void)
// {
// 	int		size;
// 	size_t	i;

// 	size = 5;
// 	i = 3;
// 	while (size--)
// 	{
// 		i--;
// 	}
// 	printf("size_t minus : %zu\n", i);
// 	return (0);
// }
