/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:48:31 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 10:48:32 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	mark1(t_stack *stack, t_elem *mark_head)
{
	int			indx;
	int			row;
	t_elem		*curr;

	row = 0;
	if (stack && mark_head)
	{
		indx = mark_head->indx;
		mark_head->move = true;
		curr = mark_head->next;
		while (curr != mark_head)
		{
			if (curr->indx == indx + 1)
			{
				row++;
				indx++;
				curr->move = true;
			}
			else
				curr->move = false;
			curr = curr->next;
		}
	}
	return (row);
}

int	mark2(t_stack *stack, t_elem *mark_head)
{
	int			indx;
	int			row;
	t_elem		*curr;

	row = 0;
	if (stack && mark_head)
	{
		indx = mark_head->indx;
		mark_head->move = true;
		curr = mark_head->next;
		while (curr != mark_head)
		{
			if (curr->indx > indx)
			{
				row++;
				indx = curr->indx;
				curr->move = true;
			}
			else
				curr->move = false;
			curr = curr->next;
		}
	}
	return (row);
}

void	best_mark(t_stack *stack, int (*mark)(t_stack *, t_elem *))
{
	int			i;
	int			curr_row;
	t_elem		*curr;

	if (stack)
	{
		i = 0;
		curr = stack->head;
		while (i < stack->size)
		{
			curr_row = mark(stack, curr);
			if (curr_row > stack->row)
			{
				stack->mark_head = curr;
				stack->row = curr_row;
			}
			else if (curr_row == stack->row && (!stack->mark_head
					|| curr->num < stack->mark_head->num))
				stack->mark_head = curr;
			i++;
			curr = curr->next;
		}
	}
	mark(stack, stack->mark_head);
}

static t_elem	*get_next_min(t_stack *stack)
{
	int				i;
	t_bool			has_min;
	t_elem			*min;
	t_elem			*curr;

	min = NULL;
	if (stack)
	{
		i = 0;
		has_min = false;
		curr = stack->head;
		while (i < stack->size)
		{
			if ((curr->indx == -1)
				&& (!has_min || curr->num < min->num))
			{
				has_min = true;
				min = curr;
			}
			i++;
			curr = curr->next;
		}
	}
	return (min);
}

void	indx(t_stack *stack)
{
	int		indx;
	t_elem	*curr;

	indx = 0;
	curr = get_next_min(stack);
	while (curr)
	{
		curr->indx = indx++;
		curr = get_next_min(stack);
	}
}
