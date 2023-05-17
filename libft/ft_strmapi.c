/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:27:14 by yayoi             #+#    #+#             */
/*   Updated: 2023/05/17 16:04:57 by csakamot         ###   ########.fr       */
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
