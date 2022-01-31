/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:34:05 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 21:46:51 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_bool	needs_pb(t_stack *a_stack)
{
	int			i;
	t_elem		*curr;

	if (a_stack)
	{
		i = 0;
		curr = a_stack->head;
		while (i < a_stack->size)
		{
			if (!curr->move)
				return (true);
			i++;
			curr = curr->next;
		}
	}
	return (false);
}

static t_bool	needs_sa(t_stack *a_stack, int (*mark_stack)(t_stack *,
		t_elem *))
{
	int	curr_row;

	if (a_stack && a_stack->size >= 2)
	{
		sx(a_stack, NULL, NULL);
		curr_row = mark_stack(a_stack, a_stack->mark_head);
		sx(a_stack, NULL, NULL);
		mark_stack(a_stack, a_stack->mark_head);
		if (curr_row > a_stack->row)
			return (true);
	}
	return (false);
}

void	sort_a(t_stack *a, t_stack *b, int (*markup)(t_stack *, t_elem *),
	t_ops_que *que)
{
	while (needs_pb(a))
	{
		if (needs_sa(a, markup))
		{
			sx(a, "sa", que);
			a->row = markup(a, a->mark_head);
		}
		else if (a->head->move == false)
			px(b, a, "pb", que);
		else
			rx(a, "ra", que);
	}
}
