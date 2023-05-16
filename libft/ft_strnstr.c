/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:54:58 by yayoi             #+#    #+#             */
/*   Updated: 2023/05/16 20:14:01 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nbr;
	char	*s1;

	s1 = (char *)haystack;
	i = 0;
	nbr = 0;
	while (nbr < len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i] == needle[j] && needle[j] != '\0' && nbr < len)
		{
			nbr++;
			i++;
			j++;
		}
		i -= j;
		if (needle[j] == '\0')
			return (&s1[i]);
		nbr++;
		i++;
	}
	return (NULL);
}
