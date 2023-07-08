/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:46:16 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/08 13:13:28 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_array_delete(char **relay)
{
	int	i;

	i = 1;
	while (relay[i] != NULL)
	{
		free(relay[i]);
		i++;
	}
	free(relay[i]);
	free(relay);
}
