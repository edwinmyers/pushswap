/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:07:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/14 17:09:31 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int g_kostyl = 0;

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

void merge(t_stack **a, t_stack **b)
{
	int i;

	i = 0;
	
	if ((*a)->size == 1 && (*b)->size == 1)
	{
		g_kostyl++;
		push(a, b);
		ft_printf("pa ");
		if (a_head > a_head_next)
		{
			swap_st(a);
			ft_printf("sa ");
			g_kostyl++;
		}
		return ;
	}
	while ((*b)->size)
	{
		while ((*b)->head->data > (*a)->head->data)
		{
			if (i >= (*a)->size)
				break;
			i++;
			g_kostyl++;
			rotate(a);
			ft_printf("ra ");
		}
		push(a, b);
		ft_printf("pa ");
		g_kostyl++;
	}
	while (i--)
	{
		g_kostyl++;
		ft_printf("rra ");
		reverse_rotate(a);
	}
}

void merge_sort(t_stack **a)
{
	t_stack *b;
	int n;
	int i;
	int j;

	i = 0;
	j = 4;
	if ((*a)->size < 2)
		return ;
	b = malloc(sizeof(t_stack));
	init_list(b);
	n = (*a)->size;
	while ((*a)->size - 1)
	{
		i = 0;
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
		while (a_head < a_head_next)
		{
			// while (b->head && a_head < b_head)
			// {
			// 	push(a, &b);
			// 	g_kostyl+=2;
			// 	ft_printf("pa ");
			// 	swap_st(a);
			// 	ft_printf("sa ");
			// }
			
			while (b->head && b_head > a_head)
			{
				if (b->size == 1)
				{
					push(a, &b);
					swap_st(a);
					ft_printf("pa ");
					ft_printf("sa ");
					break;
					g_kostyl+=2;
				}
				ft_printf("rb ");
				g_kostyl++;
				rotate(&b);
				i++;
			}
			ft_printf("pb ");			
			push(&b, a);
			while (i-- > 0)
			{
				g_kostyl++;
				reverse_rotate(&b);	
			}
			// if (b->head->next && b_head < b_head_next)
			// {
			// 	ft_printf("sb ");
			// 	swap_st(&b);
			// 	g_kostyl++;
			// }
	
			g_kostyl++;
		}
	}
	while (b->size)
	{
		ft_printf("pa ");		
		push(a, &b);
		g_kostyl++;
	}


	
	
	// merge_sort(a);
	
	// while (b->size < n)
	// {
	// 	g_kostyl++;
	// 	push(&b, a);
	// 	// rotate(a);
		
	// 	ft_printf("pb ");
	// 	// ft_printf("ra ");
	// }
	// merge_sort(a);
	// merge_sort(&b);
	// merge(a, &b);
	

}



int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_st_node *tmp;
	int i;
	void *data;

	int arr[] = {4, 2, 1, 3, 50, 36, 45, 30, 48, 40};
	stack_a = malloc(sizeof(t_stack));
	init_list(stack_a);
	i = 0;
	while (i < 10)
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
	ft_printf("\n%d", g_kostyl);
}
