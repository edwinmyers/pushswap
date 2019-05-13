/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:07:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/11 18:15:16 by vice-wra         ###   ########.fr       */
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

// void quicksort(t_stack **a, int n)
// {
// 	int med;
// 	int i;
// 	t_stack *b;
// 	t_stack *tmp;
// 	int len = 0;

// 	b = malloc(sizeof(t_stack));
// 	init_list(b);
// 	med = ((*a)->head->data + (*a)->tail->data) / 3;
// 	i = 0;
// 	if (n == 1)
// 		return ;
// 	while (i < n)
// 	{
// 		if ((*a)->head->data > med)
// 		{
// 			len++;
// 			push(&b, a);
// 		}
// 		else 
// 			rotate(a);
// 		i++;
// 	}
// 	i = 0;
// 	while (i++ < (n - len))
// 		reverse_rotate(a);
// 	while (b->size)
// 		push(a, &b);
// 	if (len > 0)
// 		quicksort(a, len);
// 	i = 0;
// 	while (i++ < len)
// 		rotate(a);
// 	if (n > len) 
// 		quicksort(a, n - len);
// 	i = 0;
// 	while (i++ < len)
// 		reverse_rotate(a);
// 	return ;
// }

void merge_sort(t_stack **a)
{
	t_stack *b;
	int i;
	int j;

	j = 0;
	i = 0;
	b = malloc(sizeof(t_stack));
	init_list(b);
	while (b->size <= (*a)->size / 2)
		push(&b, a);
	while (b->size)
	{	
		if (b->head->data < (*a)->head->data)
			push(a, &b);
		else
		{
			j++;
			rotate(a);
			if (i++ > (*a)->size)
				break;
		}
	}
	i = 0;
	while (j && i++ <= j + 1)
	{
		if ((*a)->head->data > (*a)->tail->data)
			reverse_rotate(a);
		else
			push(&b, a);
	}
	if (b->size > 0)
	{
		while (b->size)
			push(a, &b);	
		merge_sort(a);
	}
}



int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_st_node *tmp;
	int i;
	void *data;

	int arr[] = {45, 43, 345, 22, 3, 4, 8, 2, 48};
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
	merge_sort(&stack_a);
	i = 0;
	while (i++ < stack_a->size)
	{
		ft_printf("%d ", stack_a->head->data);
		stack_a->head = stack_a->head->next;
	}
}
