/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:20:03 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 21:48:31 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_elem	*find_a_elem(t_stack *a_stack, int indx)
{
	t_elem	*curr;

	curr = a_stack->mark_head;
	if (indx < curr->indx)
	{
		while (indx < curr->prev->indx
			&& curr->indx > curr->prev->indx)
			curr = curr->prev;
	}
	else
	{
		while (indx > curr->indx
			&& curr->indx < curr->next->indx)
			curr = curr->next;
		if (indx > curr->indx && curr->indx > curr->next->indx)
			curr = curr->next;
	}
	return (curr);
}

static void	plan_way(t_stack *stack, int indx, int *rx_size, int *rrx_size)
{
	t_elem	*curr;

	if (stack && stack->head)
	{
		curr = stack->head;
		while (curr->indx != indx)
		{
			(*rx_size)++;
			curr = curr->next;
		}
		curr = stack->head;
		while (curr->indx != indx)
		{
			(*rrx_size)++;
			curr = curr->prev;
		}
	}
}

static void	set_way(int size, t_step_data new_step_data,
		t_step_data *step_data)
{
	if (!step_data->is_set || size < step_data->size)
	{
		step_data->a_elem = new_step_data.a_elem;
		step_data->b_elem = new_step_data.b_elem;
		step_data->a_way = new_step_data.a_way;
		step_data->b_way = new_step_data.b_way;
		step_data->size = size;
		step_data->is_set = true;
	}
}

static void	finding_way(t_stack *a, t_stack *b, t_elem *b_elem,
		t_step_data *step_data)
{
	t_step_data		new_step_data;
	int				ra_size;
	int				rra_size;
	int				rb_size;
	int				rrb_size;

	ra_size = 0;
	rra_size = 0;
	rb_size = 0;
	rrb_size = 0;
	new_step_data.a_elem = find_a_elem(a, b_elem->indx);
	new_step_data.b_elem = b_elem;
	plan_way(a, new_step_data.a_elem->indx, &ra_size, &rra_size);
	plan_way(b, b_elem->indx, &rb_size, &rrb_size);
	new_step_data.a_way = R;
	new_step_data.b_way = R;
	set_way(ft_max(ra_size, rb_size), new_step_data, step_data);
	new_step_data.a_way = RR;
	set_way(rra_size + rb_size, new_step_data, step_data);
	new_step_data.b_way = RR;
	set_way(ft_max(rra_size, rrb_size), new_step_data, step_data);
	new_step_data.a_way = R;
	set_way(ra_size + rrb_size, new_step_data, step_data);
}

void	find_way(t_stack *a, t_stack *b, t_step_data *step_data)
{
	int			i;
	t_elem		*curr;

	if (b)
	{
		i = 0;
		curr = b->head;
		while (i < b->size)
		{
			finding_way(a, b, curr, step_data);
			i++;
			curr = curr->next;
		}
	}
}
