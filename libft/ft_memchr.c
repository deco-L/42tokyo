/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:38:38 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/18 12:27:31 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n);

void	*ft_memchr(const void *buf, int c, size_t n)
{
	int				flag;
	size_t			i;
	const char		*dest;
	unsigned char	cbuf;
	void			*result;

	i = 0;
	flag = 0;
	dest = (char *) buf;
	cbuf = (unsigned char)c;
	while (i < n)
	{
		if (dest[i] == cbuf)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 1 || cbuf == '\0')
	{
		result = (void *)&dest[i];
		return (result);
	}
	return (NULL);
}
