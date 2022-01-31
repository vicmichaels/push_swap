/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:04:45 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 13:04:47 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rx(t_stack *stack, char *name, t_ops_que *que)
{
	if (stack && stack->head)
		stack->head = stack->head->next;
	if (name && que)
		add_op(que, create_op(name));
}

void	rr(t_stack *a, t_stack *b, char *name, t_ops_que *que)
{
	rx(a, NULL, NULL);
	rx(b, NULL, NULL);
	if (name && que)
		add_op(que, create_op(name));
}

void	rrx(t_stack *stack,	char *name,	t_ops_que *que)
{
	if (stack && stack->head)
		stack->head = stack->head->prev;
	if (name && que)
		add_op(que, create_op(name));
}

void	rrr(t_stack *a, t_stack *b,	char *name,	t_ops_que *que)
{
	rrx(a, NULL, NULL);
	rrx(b, NULL, NULL);
	if (name && que)
		add_op(que, create_op(name));
}
