/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:34:19 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/30 15:53:42 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*nbuf;

	if (lst && del)
	{
		tmp = *lst;
		while (*lst)
		{
			nbuf = (*lst)-> next;
			del ((*lst)-> content);
			free (*lst);
			*lst = nbuf;
		}
		tmp = NULL;
	}
}
