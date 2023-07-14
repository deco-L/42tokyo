/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:50:40 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/14 22:23:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_linux.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_closing_process(game);
	return (0);
}
