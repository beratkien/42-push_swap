/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:39:55 by beergin           #+#    #+#             */
/*   Updated: 2025/02/02 18:34:24 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_checkk(unsigned long long result, const char *str, int sign,
		int i)
{
	if ((sign == 1 && result == 214748364 && (str[i] - 48) > 7) || (sign == -1
			&& result == 214748364 && (str[i] - 48) > 8) || (sign == 1
			&& ft_strlen(str) > 10) || (sign == -1 && ft_strlen(str) > 11))
		return (0);
	else
		return (1);
}

static int	ft_white_space(int i, const char *str)
{
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	p_atoi(const char *str)
{
	long long	result;
	int			i;
	int			sign;
	int			re;

	i = 0;
	result = 0;
	sign = 1;
	re = 0;
	i += ft_white_space(i, str);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		re = ft_checkk(result, str, sign, i);
		if (re == 0)
			return (write(1, "Error\n", 6), exit(0), 0);
		result = ((result * 10) + (str[i++] - 48));
	}
	return ((int)(result * sign));
}
