/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:21:42 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 13:04:11 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr_free(char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char*)str);
		move_char_pointer(&str);
	}
	if (c == '\0')
	{
		while (*str != '\0')
			move_char_pointer(&str);
		return (char*)(str);
	}
	return (NULL);
}
