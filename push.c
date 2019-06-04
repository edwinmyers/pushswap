/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:28:49 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/03 18:38:11 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			push(t_stack **stack_dst, t_stack **stack_src, int flag)
{
	t_st_node *tmp;

	if (!(*stack_src)->head)
		return ;
	tmp = ft_newnode((*stack_src)->head->data, sizeof(int), (*stack_src)->head->sort_pos);
	ft_del_node(stack_src);
	if ((*stack_src)->size) 
		assign_pos(*stack_src);
	ft_lstadd_at_head(stack_dst, tmp);
	if ((*stack_dst)->size)
		assign_pos(*stack_dst);
	if (flag == 1)
		ft_printf("pa\n");
	else if (flag == 2)
		ft_printf("pb\n");
}
