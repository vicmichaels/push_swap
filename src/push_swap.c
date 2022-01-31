/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:52:21 by crobot            #+#    #+#             */
/*   Updated: 2021/10/05 19:52:23 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack				*stack1;
	t_stack				*stack2;
	t_ops_que			*que1;
	t_ops_que			*que2;

	if (ac >= 2)
	{
		dup_check((stack1 = parse(ac, av)));
		indx(stack1);
		best_mark(stack1, &mark1);
		que1 = sort(stack1, &mark1);
		free_stack(stack1);
		indx(stack2 = parse(ac, av));
		best_mark(stack2, &mark2);
		que2 = sort(stack2, &mark2);
		free_stack(stack2);
		print_que(que1, que2);
		free_op_que(que1);
		free_op_que(que2);
	}
	return (0);
}
