/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:42:20 by nparker           #+#    #+#             */
/*   Updated: 2019/05/17 14:36:41 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_strtoll(const char *str)
{
	long long res;
	long long neg;

	res = 0;
	neg = 0;
	if (str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\f' || *str == '\v')
			str++;
		if (*str == '-')
		{
			neg = 1;
			str++;
		}
		else if (*str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			res += *str++ - '0';
			if (*str >= '0' && *str <= '9')
				res *= 10;
		}
	}
	return (neg ? -res : res);
}
