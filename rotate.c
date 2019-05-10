/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:26:43 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/10 17:50:24 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void rotate(t_stack **stack)
{
    t_st_node *tmp;

    tmp = (*stack)->head;
    (*stack)->head = (*stack)->head->next;
    ft_lstadd_at_tail(stack, tmp);
    (*stack)->size--;
}