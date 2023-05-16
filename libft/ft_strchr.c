/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:08:07 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/16 19:15:01 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c);

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)str;
	while (result[i] != '\0')
	{
		if (result[i] == c)
			return (&result[i]);
		i++;
	}
	return (NULL);
}
