/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:23:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/01 14:17:08 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

typedef struct s_check
{
	struct s_check	*next;
}					t_check;

void	ft_putnbr_base_fd(int nbr, char *base, int fd);
int		ft_printf(const char *format, ...);

#endif