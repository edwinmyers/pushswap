/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:14:40 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/22 16:01:33 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_count_by_currpos(t_stack *stack, int pos, int count)
{
    t_st_node *temp;

    temp = stack->head;
    while(temp && pos-- > 0)
        temp = temp->next;
    if(temp)
        temp->count = count;
}

void set_count_by_orig_pos(t_stack *stack, int pos, int count)
{
    t_st_node *temp;

    temp = stack->head;
    while (temp && temp->orig_pos != pos)
        temp = temp->next;
    if(temp)
        temp->count = count;
}