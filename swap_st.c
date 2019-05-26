/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:05:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/26 18:08:56 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_st(t_stack **stack)
{
    int tmp;
    int tmp2;

    if (!*stack)
        return ;
    tmp = (*stack)->head->data;
    tmp2 = (*stack)->head->sort_pos;
    (*stack)->head->data = (*stack)->head->next->data;
    (*stack)->head->sort_pos = (*stack)->head->next->sort_pos;
    (*stack)->head->next->data = tmp;
    (*stack)->head->next->sort_pos = tmp2;
    assign_pos(*stack);
}
