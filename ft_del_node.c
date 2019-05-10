/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:30:51 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/10 18:15:17 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int ft_del_node(t_stack **alst)
{
    int item;

    item = 0;
	if((*alst)->head == NULL)
	{	
		ft_printf("\nList is Empty ..."); 	
		return (-1);
	}
	else
	{
		item = (*alst)->head->data;
		(*alst)->head = (*alst)->head->next;
		(*alst)->size -= 1;		
	}	
	return (item);
}
