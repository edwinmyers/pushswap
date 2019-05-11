/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:07:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/11 15:23:15 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void init_list(t_stack * stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void quicksort(t_stack **a, int n)
{
	int med;
	int i;
	t_stack *b;
	t_stack *tmp;
	int len = 0;

	b = malloc(sizeof(t_stack));
	init_list(b);
	med = ((*a)->head->data + (*a)->tail->data) / 2;
	i = 0;
	if (n == 1)
		return ;
	while (i < n)
	{
		if ((*a)->head->data > med)
		{
			len++;
			push(&b, a);
		}
		rotate(a);
		i++;
	}
	i = 0;
	while (i++ < (n - len))
		reverse_rotate(a);
	while (b->size)
		push(a, &b);
	if (len > 0)
		quicksort(a, len);
	i = 0;
	while (i++ < len)
		rotate(a);
	if (n > len) 
		quicksort(a, n - len);
	i = 0;
	while (i++ < len)
		reverse_rotate(a);
	return ;
}



int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_st_node *tmp;
	int i;
	void *data;

	int arr[] = {23, 43, 33, 22, 3, 4, 8, 2, 48};
	stack_a = malloc(sizeof(t_stack));
	init_list(stack_a);
	i = 0;
	while (i < 9)
	{
		ft_lstadd_at_tail(&stack_a, ft_newnode(arr[i], sizeof(int)));
		i++;
		// ft_printf("%d ", *(int*)stack_a->tail->data);
	}
	stack_b = malloc(sizeof(t_stack));
	init_list(stack_b);
	quicksort(&stack_a, stack_a->size);
	i = 0;
	while (i++ < stack_a->size)
	{
		ft_printf("%d ", stack_a->head->data);
		stack_a->head = stack_a->head->next;
	}
}
