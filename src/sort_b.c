/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:40:24 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 21:49:15 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_step_data	*init_step_data(void)
{
	t_step_data	*step_data;

	step_data = (t_step_data *)malloc(sizeof(t_step_data));
	if (!step_data)
		terminate("Error");
	step_data->a_elem = NULL;
	step_data->b_elem = NULL;
	step_data->a_way = R;
	step_data->b_way = R;
	step_data->size = 0;
	step_data->is_set = false;
	return (step_data);
}

static void	move_b(t_stack *a, t_stack *b, t_step_data *step_data,
		t_ops_que *que)
{
	while (step_data->a_elem != a->head || step_data->b_elem != b->head)
	{
		if (step_data->a_way == step_data->b_way
			&& step_data->a_elem != a->head && step_data->b_elem != b->head)
		{
			if (step_data->a_way == R)
				rr(a, b, "rr", que);
			else
				rrr(a, b, "rrr", que);
		}
		else if (step_data->a_elem != a->head)
		{
			if (step_data->a_way == R)
				rx(a, "ra", que);
			else
				rrx(a, "rra", que);
		}
		else if (step_data->b_elem != b->head)
		{
			if (step_data->b_way == R)
				rx(b, "rb", que);
			else
				rrx(b, "rrb", que);
		}
	}
}

void	sort_b(t_stack *a, t_stack *b, t_ops_que *que)
{
	t_step_data	*step_data;

	step_data = init_step_data();
	while (b->size)
	{
		step_data->is_set = false;
		find_way(a, b, step_data);
		move_b(a, b, step_data, que);
		px(a, b, "pa", que);
	}
	free(step_data);
}
