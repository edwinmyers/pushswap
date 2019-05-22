/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:12:42 by nparker           #+#    #+#             */
/*   Updated: 2019/05/22 15:36:34 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		parse_arr(t_stack *stack, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_isint(argv[i]) == -1 || ft_ischar(argv[i]) == 1)
			terminate("Error_is_not_integer");
		ft_lstadd_at_tail(&stack, ft_newnode(ft_strtoll(argv[i]), sizeof(int), 0));
		i++;
	}
}

static void		parse_str(t_stack *stack, char *str)
{
	char		**num;
	int		i;

	num = ft_strsplit(str, ' ');
	i = 0;
	while (num[i])
	{
		if (ft_isint(num[i]) == -1 || ft_ischar(num[i]) == 1)
			terminate("Error_is_not_integer");
		ft_lstadd_at_tail(&stack, ft_newnode(ft_strtoll(num[i]), sizeof(int), 0));
		i++;
	}
	ft_free2dmass(num, i);
}

t_stack			*parse_num(int argc, char **argv)
{
	t_stack		*stack;

	if (!(stack = malloc(sizeof(t_stack))))
		exit(-1);
	init_list(stack);
	if (argc == 2 && ft_isnum(argv[1]))
		parse_str(stack, argv[1]);
	else
		parse_arr(stack, argc, argv);
	return (stack);
}
