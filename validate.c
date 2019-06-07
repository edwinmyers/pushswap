/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:14:23 by nparker           #+#    #+#             */
/*   Updated: 2019/06/06 16:47:30 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_sort(t_stack *stack)
{
	t_st_node	*curr_i;
	t_st_node	*curr_j;
	int			i;

	i = 0;
	curr_i = stack->head;
	curr_j = curr_i->next;
	if (stack->size == 1)
		return (1);
	while (i < stack->size)
	{
		if (curr_j != NULL && curr_i->data > curr_j->data)
		{
			break ;
		}
		curr_j = curr_j ? curr_j->next : 0;
		curr_i = curr_i->next;
		i++;
		if (curr_j == NULL)
			return (1);
	}
	return (0);
}

int				ft_isint(char *str)
{
	int		i;

	i = 0;
	if (ft_strtoll(str) > 2147483647)
		return (-1);
	if (ft_strtoll(str) < -2147483648)
		return (-1);
	return (0);
}

int				ft_isnum(char *str)
{
	int			i;
	int			len;
	int			num;

	len = ft_strlen(str);
	num = ft_strtoll(str);
	if (!ft_isdigit(str[0]) && len == 1)
		return (0);
	i = ft_count_digits(num) + (num < 0 || (str[0] == '+' && ft_isdigit(str[1])) ? 1 : 0);
	if (i != len)
		return (0);
	return (1);
}

void			check_dup(t_stack *stack)
{
	t_st_node		*curr_i;
	t_st_node		*curr_j;
	int				i;

	i = 0;
	curr_i = stack->head;
	while (i < stack->size)
	{
		curr_j = curr_i->next;
		while (curr_j != NULL)
		{
			if (curr_i->data == curr_j->data)
				terminate("Error", 2);
			curr_j = curr_j->next;
		}
		i++;
		curr_i = curr_i->next;
	}
}
