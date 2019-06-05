/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:25:43 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 13:04:11 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_rev_str(char *str)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	res = ft_strnew(len);
	res[len] = '\0';
	while (len-- > 0)
		res[len] = str[i++];
	return (res);
}
