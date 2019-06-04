/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_both.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:40:39 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/03 15:50:23 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrotate_both(t_stack **stack_a, t_stack **stack_b, int flag)
{
    reverse_rotate(stack_a, 0);
    reverse_rotate(stack_b, 0);
    if (flag != 0)
        ft_printf("rrr\n");
}
