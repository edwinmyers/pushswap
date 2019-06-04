/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:33:28 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/04 14:35:26 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack **stack, int flag)
{
    t_st_node *tmp;

    if (!(*stack)->tail)
        terminate("KO");
    tmp = (*stack)->tail;
    ft_lstadd_at_head(stack, tmp);
    delfromtail(stack);
    assign_pos(*stack);
    if (flag != 0)
		flag == 1 ? ft_printf("rra\n") : ft_printf("rrb\n");
}
