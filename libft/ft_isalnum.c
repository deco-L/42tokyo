/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakamoto <sakamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:28:15 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/02 16:46:16 by sakamoto         ###   ########.fr       */
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
