/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:06:05 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/16 16:13:52 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c);

int	ft_isdigit(int c)
{
	int	flag;

	flag = 0;
	if (48 <= c && c <= 57)
		flag = 1;
	return (flag);
}
