/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:14:23 by nparker           #+#    #+#             */
/*   Updated: 2019/06/04 13:46:05 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_sort(t_stack *stack)
{
	t_st_node	*curr_i;
	t_st_node	*curr_j;
	int		i;

	i = 0;
	curr_i = stack->head;
	curr_j = curr_i->next;
	if (stack->size == 1)
		return (1);
	while (i < stack->size)
	{
		if (curr_i->data > curr_j->data && curr_j != NULL)
		{
			break;
		}
		curr_j = curr_j->next;
		curr_i = curr_i->next;
		i++;
		if (curr_j == NULL)
			return (1);
	}
	return (0);
}

int		ft_isint(char *str)
{
	int i;

	i = 0;
	if (ft_strtoll(str) > 2147483647)
		return (-1);
	if (ft_strtoll(str) < -2147483647)
		return (-1);
	return (0);
}

int 		ft_isnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int 		ft_ischar(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void			check_dup(t_stack *stack)
{
	t_st_node		*curr_i;
	t_st_node		*curr_j;
	int			i;

	i = 0;
	curr_i = stack->head;
	while (i < stack->size)
	{
		curr_j = curr_i->next;
		while (curr_j != NULL)
		{
			if (curr_i->data == curr_j->data)
				terminate("Error_duplicate");
			curr_j = curr_j->next;
		}
		i++;
		curr_i = curr_i->next;
	}
}
