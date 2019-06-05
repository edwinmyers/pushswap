/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:54:02 by nparker           #+#    #+#             */
/*   Updated: 2019/06/05 13:26:27 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_word_len(char const *str, char c)
{
	size_t			i;
	size_t			len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

int					ft_word_count(char const *str, char c)
{
	size_t			count;
	size_t			i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	int				i;
	size_t			j;
	size_t			k;
	char			**arr;

	i = -1;
	j = 0;
	if (!s || !c)
		return (0);
	arr = (char**)malloc(sizeof(arr) * (ft_word_count(s, c) + 1));
	if (!arr)
		return (0);
	while (++i < ft_word_count(s, c))
	{
		k = 0;
		if (!(arr[i] = ft_strnew(ft_word_len(&s[j], c))))
			ft_free2dmass(arr, i);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			arr[i][k++] = s[j++];
		arr[i][k] = '\0';
	}
	arr[i] = 0;
	return (arr);
}
