/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:30:51 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/11 16:27:20 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_del_node(t_stack **alst)
{
    int item;

    item = 0;
	if((*alst)->head == NULL)
	{	
		ft_printf("\nList is Empty ..."); 	
		return (-1);
	}
	else if ((*alst)->size == 1)
	{	
		(*alst)->head = NULL;
		(*alst)->tail = NULL;
	}
	else
	{
		item = (*alst)->head->data;
		(*alst)->tail->next = (*alst)->head->next;
		(*alst)->head = (*alst)->head->next;
	}
	(*alst)->size -= 1;		
	return (item);
}

int delfromtail(t_stack **alst)
{
	t_st_node *temp;
	int item;

	item = 0;
	if((*alst)->tail == NULL)
	{	
		printf("\nList is Empty ..."); 	
		return -1;
	}
	else
	{
		temp = (*alst)->head;
		while(temp->next != (*alst)->tail)
			temp = temp->next;
		item = (*alst)->tail->data;
		(*alst)->tail = temp; 
		(*alst)->tail->next = NULL;	
	}
	(*alst)->size--;
	return (item);
}
