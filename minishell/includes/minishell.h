/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:21 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/13 11:22:44 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../srcs/libft/libft_include/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <termios.h>
# include <termcap.h>

typedef struct s_init
{
	char	*prompt;
}				t_init;

#endif