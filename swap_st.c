/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:05:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/13 15:43:18 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_st(t_stack **stack)
{
    int tmp;

    if (!*stack)
        return ;
    tmp = (*stack)->head->data;
    (*stack)->head->data = (*stack)->head->next->data;
    (*stack)->head->next->data = tmp;
}
