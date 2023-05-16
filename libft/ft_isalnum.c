/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:28:15 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/16 16:13:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c);

int	ft_isalnum(int c)
{
	int	flag;

	flag = 0;
	if (48 <= c && c <= 57)
		flag = 1;
	if (65 <= c && c <= 90)
		flag = 1;
	if (97 <= c && c <= 122)
		flag = 1;
	return (flag);
}
