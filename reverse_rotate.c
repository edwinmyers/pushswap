/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:33:28 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/06 13:21:47 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		reverse_rotate(t_stack **stack, int flag)
{
	t_st_node	*tmp;

	if ((*stack)->size < 2)
		return ;
	tmp = (*stack)->tail;
	ft_lstadd_at_head(stack, tmp);
	delfromtail(stack);
	assign_pos(*stack);
	if (flag != 0)
		flag == 1 ? ft_printf("rra\n") : ft_printf("rrb\n");
}
