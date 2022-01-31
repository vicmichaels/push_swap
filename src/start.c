/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:27:30 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 19:27:31 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!(stack))
		terminate("Error");
	stack->head = NULL;
	stack->size = 0;
	stack->row = 0;
	stack->mark_head = NULL;
	return (stack);
}

t_ops_que	*init_ops_que(void)
{
	t_ops_que	*que;

	que = (t_ops_que *)malloc(sizeof(t_ops_que));
	if (!(que))
		terminate("Error");
	que->size = 0;
	que->head = NULL;
	return (que);
}
