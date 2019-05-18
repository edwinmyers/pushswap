/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:07:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/18 18:00:24 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void init_list(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->min = 0;
	stack->max = 0;
	stack->mid = 0;
}

void set_vals(t_stack *orig_stack, t_stack *sorted_stack)
{
	t_st_node *node;
	int i;
	int j;

	i = 0;
	node = orig_stack->head;
	orig_stack->max = sorted_stack->tail->data;
	orig_stack->min = sorted_stack->head->data;
	orig_stack->mid = get_data_at(sorted_stack, sorted_stack->size / 2);
	while (i < orig_stack->size)
	{
		j = 0;
		while(get_data_at(orig_stack, i) != get_data_at(sorted_stack, j++))
			;
		
		i++;
	}
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

	i = 0;
	if (argc >= 2)
	{
		stack_a = parse_num(argc, argv);
		check_dup(stack_a);
		if (check_sort(stack_a))
			terminate("OK");
		sorted_stack = parse_num(argc, argv);
		min_num_sort(&sorted_stack);
		set_vals(stack_a, sorted_stack);
		assign_pos(stack_a);
		// if (stack_a->size < 70)
		new_sort(&stack_a);
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
