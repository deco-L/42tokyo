/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:56:47 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/08 13:40:02 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	ft_forsplit_ch(char str)
{
	if ((9 <= str && str <= 13) || str == ' ')
		return (1);
	return (0);
}

static int	ft_words_count(char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i] != '\0')
	{
		if (ft_forsplit_ch(argv[i]))
			i++;
		if (argv[i] == '-' || argv[i] == '+' || ft_isdigit(argv[i]))
		{
			count++;
			i++;
			while (ft_isdigit(argv[i]))
				i++;
		}
	}
	return (count);
}

static int	ft_litter_count(char *argv)
{
	int	count;

	count = 0;
	while (!ft_forsplit_ch(*argv))
	{
		argv++;
		count++;
	}
	return (count);
}

static void	ft_split_error(char **relay, int words)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (i < words)
	{
		if (relay[i] == NULL)
		{
			flag++;
			break ;
		}
		i++;
	}
	if (flag)
	{
		while (--i)
			free(relay[i]);
		free (relay);
	}
	ft_printf("Malloc error.");
	exit(EXIT_FAILURE);
}

char	**ft_format_input(char *argv, char **relay)
{
	int	i;
	int	words;
	int	litter;

	i = 1;
	words = 1;
	words += ft_words_count(argv);
	relay = (char **)malloc(sizeof(char *) * (words + 1));
	if (!relay)
		ft_malloc_error();
	while (i < words)
	{
		while (ft_forsplit_ch(*argv))
			argv++;
		litter = ft_litter_count(argv);
		relay[i] = (char *)malloc(sizeof(char) * (litter + 1));
		if (!relay[i])
			ft_split_error(relay, words);
		ft_strlcpy(relay[i], argv, litter + 1);
		argv += litter;
		i++;
	}
	relay[i] = NULL;
	return (relay);
}
