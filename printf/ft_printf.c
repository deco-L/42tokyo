/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:31:48 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/02 17:28:08 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "libftprintf.h"

static int		ft_output(const char *format, va_list stat);
static int		ft_sp_output(const char *format, va_list stat, int i);
int				ft_printf(const char *format, ...);


int	ft_output(const char *format, va_list stat)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*format)
	{
		if (format[i] != '%')
		{
			ft_putchar_fd((char *)&format[i], 1);
			i++;
		}
		len += ft_sp_output(format, stat, ++i);
		i += 2;
	}
	return (len);
}

int	ft_sp_output(const char *format, va_list stat, int i)
{
	int		len;
	t_check	*check;

	check = (t_check *)ft_calloc(1, sizeof(t_check));
	ft_check_printf(format, stat, i, check);
	len = check -> length;
	free(check);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	stat;
	int		count;

	// if (!format)
	// 	return (0);
	count = 0;
	va_start(stat, format);
	count = ft_output(format, stat);
	return (count);
}
