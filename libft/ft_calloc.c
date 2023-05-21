/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:04:09 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/20 18:59:32 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*c;
	size_t	i;

	if (nmemb > nmemb * size && size != 0)
		return (NULL);
	c = (void *)malloc(nmemb * size);
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		c[i] = '\0';
		i++;
	}
	return ((void *)c);
}
