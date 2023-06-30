/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:30:46 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/30 16:29:17 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include "./../srcs/libft/libft.h"
# include "./../srcs/ft_printf/ft_printf.h"

/*
client
*/

void	ft_send_signal(int pid, unsigned char chare);

/*
server
*/

#endif