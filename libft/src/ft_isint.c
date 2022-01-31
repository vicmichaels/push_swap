/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 03:57:41 by crobot            #+#    #+#             */
/*   Updated: 2022/01/31 03:57:44 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_space(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

t_bool	ft_isint(const char *str)
{
	unsigned int	r;
	unsigned int	b;
	int				i;
	int				sign;
	int				digits;

	r = 0;
	digits = 0;
	b = (unsigned int)(INT_MAX / 10);
	i = 0;
	while (ft_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && ++digits)
	{
		if (((r > b || (r == b && (str[i] - '0') > 7)) && sign == 1)
			|| ((r > b || (r == b && (str[i] - '0') > 8)) && sign == -1))
			return (false);
		r = r * 10 + (str[i++] - '0');
	}
	return (!str[i] && digits);
}
