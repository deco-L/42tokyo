/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:28:15 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/29 14:22:46 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c);

int	ft_isalnum(int c)
{
	int	flag;

	flag = 0;
	if ('0' <= c && c <= '9')
		flag = 1;
	if ('A' <= c && c <= 'Z')
		flag = 1;
	if ('a' <= c && c <= 'z')
		flag = 1;
	return (flag);
}
