/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:07:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/10 18:16:31 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "test.h"

void ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
void init_list(t_stack * stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

t_stack *quicksort(t_stack *a)
{
	int med;
	int i;
	t_stack *b;
	t_stack *tmp;
	int len;

	b = malloc(sizeof(t_stack));
	init_list(b);
	med = 22;
	i = 0;
	if (a->size == 1)
		return a;
	while (i++ < a->size)
	{
		if (a->head->data > med)
			push(&b, &a);
		else
			rotate(&a);
	}
	i = 0;
	// while (i < b->size)
	// 	push(&a, &b);
	return (a);
}



int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_st_node *tmp;
	int i;
	void *data;

	int arr[] = {23, 43, 33, 22, 3, 4, 8, 2, 234};
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
	stack_a = quicksort(stack_a);
	i = 0;
	while (i++ < stack_a->size)
	{
		ft_printf("%d ", stack_a->head->data);
		stack_a->head = stack_a->head->next;
	}
}
