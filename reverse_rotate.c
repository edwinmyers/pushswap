/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:33:28 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/23 16:35:45 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack **stack)
{
    t_st_node *tmp;

    if (!(*stack)->tail)
        return ;
    tmp = (*stack)->tail;
    ft_lstadd_at_head(stack, tmp);
    delfromtail(stack);
    assign_pos(*stack);
}