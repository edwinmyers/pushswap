/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:33:32 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 13:01:03 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bignum		*big_num_create(void)
{
	t_bignum	*num;

	num = (t_bignum *)malloc(sizeof(t_bignum));
	num->sign = '+';
	num->int_part = str_create_size(5);
	num->frac_part = str_create_size(5);
	return (num);
}
