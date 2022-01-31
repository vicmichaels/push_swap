/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_que.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:26:46 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 19:26:48 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_op	*create_op(char *name)
{
	t_op	*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (!(op))
		terminate("Error");
	op->name = ft_strdup(name);
	if (!(op->name))
		terminate("Error");
	op->next = NULL;
	return (op);
}

void	add_op(t_ops_que *que, t_op *op)
{
	t_op	*last;

	if (que && op)
	{
		if (!que->head)
			que->head = op;
		else
		{
			last = que->head;
			while (last->next)
				last = last->next;
			last->next = op;
		}
		que->size++;
	}
}

void	print_que(t_ops_que *que1, t_ops_que *que2)
{
	if (que1->size < que2->size)
		print_ops(que1);
	else
		print_ops(que2);
}

void	print_ops(t_ops_que *que)
{
	while (que->head)
	{
		ft_putendl_fd(que->head->name, 1);
		que->head = que->head->next;
	}
}
