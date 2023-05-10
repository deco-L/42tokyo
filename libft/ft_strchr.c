/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakamoto <sakamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:08:07 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/10 17:13:25 by sakamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c);

char	*ft_strchr(const char *str, int c)
{
	int		i;
	int		flag;
	char	*result;

	i = 0;
	flag = 0;
	result = (char *)str;
	while (result[i] != '\0')
	{
		if (result[i] == c)
		{
			flag++;
			break ;
		}
		i++;
	}
	if (flag == 1)
	{
		return (&result[i]);
	}
	return (NULL);
}
