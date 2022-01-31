/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:04:32 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 13:04:34 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_elem *first,	t_elem *second, t_stack *stack)
{
	t_elem	*prev;
	t_elem	*next;

	prev = first->prev;
	next = second->next;
	prev->next = second;
	second->prev = prev;
	first->next = next;
	next->prev = first;
	second->next = first;
	first->prev = second;
	stack->head = second;
}

void	sx(t_stack *stack, char *name, t_ops_que *que)
{
	if (stack && stack->head && stack->size >= 2)
		swap(stack->head, stack->head->next, stack);
	if (name && que)
		add_op(que, create_op(name));
}

void	ss(t_stack *a, t_stack *b, char *name, t_ops_que *que)
{
	sx(a, NULL, NULL);
	sx(b, NULL, NULL);
	if (name && que)
		add_op(que, create_op(name));
}

void	px(t_stack *out, t_stack *in, char *op, t_ops_que *que)
{
	push(out, pop(in));
	if (op && que)
		add_op(que, create_op(op));
}
