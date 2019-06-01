/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:07:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/01 18:29:05 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void			sort_pos(t_stack *orig_stack, t_stack *sort_stack)
{
	t_st_node		*curr_i;
	t_st_node		*curr_j;
	int			i;

	i = 0;
	curr_i = orig_stack->head;
	curr_j = sort_stack->head;
	while (i < orig_stack->size)
	{
		curr_j = sort_stack->head;
		while (curr_j != NULL)
		{
			if (curr_i->data == curr_j->data)
				curr_i->sort_pos = curr_j->sort_pos;
			curr_j = curr_j->next;
		}
		i++;
		curr_i = curr_i->next;
	}
}

void init_list(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->min = 0;
	stack->max = 0;
	stack->mid = 0;
}

void set_kisa(t_stack *stack, int i)
{
	t_st_node *temp;

	temp = stack->head;
	while (i--)
		temp = temp->next;
	temp->kisa = 1;
}

void set_vals(t_stack *orig_stack, t_stack *sorted_stack)
{
	t_st_node *node;
	t_st_node *curr;
	int i;
	int j;

	curr = sorted_stack->head;
	i = 0;
	node = orig_stack->head;
	orig_stack->max = sorted_stack->tail->data;
	orig_stack->min = sorted_stack->head->data;
	orig_stack->mid = get_data_at(sorted_stack, (sorted_stack->size / 2)- 1);
	while (sorted_stack->size && curr != NULL)
	{
		curr->sort_pos = i;
		++i;
		curr = curr->next;
	}
	sort_pos(orig_stack, sorted_stack);
}

char	terminate(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	int	i;
	t_stack	*stack_a;
	t_stack *sorted_stack;
	t_stack *stack_b;

	i = 0;
	if (argc >= 2)
	{
		stack_b = (t_stack*)malloc(sizeof(t_stack));
		init_list(stack_b);
		stack_a = parse_num(argc, argv);
		check_dup(stack_a);
		if (check_sort(stack_a))
			terminate("OK");
		sorted_stack = parse_num(argc, argv);
		assign_pos(stack_a);
		assign_pos(sorted_stack);
		min_num_sort(&sorted_stack);
		set_vals(stack_a, sorted_stack);
		kisa(stack_a);
		// if (stack_a->size < 70)
		new_sort(&stack_a, &sorted_stack);
		// else
		// quick_sort(&stack_a, stack_a->size);
		// min_num_sort(&stack_a);
		while (i++ < stack_a->size)
		{
			ft_printf("%d ", stack_a->head->data);
			stack_a->head = stack_a->head->next;
		}
	}
	else
		terminate("usage: ./push_swap ...");
	return (0);
}
