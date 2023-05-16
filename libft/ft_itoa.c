/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:50:17 by yayoi             #+#    #+#             */
/*   Updated: 2023/05/16 16:16:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n);
int		get_digit(int n);
char	*insert_number(int n, char *result, unsigned int digit);

int	get_digit(int n)
{
	unsigned int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*insert_number(int n, char *result, unsigned int digit)
{
	int	flag;

	flag = 0;
	if (n < 0)
	{
		n *= -1;
		flag++;
	}
	result[digit] = '\0';
	while (digit > 0)
	{
		result[digit - 1] = n % 10 + '0';
		n /= 10;
		digit--;
	}
	if (flag)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char				*result;
	unsigned int		digit;

	digit = get_digit(n);
	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (!result)
		return (NULL);
	result = insert_number(n, result, digit);
	return (result);
}
