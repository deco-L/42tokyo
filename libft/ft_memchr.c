/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:38:38 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/16 16:14:04 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n);

void	*ft_memchr(const void *buf, int c, size_t n)
{
	int			flag;
	size_t		i;
	const char	*dest;
	void		*result;

	i = 0;
	flag = 0;
	dest = (char *) buf;
	while (dest[i] != '\0' && i < n)
	{
		if (dest[i] == c)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 1)
	{
		result = (void *)&dest[i];
		return (result);
	}
	return (NULL);
}
