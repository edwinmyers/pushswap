/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:49:00 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/30 13:04:11 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_fs(char **str, t_fs *form_string)
{
	form_string->flags = get_flags(str);
	form_string->width = get_width(str);
	form_string->precision = get_precision(str);
	form_string->size = get_size(str);
	form_string->type = get_type(str);
	if (**str == '\0')
		ft_strdel(str);
}
