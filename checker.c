/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:49:19 by nparker           #+#    #+#             */
/*   Updated: 2019/06/03 16:51:50 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	instruction(t_stack *a, t_stack *b, char *line)
{

	if (ft_strequ(line, "pb"))
		push(&b, &a);
	else if (ft_strequ(line, "pa"))
		push(&a, &b);
	else if (ft_strequ(line, "sa"))
		swap_st(&a);
	else if (ft_strequ(line, "sb"))
		swap_st(&b);
	else if (ft_strequ(line, "ss"))
		swap_both(&a, &b);
	else if (ft_strequ(line, "ra"))
		rotate(&a);
	else if (ft_strequ(line, "rb"))
		rotate(&b);
	else if (ft_strequ(line, "rra"))
		reverse_rotate(&a);
	else if (ft_strequ(line, "rrb"))
		reverse_rotate(&b);
	else if (ft_strequ(line, "rr"))
		rotate_both(&a, &b);
	else if (ft_strequ(line, "rrr"))
		rrotate_both(&a, &b);
	else
		terminate("Error_unknow");
}

void	print_stack(t_stack *a, t_stack *b)
{
	int i;
	t_st_node *curr_a;
	t_st_node *curr_b;

	i = 0;
	curr_a = a->head;
	curr_b = b->head;
	ft_printf("<======A======+======B=====>");
	while (i < a->size || i < b->size)
	{
		ft_printf("|    ");
		ft_printf("%d", curr_a->data);
		ft_printf("|");
		ft_printf("%d", curr_b->data);
		ft_printf("    |");		
		ft_printf("\n");
		i++;
		curr_a = curr_a->next;
		curr_b = curr_b->next;
	}
	ft_printf("<=============+============>\n");
}

static void		checker(int argc, char **argv, short verbose)
{
	t_stack		*b;
	t_stack		*a;
	char		*line;
	int			size;

	b = malloc(sizeof(t_stack));
	init_list(b);
	check_dup(a = parse_num(argc, argv));
	if (verbose)
		print_stack(a, b);
	while ((size = get_next_line(0, &line)) > 0)
	{
		instruction(a, b, line);
		if (verbose)
			print_stack(a, b);
		free(line);
	}
	if (size == -1)
		terminate("Error_no_instruction");
	if (b->size == 0 && check_sort(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}


int         main(int argc, char **argv)
{
	short   verbose;

	verbose = 0;
	while (argc >= 2 && ft_strcmp(argv[1], "-v"))
	{
		if (ft_strcmp(argv[1], "-v"))
			verbose = 1;
		argc--;
		argv++;
	}
	if (argc >= 2)
		checker(argc, argv, verbose);
	else
		terminate("usage: ./push_swap ...");
	return (0);
}