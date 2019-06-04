/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:31:03 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/04 13:39:54 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_st_node	*ft_newnode(int data, size_t data_size, int sort_pos)
{
	t_st_node	*node;

	node = (t_st_node*)malloc(sizeof(t_st_node));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->data_size = data_size;
	node->next = NULL;
	node->pos = 0;
	node->sort_pos = sort_pos;
	node->count = 0;
	node->rot = 0;
	node->rev = 0;
	node->neighb_pos = 0;
	node->rrr = 0;
	node->rr = 0;
	node->flag = 0;
	return (node);
}
