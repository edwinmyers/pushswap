/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:45:18 by nparker           #+#    #+#             */
/*   Updated: 2019/06/06 16:22:01 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	terminate(char *str, int output)
{
	if (output == 1)
		ft_printf("%s\n", str);
	else
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}
