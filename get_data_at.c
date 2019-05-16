/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:15:03 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/16 17:36:23 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_data_at(t_stack *stack, int pos)
{
    t_st_node *temp;

    temp = stack->head;
    while(pos-- > 0)
        temp = temp->next;
    return (temp->data);
}
