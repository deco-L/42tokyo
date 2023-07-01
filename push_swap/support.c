/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:46:16 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/01 13:05:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) == -1)
			exit(EXIT_FAILURE);
		i++;
	}
	return ;
}

void	ft_array_delete(char **relay)
{
	int	i;

	i = 1;
	free(relay[0]);
	while (relay[i] != NULL)
	{
		free(relay[i]);
		i++;
	}
	free(relay[i]);
	free(relay);
}
