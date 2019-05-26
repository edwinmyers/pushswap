/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:46:26 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/26 15:03:29 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_count_by_origpos(t_stack *stack, int pos)
{
    t_st_node *temp;

    temp = stack->head;
    while (temp && temp->sort_pos != pos)
        temp = temp->next;
    if (temp)
        return (temp->count);
    else
        return (-1);
}
