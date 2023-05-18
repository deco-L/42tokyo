/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:08:07 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/18 11:07:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c);

char	*ft_strchr(const char *str, int c)
{
	int				i;
	int				flag;
	unsigned char	cbuf;
	char			*result;

	i = 0;
	flag = 0;
	result = (char *)str;
	cbuf = (unsigned char)c;
	if (cbuf == '\0')
		flag++;
	while (result[i] != '\0')
	{
		if (result[i] == cbuf)
			return (&result[i]);
		i++;
	}
	if (flag)
		return (&result[i]);
	return (NULL);
}
