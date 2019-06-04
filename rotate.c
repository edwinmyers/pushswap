/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:26:43 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/04 14:35:12 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **stack, int flag)
{
    t_st_node *tmp;
    t_st_node *fre;

    if (!(*stack)->head)
        terminate("KO");
    tmp = ft_newnode((*stack)->head->data, sizeof(int), (*stack)->head->sort_pos);
    fre = (*stack)->head;
    (*stack)->head = (*stack)->head->next;
    free(fre);
    ft_lstadd_at_tail(stack, tmp);
    (*stack)->size--;
    assign_pos(*stack);
    if (flag != 0)
        flag == 1 ? ft_printf("ra\n") : ft_printf("rb\n");
}
