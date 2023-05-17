/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:47:31 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/18 02:40:51 by csakamot         ###   ########.fr       */
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
	char			*s1;

	i = 0;
	buff = 0;
	flag = 0;
	cbuf = (char)c;
	s1 = (char *)s;
	if (cbuf == '\0')
		flag++;
	while (s1[i] != '\0')
	{
		if (s1[i] == cbuf)
			buff = i;
		i++;
	}
	if (buff)
		return (&s1[buff]);
	if (flag)
		return (&s1[i]);
	return (NULL);
}
