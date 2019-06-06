/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:07:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/06 16:30:32 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void				free_stack(t_stack **stack)
{
	t_st_node	*node;
	t_st_node	*temp;

	temp = (*stack)->head;
	while ((*stack)->size--)
	{
		node = temp;
		temp = temp->next;
		free(node);
		node = NULL;
	}
	free(*stack);
}

int					main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*sorted_stack;

	if (argc < 2)
		terminate("usage: ./push_swap ...", 2);
	stack_a = parse_num(argc, argv);
	check_dup(stack_a);
	if (check_sort(stack_a))
		exit(EXIT_SUCCESS);
	sorted_stack = parse_num(argc, argv);
	assign_pos(stack_a);
	assign_pos(sorted_stack);
	min_num_sort(&sorted_stack, 0);
	set_vals(stack_a, sorted_stack);
	if (stack_a->size <= 10)
		min_num_sort(&stack_a, 1);
	else
		new_sort(&stack_a, &sorted_stack);
	if (!check_sort(stack_a))
		terminate("FUCK\n", 2);
	free_stack(&stack_a);
	free_stack(&sorted_stack);
	exit(EXIT_SUCCESS);
}
