/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_neighb_by_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:18:15 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/04 13:40:04 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_neighb_by_pos(t_stack *a, int pos)
{
    t_st_node *node;

    node = a->head;
    while (node && node->pos != pos)
        node = node->next;
    return (node->neighb_pos);
}
