/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:23:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/02 17:15:56 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

# define CHAR		1
# define STRING		2
# define POINT		3
# define DECIMAL	4
# define INTEJER	5
# define UNSIGNED	6
# define HEXALOW	7
# define HEXAUPP	8
# define PERCENT	9

typedef struct s_check
{
	int				type;
	int				length;
}					t_check;

int		ft_printf(const char *format, ...);
int		ft_putnbr_fd_cnt(int n, int digit, int fd);
int		ft_putnbr_base_fdcnt(unsigned long long nbr, int digit, char *base);
void	ft_process(va_list stat, t_check *check);
void	ft_ch_printf(const char *format, va_list stat, int i, t_check *check);
void	ft_process_litter(va_list stat, t_check *check);
void	ft_process_point(va_list stat, t_check *check);
void	ft_process_number(va_list stat, t_check *check);
void	ft_process_hexa(va_list stat, t_check *check);

#endif