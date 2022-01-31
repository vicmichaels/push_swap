/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:05:53 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 13:05:55 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_op_que(t_ops_que *que)
{
	t_op	*curr;
	t_op	*rm;

	curr = que->head;
	while (curr)
	{
		rm = curr;
		curr = curr->next;
		free(rm->name);
		free(rm);
	}
	free(que);
}

void	free_stack(t_stack *stack)
{
	int			i;
	t_elem		*curr;
	t_elem		*rm;

	i = 0;
	curr = stack->head;
	while (i < stack->size)
	{
		rm = curr;
		curr = curr->next;
		free(rm);
		i++;
	}
	free(stack);
}

void	terminate(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	ft_split_free(char ***split)
{
	char	**current;

	if (split && *split)
	{
		current = ((*split));
		while ((*current))
			free((*(current++)));
		free((*split));
		(*split) = NULL;
	}
}

int	ft_max(int a, int b)
{
	if ((a) > (b))
		return (a);
	else
		return (b);
}
