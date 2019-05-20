/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:28:49 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/20 17:32:07 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			push(t_stack **stack_dst, t_stack **stack_src)
{
	t_st_node *tmp;

	if (!*stack_src)
		return ;
	tmp = ft_newnode(ft_del_node(stack_src), sizeof(int));
	if ((*stack_src)->size) 
		assign_pos(*stack_src);
	ft_lstadd_at_head(stack_dst, tmp);
	if ((*stack_dst)->size)
		assign_pos(*stack_dst);
}


void			push_with_pos(t_stack **stack_dst, t_stack **stack_src, t_stack **sorted_stack)
{
	t_st_node *tmp;

	if (!*stack_src)
		return ;
	tmp = ft_newnode(ft_del_node(stack_src), sizeof(int));
	if ((*stack_src)->size) 
	{
		assign_pos(*stack_src);
		sort_pos(*stack_src, *sorted_stack);
	}
	ft_lstadd_at_head(stack_dst, tmp);
	if ((*stack_dst)->size)
	{
		assign_pos(*stack_dst);
		sort_pos(*stack_dst, *sorted_stack);
	}
}
