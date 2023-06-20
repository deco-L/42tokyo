/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:12:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/20 20:35:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include "../srcs/ft_printf/ft_printf.h"

typedef struct s_node
{
	long long		content;
	struct s_node	*next;
	struct s_node	*prev;
	int				flag;
}				t_node;


void	ft_input_arg_error(int argc, char **argv);
void	ft_arg_less(void);
void	ft_one_arg_check(char **argv);
void	ft_args_check(int argc, char **argv);

#endif