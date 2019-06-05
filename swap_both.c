/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:37:01 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/05 13:14:28 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_both(t_stack **stack_a, t_stack **stack_b, int flag)
{
	swap_st(stack_a, 0);
	swap_st(stack_b, 0);
	if (flag != 0)
		ft_printf("ss\n");
}
