/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:47:31 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/24 15:30:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*s1;
	unsigned char	cbuf;

	len = ft_strlen(s);
	s1 = (unsigned char *) s;
	cbuf = (unsigned char) c;
	while (len)
	{
		if (s1[len] == cbuf)
			return ((char *)&s1[len]);
		len--;
	}
	if (s1[len] == cbuf)
		return ((char *)&s1[len]);
	return (NULL);
}
