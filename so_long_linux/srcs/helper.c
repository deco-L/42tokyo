/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:05:41 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/14 23:13:25 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_linux.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t				c1_len;
	size_t				c2_len;

	c1_len = ft_strlen(s1);
	c2_len = ft_strlen(s2);
	if (n == 0)
		return (0);
	while (c1_len > 0 && c1[c1_len--] != '\0' && c2[c2_len--] != '\0')
	{
		if (c1[c1_len] != c2[c2_len])
			break ;
	}
	return (c1[c1_len] - c2[c2_len]);
}
