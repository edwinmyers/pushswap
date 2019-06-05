/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:12:42 by nparker           #+#    #+#             */
/*   Updated: 2019/06/05 12:43:21 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		parse_arr(t_stack *stack, int argc, char **argv)
{
	int			i;
	char		**str;
	int			j;
	int			len;

	len = 0;
	j = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_isint(argv[i]) == -1 || ft_ischar(argv[i]) == 1)
			terminate("Error_is_not_integer");
		if ((str = ft_strsplit(argv[i], ' ')))
		{
			len = ft_word_count(argv[i], ' ');
			while (j < len)
				ft_lstadd_at_tail(&stack,
				ft_newnode(ft_strtoll(str[j++]), sizeof(int), 0));
			ft_free2dmass(str, j);
		}
		i++;
	}
}

static void		parse_str(t_stack *stack, char *str)
{
	char		**num;
	int			i;

	num = ft_strsplit(str, ' ');
	i = 0;
	while (num[i])
	{
		if (ft_isint(num[i]) == -1 || ft_ischar(num[i]) == 1)
			terminate("Error_is_not_integer");
		ft_lstadd_at_tail(&stack,
		ft_newnode(ft_strtoll(num[i]), sizeof(int), 0));
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
