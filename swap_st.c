/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:05:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/06 13:21:02 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_st(t_stack **stack, int flag)
{
	int	tmp;
	int	tmp2;

	if ((*stack)->size < 2)
		return ;
	tmp = (*stack)->head->data;
	tmp2 = (*stack)->head->sort_pos;
	(*stack)->head->data = (*stack)->head->next->data;
	(*stack)->head->sort_pos = (*stack)->head->next->sort_pos;
	(*stack)->head->next->data = tmp;
	(*stack)->head->next->sort_pos = tmp2;
	assign_pos(*stack);
	if (flag != 0)
		flag == 1 ? ft_printf("sa\n") : ft_printf("sb\n");
}
