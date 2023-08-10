/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:34:19 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/10 19:55:50 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nbuf;

	if (lst && del)
	{
		while (*lst)
		{
			nbuf = (*lst)-> next;
			del ((*lst)-> content);
			free (*lst);
			*lst = nbuf;
		}
	}
}
