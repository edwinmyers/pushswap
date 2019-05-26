/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:40:05 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/26 15:03:29 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_dup(t_stack *src)
{
    t_stack *new;
    t_st_node *temp;

    temp = src->head;
    new = malloc(sizeof(t_stack));
    init_list(new);
    while (temp)
    {
        ft_lstadd_at_tail(&new, ft_newnode(temp->data, sizeof(int), temp->sort_pos));
        temp = temp->next;
    }
    return(new);
}
