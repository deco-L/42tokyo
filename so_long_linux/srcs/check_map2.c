/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:15:31 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/11 19:20:30 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_linux.h"

void	ft_mapcheck_empty(t_game *game)
{
	if (game -> map[0] == NULL)
		ft_error_msg("Error\nEmpty map.");
	return ;
}
