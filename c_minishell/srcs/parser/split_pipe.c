/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:07:28 by hiraiyuina        #+#    #+#             */
/*   Updated: 2023/09/22 12:37:58 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_parser	*split_pipe(char **str, char **one_phrase)
{
	t_parser	*new;
	t_parser	*node;
	char		*tmp;
	size_t	flag;
	size_t	i;
	size_t	j;
	t_file		*file;

	flag = 0;
	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i] != NULL && str[i][0] != '|')
		{
			tmp = ft_strdup(str[i]);
			one_phrase[j] = str[i];
			i++;
			j++;
		}
		if (!flag)
		{
			node = ft_parsernew(ft_command(one_phrase), \
			ft_option(one_phrase), ft_str(one_phrase), ft_redirect(one_phrase));
			flag++;
		}
		else
		{
			new = ft_parsernew(ft_command(one_phrase), \
			ft_option(one_phrase), ft_str(one_phrase), ft_redirect(one_phrase));
			ft_parseradd_back(&node, new);
		}
		printf("%s\n", ft_command(one_phrase));
		if (str[i] != NULL)
			i++;
		// ft_bzero_double(one_phrase);
	}
	while (node != NULL)
	{
		printf("cmd|[%s]%p\n", node->cmd, node->cmd);
		printf("option|[%s]%p\n", node->option, node->option);
		printf("str|[%s]%p\n", node->str, node->str);
		printf("current|%p, prev|%p, next|%p\n", node, node->prev, node->next);
		file = node->redirect;
		while (file != NULL)
		{
			printf("redirect|[%s]%p\n", file->file_name, file->file_name);
			file = file->next;
		}
		printf("=============================\n");
		node = node->next;
	}
	return (node);
}
