/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:05:08 by crobot            #+#    #+#             */
/*   Updated: 2021/10/06 13:05:10 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	dup_check(t_stack *stack)
{
	int		i;
	t_elem	*curr_i;
	t_elem	*curr_j;

	i = 0;
	curr_i = stack->head;
	while (i < stack->size)
	{
		curr_j = curr_i->next;
		while (curr_j != curr_i)
		{
			if (curr_i->num == curr_j->num)
				terminate("Error");
			curr_j = curr_j->next;
		}
		i++;
		curr_i = curr_i->next;
	}
}

void	parse_arr(t_stack *stack, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_isint(av[i]))
			terminate("Error");
		add(stack, create_elem(ft_atoi(av[i++])));
	}
}

void	parse_str(t_stack *stack, char *str)
{
	char	**num;
	int		i;

	num = ft_split(str, ' ');
	i = 0;
	while (num[i])
	{
		if (!ft_isint(num[i]))
			terminate("Error");
		add(stack, create_elem(ft_atoi(num[i++])));
	}
	ft_split_free(&num);
}

t_stack	*parse(int ac, char **av)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!(stack))
		terminate("Error");
	stack->head = NULL;
	stack->size = 0;
	stack->row = 0;
	stack->mark_head = NULL;
	if (ac == 2 && !ft_isdigit(ft_atoi(av[1])))
		parse_str(stack, av[1]);
	else
		parse_arr(stack, ac, av);
	if (!stack->size)
		terminate("Error");
	return (stack);
}
