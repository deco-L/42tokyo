/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_to_i_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:22:03 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/12 12:36:16 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minilibx_test_mac.h"

int	ctoi_create_trgb(t_uchar t, t_uchar r, t_uchar g, t_uchar b)
{
	return (*(int *)(t_uchar [4]){b, g, r, t});
}

t_uchar	ctoi_get_t(int trgb)
{
	return (((t_uchar *)&trgb)[3]);
}

t_uchar	cto_iget_r(int trgb)
{
	return (((t_uchar *)&trgb)[2]);
}

t_uchar	ctoi_get_g(int trgb)
{
	return (((t_uchar *)&trgb)[1]);
}

t_uchar	ctoi_get_b(int trgb)
{
	return (((t_uchar *)&trgb)[0]);
}
