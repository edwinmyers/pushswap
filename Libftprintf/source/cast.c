/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:36:57 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 13:02:05 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cast(t_fs *form_string, long long *arg)
{
	if (form_string->size == NULL)
		*arg = (int)*arg;
	else if (ft_strcmp(form_string->size, "l") == 0)
		*arg = (long)*arg;
	else if (ft_strcmp(form_string->size, "hh") == 0)
		*arg = (char)*arg;
	else if (ft_strcmp(form_string->size, "h") == 0)
		*arg = (short int)*arg;
}

void	f_cast(t_fs *form_string, long double *arg)
{
	if (ft_strchr(form_string->size, 'L') == 0)
		*arg = (double)*arg;
}
