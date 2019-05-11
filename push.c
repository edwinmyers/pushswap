/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:28:49 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/11 12:28:50 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack **stack_dst, t_stack **stack_src)
{
    t_st_node *tmp;

    tmp = ft_newnode((*stack_src)->head->data, sizeof(int));
    ft_lstadd_at_head(stack_dst, tmp);
    ft_del_node(stack_src);
}