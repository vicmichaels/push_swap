/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:37:44 by crobot            #+#    #+#             */
/*   Updated: 2022/01/30 23:37:46 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	if_sorted(t_stack *stack)
{
	int			i;
	int			n;
	t_elem		*tmp;

	i = 1;
	tmp = stack->head->next;
	n = stack->head->num;
	while (i < stack->size)
	{
		if (tmp->num < n)
			return (0);
		n = tmp->num;
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	run_cmd(t_stack *a, t_stack *b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		sx(a, "sa", NULL);
	else if (ft_strcmp(op, "sb") == 0)
		sx(b, "sb", NULL);
	else if (ft_strcmp(op, "ss") == 0)
		ss(a, b, "ss", NULL);
	else if (ft_strcmp(op, "pa") == 0)
		px(a, b, "pa", NULL);
	else if (ft_strcmp(op, "pb") == 0)
		px(b, a, "pb", NULL);
	else if (ft_strcmp(op, "ra") == 0)
		rx(a, "ra", NULL);
	else if (ft_strcmp(op, "rb") == 0)
		rx(b, "rb", NULL);
	else if (ft_strcmp(op, "rr") == 0)
		rr(a, b, "rr", NULL);
	else if (ft_strcmp(op, "rra") == 0)
		rrx(a, "rra", NULL);
	else if (ft_strcmp(op, "rrb") == 0)
		rrx(b, "rrb", NULL);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(a, b, "rrr", NULL);
	else
		terminate("Error");
}

static int	ft_get_next_line(char **line)
{
	char	r;
	char	c;
	int		i;

	i = 0;
	*line = malloc(100000);
	r = read(0, &c, 1);
	while (r > 0 && c != '\n')
	{
		(*line)[i++] = c;
		r = read(0, &c, 1);
	}
	(*line)[i] = '\0';
	if (r > 0)
		return (1);
	return (r);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	if (ac >= 2)
	{
		b = init_stack();
		dup_check(a = parse(ac, av));
		while (ft_get_next_line(&str))
		{
			run_cmd(a, b, str);
			free(str);
		}
		if (b->head == NULL && if_sorted(a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_stack(a);
		free_stack(b);
		return (0);
	}
	return (1);
}
