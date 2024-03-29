/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:39:38 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 13:00:06 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	if (flag != 0)
		ft_printf("rr\n");
}
