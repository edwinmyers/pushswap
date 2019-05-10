/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:31:03 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/10 18:13:29 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_st_node	*ft_newnode(int data, size_t data_size)
{
	t_st_node *node;

	node = (t_st_node*)malloc(sizeof(t_st_node));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->data_size = data_size;
	node->next = NULL;
	return (node);
}
