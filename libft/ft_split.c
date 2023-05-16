/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:28:36 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/16 16:16:24 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *str, char c);
int		ft_check(char str, char c);
int		ft_word_cnt(const char *str, char c);
int		ft_letter_cnt(const char *str, char c, int i);

int	ft_check(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

int	ft_word_cnt(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_check(str[i], c))
		{
			i++;
			continue ;
		}
		count++;
		while (!ft_check(str[i], c) && str[i] != '\0')
			i++;
	}
	return (count);
}

int	ft_letter_cnt(const char *str, char c, int i)
{
	int	letter_cnt;

	letter_cnt = 0;
	while (ft_check(str[i], c) && str[i] != '\0')
	{
		letter_cnt++;
		i++;
	}
	return (letter_cnt);
}

char	*ft_in(char *dest, char *str, int letter_cnt, int i)
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
		while (ft_check(str[i], c))
			i++;
		lcnt = ft_letter_cnt(str, c, i);
		result[count] = ft_in(malloc(sizeof(char) * (lcnt + 1)), str, lcnt, i);
		if (result[count] == NULL)
			return (NULL);
		count++;
		i += lcnt;
	}
	result[count] = NULL;
	return (result);
}
