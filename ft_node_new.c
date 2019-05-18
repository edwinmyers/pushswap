/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:31:03 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/18 20:00:02 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_st_node	*ft_newnode(int data, int orig_pos, size_t data_size)
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
	return (node);
}
