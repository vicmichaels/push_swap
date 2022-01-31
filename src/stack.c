/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:31:22 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 16:31:24 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_elem	*create_elem(int num)
{
	t_elem	*new;

	new = (t_elem *)malloc(sizeof(t_elem));
	if (!new)
		terminate("Error");
	new->num = num;
	new->indx = -1;
	new->move = false;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add(t_stack *stack, t_elem *elem)
{
	t_elem	*last;

	if (stack && elem)
	{
		if (stack->head)
		{
			last = stack->head->prev;
			elem->prev = last;
			last->next = elem;
			elem->next = stack->head;
			stack->head->prev = elem;
		}
		else
		{
			stack->head = elem;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		stack->size++;
	}
}

void	push(t_stack *stack, t_elem *elem)
{
	t_elem	*last;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			last = stack->head->prev;
			elem->prev = last;
			last->next = elem;
			elem->next = stack->head;
			stack->head->prev = elem;
			stack->head = elem;
		}
		stack->size++;
	}
}

t_elem	*pop(t_stack *stack)
{
	t_elem	*elem;

	elem = NULL;
	if (stack && stack->size)
	{
		if (stack->size == 1)
		{
			elem = stack->head;
			stack->head = NULL;
			elem->prev = NULL;
			elem->next = NULL;
		}
		else
		{
			elem = stack->head;
			stack->head = stack->head->next;
			elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
			elem->prev = NULL;
			elem->next = NULL;
		}
		stack->size--;
	}
	return (elem);
}
