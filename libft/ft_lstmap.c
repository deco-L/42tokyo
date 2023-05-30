/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:07:55 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/30 16:50:29 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(f(lst -> content));
	if (!new)
	{
		ft_lstdelone(lst, del);
		return (NULL);
	}
	while (lst -> next)
	{
		tmp = ft_lstnew(f(lst -> content));
		if (!tmp)
		{
			ft_lstdelone(tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst -> next;
	}
	return (new);
}
