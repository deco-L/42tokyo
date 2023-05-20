/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:28:36 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/20 17:17:38 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_split(const char *str, char c);
static int		ft_check_split(char str, char c);
static int		ft_word_cnt(const char *str, char c);
static int		ft_letter_cnt(const char *str, char c, int i);
static char		*ftinsp(char *dest, const char *str, int letter_cnt, int i);

static int	ft_check_split(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

static int	ft_word_cnt(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (ft_check_split(str[i], c))
		{
			i++;
			continue ;
		}
		count++;
		while (!ft_check_split(str[i], c) && str[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_letter_cnt(const char *str, char c, int i)
{
	int	letter_cnt;

	letter_cnt = 0;
	while (!ft_check_split(str[i], c) && str[i] != '\0')
	{
		letter_cnt++;
		i++;
	}
	return (letter_cnt);
}

static char	*ftinsp(char *dest, const char *str, int letter_cnt, int i)
{
	int	j;

	j = 0;
	while (j < letter_cnt)
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		words;
	int		lcnt;
	int		count;
	char	**result;

	i = 0;
	count = 0;
	words = ft_word_cnt(str, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);
	while (count < words)
	{
		while (ft_check_split(str[i], c))
			i++;
		lcnt = ft_letter_cnt(str, c, i);
		result[count] = ftinsp(malloc(sizeof(char) * (lcnt + 1)), str, lcnt, i);
		if (result[count] == NULL)
			return (NULL);
		count++;
		i += lcnt;
	}
	result[count] = NULL;
	return (result);
}
