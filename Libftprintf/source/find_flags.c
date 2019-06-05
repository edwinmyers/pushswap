/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:58:07 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 13:04:11 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isflag(int c)
{
	if (ft_strchr("cspdiouxXf", c))
		return (1);
	return (0);
}

int			find_the_flags(char **str)
{
	int i;

	i = 0;
	while (((*str)[i] && !ft_isalpha((*str)[i])) || ((*str)[i] == 'l'
							|| (*str)[i] == 'L' || (*str)[i] == 'h'))
	{
		if ((*str)[i + 1] && (*str)[i + 1] == '%')
		{
			i++;
			break ;
		}
		i++;
	}
	if (!ft_isflag((*str)[i]) && (*str)[i] != '%')
		i--;
	return (i);
}
