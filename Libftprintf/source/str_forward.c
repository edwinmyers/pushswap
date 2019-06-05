/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_forward.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:40:08 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 13:04:11 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	move_char_pointer(char **s1)
{
	char	*new_s1;

	if (*s1 == NULL && **s1 == '\0')
		return ;
	new_s1 = NULL;
	if (**s1)
	{
		new_s1 = ft_strdup(*s1 + 1);
		ft_strdel(s1);
		*s1 = new_s1;
	}
}
