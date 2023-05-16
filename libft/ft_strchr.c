/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:08:07 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/16 16:14:31 by csakamot         ###   ########.fr       */
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
