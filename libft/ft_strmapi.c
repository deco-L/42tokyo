/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayoi <yayoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:27:14 by yayoi             #+#    #+#             */
/*   Updated: 2023/05/15 19:50:12 by yayoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strmapi(const char *str, char (*f)(unsigned int, char));

void	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*result;
	char	*src;

	i = 0;
	if (!str || !f)
		return (NULL);
	src = (char *)str;
	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, src[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
