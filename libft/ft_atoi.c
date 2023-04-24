/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakamoto <sakamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:35:04 by sakamoto          #+#    #+#             */
/*   Updated: 2023/04/24 17:29:58 by sakamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char	*nptr);

int	ft_atoi(const char *nptr)
{
	int	i;
	int	count;
	int	result;

	i = 0;
	count = 0;
	result = 0;
	while (9 <= nptr[i] && nptr[i] <= 13)
		i++;
	if (nptr[i] == '-')
	{
		count = 1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0')
	{
		if (48 <= nptr[i] && nptr[i] <= 57)
			result = result * 10 + (nptr[i] - '0');
		else
			break ;
		i++;
	}
	if (count == 1)
		result *= -1;
	return (result);
}
