/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exclusion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:57:02 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 13:04:11 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_exclusion_of_letter(char *str, char letter, char letter1, char letter2)
{
	int i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] != letter && str[i] != letter1 && str[i] != letter2)
			return (1);
		i++;
	}
	return (0);
}
