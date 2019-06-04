/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:50:14 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/04 13:40:24 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_rev(t_stack *a, int pos)
{
    t_st_node *node;

    node = a->head;
    while (node && node->pos != pos)
        node = node->next;
    if (node)
        return (node->rev);
    return (-1);
}

int get_rrr(t_stack *a, int pos)
{
    t_st_node *node;

    node = a->head;
    while (node && node->pos != pos)
        node = node->next;
    if (node)
        return (node->rrr);
    return (-1);
}
