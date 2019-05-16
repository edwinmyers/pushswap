/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:07:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/16 18:43:47 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int g_kostyl = 0;

void init_list(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

int find_min(t_stack *a)
{
	int min;
	t_st_node *temp;
	int pos;

	pos = 0;
	temp = a->head;
	min = temp->data;
	while (temp)
	{
		if (temp->data < min)
		{
			min = temp->data;
			pos = temp->pos;
		}
		temp = temp->next;
	}
	return (pos);
}

void min_num_sort(t_stack **a)
{
	t_stack *b;
	int min;
	int pos;
	int i;

	i = 0;
	b = malloc(sizeof(t_stack));
	init_list(b);
	while (a_size > 3)
	{
		pos = find_min(*a);
		min = get_data_at(*a, pos);
		if (pos > a_size / 2)
			while (a_head != min)
			{
				ft_printf("rra ");
				reverse_rotate(a);
				g_kostyl++;
			}
		else
			while (a_head != min)
			{
				ft_printf("ra ");
				rotate(a);
				g_kostyl++;
			}
		push(&b, a);
		ft_printf("pb ");
		g_kostyl++;
	}
	while (i++ < a_size)
	{
		if (a_head > a_head_next)
		{
			ft_printf("sa ");
			swap_st(a);
			g_kostyl++;
		}
		while (a_head > a_tail)
		{
			ft_printf("rra ");			
			reverse_rotate(a);
			g_kostyl++;
		}	
	}
	while (b->size)
	{
		ft_printf("pa ");
		g_kostyl++;	
		push(a, &b);
	}
}


int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_st_node *tmp;
	int i;
	void *data;

	int arr[] = {2, 1, 3, 6, 5, 8, 40, 48, 345,  9, 44, 98, 4935, 3548, -432, 324, 89423, -234, 2334, 213, -345, 0, 867432, 423987, 87534, 132, 94783, 137892, 5987, -23, -435, -1123, 593748, -4435, 95843, 142324, 345089, -1238, 95486, 432897, -4, -3, -1, 99, 444, 8234, -123, 45, 34, 93, 90423, 67, 13278, 5498, 3298, 345, 98, 4389, 498, -84179, 345002, 4382, 493, 84188, 3200, 9830, 8738, 653, 6758, 3917, 3916, 1739, 1362, 7855, 7283, 8432, 66446, 4377, 6642, 94275};
	// , 30, 48, 345, 40, 9, 44, 98, 4935, 3548};
	//  40, 9, 44, 98, 4935, 3548, -432, 324, 89423};
	// , -234, 2334, 213, -345, 0, 867432, 423987, 87534, 132, 94783, 137892, 5987, -23, -435, -1123, 593748, -4435, 95843, 142324, 345089, -1238, 95486};
	//  -4, -3, -1, 99, 444, 8234, -123, 45, 34, 93, 90423, 67, 13278, 5498, 3298, 345, 98, 4389, 498};
	stack_a = malloc(sizeof(t_stack));
	init_list(stack_a);
	i = 0;
	while (i < 80)
	{
		ft_lstadd_at_tail(&stack_a, ft_newnode(arr[i], sizeof(int)));
		i++;
		// ft_printf("%d ", *(int*)stack_a->tail->data);
	}
	
	stack_b = malloc(sizeof(t_stack));
	init_list(stack_b);
	assign_pos(stack_a);
	min_num_sort(&stack_a);
	i = 0;
	while (i++ < stack_a->size)
	{
		ft_printf("%d ", stack_a->head->data);
		stack_a->head = stack_a->head->next;
	}
	ft_printf("\n%d", g_kostyl);
}
