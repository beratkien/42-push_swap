/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:29 by beergin           #+#    #+#             */
/*   Updated: 2025/02/12 16:58:25 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_repeat(char **argv, int len, int c)
{
	int	num1;
	int	num2;
	int	i;
	int	j;

	i = c;
	len += c;
	while (i < len)
	{
		num1 = p_atoi(argv[i]);
		j = i + 1;
		while (j < len)
		{
			num2 = p_atoi(argv[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	set_arrays(t_stack *a, int *clone, char **arg, int c)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (c)
		{
			a->s_data[i] = p_atoi(arg[i + 1]);
			clone[i] = p_atoi(arg[i + 1]);
		}
		else
		{
			a->s_data[i] = p_atoi(arg[i]);
			clone[i] = p_atoi(arg[i]);
		}
		i++;
	}
}

int	get_sorted_mid(t_stack *s1, t_stack *s2, int len)
{
	int	*clone;
	int	i;
	int	*sorted;
	int	value;

	if (len <= 0)
		return (0);
	i = 0;
	clone = malloc(sizeof(int) * len);
	if (!clone)
		return (ft_free_struct(s1, s2), exit(0), 1);
	while (i < len)
	{
		clone[i] = s1->s_data[i];
		i++;
	}
	sorted = bubble_sort(clone, len);
	if (!sorted)
	{
		free(clone);
		return (ft_free_struct(s1, s2), exit(0), 0);
	}
	value = sorted[len / 2];
	ft_free(clone);
	return (value);
}

int	simple_a(t_stack *a, t_stack *b)
{
	if (a->s_data[0] > a->s_data[1])
	{
		if (b->s_data[0] < b->s_data[1])
			ss(a, b, 1);
		else
			sa(a, 1);
	}
	return (1);
}

int	simple_a2(t_stack *a, t_stack *b, int len)
{
	while (len != 3 || !(a->s_data[0] < a->s_data[1]
			&& a->s_data[1] < a->s_data[2]))
	{
		if (len == 3 && a->s_data[0] > a->s_data[1] && a->s_data[2])
		{
			if ((a->s_data[0] > a->s_data[1]) && (b->s_data[0] < b->s_data[1]))
				ss(a, b, 1);
			else
				sa(a, 1);
		}
		else if (len == 3 && !(a->s_data[2] > a->s_data[0]
				&& a->s_data[2] > a->s_data[1]))
		{
			pb(a, b, 1);
			len--;
		}
		else if (a->s_data[0] > a->s_data[1])
			sa(a, 1);
		else if (len++)
			pa(a, b, 1);
	}
	return (1);
}
