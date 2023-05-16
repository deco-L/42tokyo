/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:49:06 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/16 16:13:16 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c);

int	ft_isalpha(int c)
{
	int	flag;

	flag = 0;
	if (65 <= c && c <= 90)
		flag = 1;
	if (97 <= c && c <= 122)
		flag = 1;
	return (flag);
}
