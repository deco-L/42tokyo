/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:35:04 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/18 21:04:06 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_space(const char *nptr, int i);
int	ft_pulmi(const char *nptr, int i);
int	ft_atoi(const char	*nptr);

int	ft_space(const char *nptr, int i)
{
	int	flag;

	flag = 0;
	if (9 <= nptr[i] && nptr[i] <= 13)
		flag++;
	if (nptr[i] == ' ' || nptr[i] == '	')
		flag++;
	return (flag);
}

int	ft_pulmi(const char *nptr, int i)
{
	int	flag;

	flag = 0;
	if (nptr[i] == '+')
		flag = 1;
	else if (nptr[i] == '-')
		flag = 2;
	return (flag);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	count;
	int	result;

	i = 0;
	count = 0;
	result = 0;
	while (ft_space(nptr, i))
		i++;
	count = ft_pulmi(nptr, i);
	if (ft_pulmi(nptr, i))
		i++;
	while (nptr[i] != '\0')
	{
		if (48 <= nptr[i] && nptr[i] <= 57)
		{
			result = result * 10;
			result += (nptr[i] - '0');
		}
		else
			break ;
		i++;
	}
	if (count == 2)
		result *= -1;
	return (result);
}
