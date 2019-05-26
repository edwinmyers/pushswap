/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_in_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:45:51 by nparker           #+#    #+#             */
/*   Updated: 2019/05/26 15:03:29 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int kisa_by_value(t_stack **stack, int pos, int flag)
{
    t_st_node *node;
    int val;
    int i;

    node = (*stack)->head;
    i = 0;
    val = get_data_at(*stack, pos);
    while (node->data != val)
        node = node->next;
    node->kisa = flag ? 1 : 0;
    while (node)
    {
        if (val < node->data)
        {
            node->kisa = flag ? 1 : 0;
            val = node->data;
            i++;
        }
        node = node->next;
    }
    return (i);
}


int            kisa_by_index(t_stack **stack, int pos, int flag)
{
    t_st_node   *node;
    int         index;
    size_t      iter;

    index = pos;
    node = (*stack)->head;
    node->kisa = flag ? 1 : 0;
    iter = 0;
    while (node->pos != pos)
        node = node->next;
    while(node)
    {
        if (node->sort_pos == (index + 1))
        {
            node->kisa = flag ? 1 : 0;
            index = node->sort_pos;
            iter++;
        }
        node = node->next;
    }
    return (iter);
}

void kisa(t_stack *stack)
{
    int i;
    int max;
    int j;
    int k;

    k = 0;
    i = 0;
    j = 0;
    max = 0;
    while (i < (stack->size / 2) + 1)
    {
      max = kisa_by_index(&stack, i, 0) > max ? kisa_by_index(&stack, i, 0), j++ : max;
       max = kisa_by_value(&stack, i, 0) > max ? kisa_by_value(&stack, i, 0), k++ : max;
        i++;
    }
    j > k ? kisa_by_index(&stack, j - 1, 1) : kisa_by_value(&stack, k - 1, 1);




}