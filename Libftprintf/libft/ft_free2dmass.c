/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2dmass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:53:53 by nparker           #+#    #+#             */
/*   Updated: 2019/06/03 15:57:58 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_free2dmass(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		res[i] = NULL;
		i--;
	}
	free(res);
	res = NULL;
}
