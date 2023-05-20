/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:47:31 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/20 18:40:22 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				buff;
	int				flag;
	unsigned char	cbuf;
	unsigned char	*s1;

	i = 0;
	buff = -1;
	flag = 0;
	cbuf = (unsigned char)c;
	s1 = (unsigned char *)s;
	if (cbuf == '\0')
		flag++;
	while (s1[i] != '\0')
	{
		if (s1[i] == cbuf)
			buff = i;
		i++;
	}
	if (buff != -1)
		return (&s1[buff]);
	if (flag)
		return (&s1[i]);
	return (NULL);
}
