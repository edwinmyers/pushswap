/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:31:03 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/22 15:35:33 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_st_node	*ft_newnode(int data, size_t data_size, int orig_pos)
{
	t_st_node *node;

	node = (t_st_node*)malloc(sizeof(t_st_node));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->data_size = data_size;
	node->next = NULL;
	node->pos = 0;
	node->orig_pos = orig_pos;
	node->kisa = 0;
	node->count = 0;
	return (node);
}
