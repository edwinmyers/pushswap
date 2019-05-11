/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:05:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/11 12:29:48 by nparker          ###   ########.fr       */
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
