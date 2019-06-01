/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 18:02:12 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/31 18:03:37 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_flag(t_stack *a, int pos)
{
    t_st_node *node;

    node = a->head;
    while (node && node->pos != pos)
        node = node->next;
    if (node)
        return (node->flag);
    return(-1);
}
