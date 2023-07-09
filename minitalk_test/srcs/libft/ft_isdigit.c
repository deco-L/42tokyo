/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:06:05 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/29 14:21:28 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c);

int	ft_isdigit(int c)
{
	int	flag;

	flag = 0;
	if ('0' <= c && c <= '9')
		flag = 1;
	return (flag);
}
