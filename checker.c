/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:49:19 by nparker           #+#    #+#             */
/*   Updated: 2019/06/05 13:35:58 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define VERBOSE check_flags[0]
#define COLOR	check_flags[1]

void			instruction(t_stack *a, t_stack *b, char *line, int flag)
{
	if (ft_strequ(line, "pb"))
		push(&b, &a, flag == 1 ? 1 : 0);
	else if (ft_strequ(line, "pa"))
		push(&a, &b, flag == 1 ? 2 : 0);
	else if (ft_strequ(line, "sa"))
		swap_st(&a, flag == 1 ? 1 : 0);
	else if (ft_strequ(line, "sb"))
		swap_st(&b, flag == 1 ? 2 : 0);
	else if (ft_strequ(line, "ss"))
		swap_both(&a, &b, flag == 1 ? 3 : 0);
	else if (ft_strequ(line, "ra"))
		rotate(&a, flag == 1 ? 1 : 0);
	else if (ft_strequ(line, "rb"))
		rotate(&b, flag == 1 ? 2 : 0);
	else if (ft_strequ(line, "rra"))
		reverse_rotate(&a, flag == 1 ? 1 : 0);
	else if (ft_strequ(line, "rrb"))
		reverse_rotate(&b, flag == 1 ? 2 : 0);
	else if (ft_strequ(line, "rr"))
		rotate_both(&a, &b, flag == 1 ? 3 : 0);
	else if (ft_strequ(line, "rrr"))
		rrotate_both(&a, &b, flag == 1 ? 3 : 0);
	else
		terminate("\x1b[31mError_unknown_command");
}

void			print_stack(t_stack *a, t_stack *b)
{
	int			i;
	t_st_node	*curr_a;
	t_st_node	*curr_b;

	i = 0;
	curr_a = a->head;
	curr_b = b->head;
	ft_printf("<======A======+======B=====>\n");
	while (i < a->size || i < b->size)
	{
		ft_printf("|");
		ft_printf(curr_a ? "%11d" : "%-11c", curr_a ? curr_a->data : ' ');
		ft_printf("  |   ");
		ft_printf(curr_b ? "%-9d" : "%-9c", curr_b ? curr_b->data : ' ');
		ft_printf("|");
		ft_printf("\n");
		i++;
		curr_a = curr_a ? curr_a->next : curr_a;
		curr_b = curr_b ? curr_b->next : curr_b;
	}
	ft_printf("<=============+============>\n");
}

void			print_stack_color(t_stack *a, t_stack *b, int flag)
{
	int			i;
	t_st_node	*curr_a;
	t_st_node	*curr_b;

	i = 0;
	curr_a = a->head;
	curr_b = b->head;
	ft_printf("\x1b[33m<====\x1b[0mA\x1b[33m====+====\x1b[0mB\x1b[33m====>\n");
	while (i < a->size || i < b->size)
	{
		ft_printf("\x1b[33m|");
		ft_printf(curr_a ? "\x1b[34m%8d\x1b[33m" : "%-8c",
		curr_a ? curr_a->data : ' ');
		ft_printf("\x1b[33m |  ");
		ft_printf(curr_b ? "\x1b[34m%-7d\x1b[33m" : "%-7c",
		curr_b ? curr_b->data : ' ');
		ft_printf("\x1b[33m|");
		ft_printf("\n");
		i++;
		curr_a = curr_a ? curr_a->next : curr_a;
		curr_b = curr_b ? curr_b->next : curr_b;
	}
	ft_printf("\x1b[33m<=========+=========>\n\x1b[35m");
	system("sleep 0.5");
	flag == 1 ? system("clear") : 0;
}

static void		checker(int argc, char **argv, short *check_flags)
{
	t_stack		*b;
	t_stack		*a;
	char		*line;
	int			i;

	b = malloc(sizeof(t_stack));
	init_list(b);
	check_dup(a = parse_num(argc, argv));
	i = 0;
	VERBOSE ? print_stack(a, b) : 0;
	while (get_next_line(0, &line) > 0)
	{
		instruction(a, b, line, VERBOSE || COLOR ? 1 : 0);
		VERBOSE ? print_stack(a, b) : 0;
		COLOR ? print_stack_color(a, b, 1) : 0;
		free(line);
		if (b->size == 0 && check_sort(a))
		{
			VERBOSE || COLOR ? ft_printf("COUNT: %d\n", ++i) : 0;
			COLOR ? print_stack_color(a, b, 0) : 0;
			terminate("\e[32m OK");
		}
		VERBOSE || COLOR ? ft_printf("COUNT: %d\n\n", ++i) : 0;
	}
	!check_sort(a) ? terminate("\x1b[31mKO") : 0;
}

int				main(int argc, char **argv)
{
	short check_flags[2];

	VERBOSE = 0;
	COLOR = 0;
	if (argc >= 2 && (!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "-c")))
	{
		if (ft_strchr(argv[1], 'v'))
			VERBOSE = 1;
		if (ft_strchr(argv[1], 'c'))
			COLOR = 1;
		argv++;
		argc--;
	}
	if (argc >= 2)
		checker(argc, argv, check_flags);
	else
		terminate("usage: ./checker [-v][-c] set of numbers");
	return (0);
}
