/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:16:06 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 13:16:08 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	align_a(t_stack *a_stack, t_ops_que *que)
{
	t_elem		*curr;
	int			ra_size;
	int			rra_size;

	if (a_stack && a_stack->head)
	{
		ra_size = 0;
		curr = a_stack->head;
		while (curr->indx != 0)
		{
			ra_size++;
			curr = curr->next;
		}
		rra_size = 0;
		curr = a_stack->head;
		while (curr->indx != 0)
		{
			rra_size++;
			curr = curr->prev;
		}
		while (a_stack->head->indx != 0 && (ra_size < rra_size))
			rx(a_stack, "ra", que);
		while (a_stack->head->indx != 0 && (ra_size >= rra_size))
			rrx(a_stack, "rra", que);
	}
}

t_ops_que	*sort(t_stack *a, int (*mark)(t_stack *, t_elem *))
{
	t_ops_que		*que;
	t_stack			*b_stack;

	que = init_ops_que();
	b_stack = init_stack();
	sort_a(a, b_stack, mark, que);
	sort_b(a, b_stack, que);
	align_a(a, que);
	free_stack(b_stack);
	return (que);
}
