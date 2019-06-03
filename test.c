/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:07:20 by vice-wra          #+#    #+#             */
/*   Updated: 2019/06/03 14:26:18 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

char	terminate(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *sorted_stack;

	if (argc >= 2)
	{
		stack_a = parse_num(argc, argv);
		check_dup(stack_a);
		if (check_sort(stack_a))
			terminate("OK");
		sorted_stack = parse_num(argc, argv);
		assign_pos(stack_a);
		assign_pos(sorted_stack);
		min_num_sort(&sorted_stack);
		set_vals(stack_a, sorted_stack);
		if (stack_a->size < 5)
			min_num_sort(&stack_a);
		else
			new_sort(&stack_a, &sorted_stack);
		if (!check_sort(stack_a))
			terminate("FUCK\n");
		while (stack_a->size--)
		{
			ft_printf("%d ", stack_a->head->data);
			stack_a->head = stack_a->head->next;
		}
	}
	else
		terminate("usage: ./push_swap ...");
	return (0);
}
