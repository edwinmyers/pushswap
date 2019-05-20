/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_in_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:45:51 by nparker           #+#    #+#             */
/*   Updated: 2019/05/20 18:51:07 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void kisa_by_value(t_stack *stack)
{
    t_st_node *curr;
    t_st_node *node;
    int val;

    curr = stack->head;
    node = stack->head;
    val = stack->min;
    while (node->data != val)
        node = node->next;
    node->kisa = 1;
    while (node)
    {
        if (val < node->data)
        {
            node->kisa = 1;
            val = node->data;
        }     
        node = node->next;
    }
}


// void kisa_by_value()