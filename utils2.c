/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:55:39 by beergin           #+#    #+#             */
/*   Updated: 2025/02/10 10:42:40 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_b(t_stack *a, t_stack *b, int len)
{
	if (len == 2)
	{
		if (b->s_data[0] < b->s_data[1])
			sb(b, 1);
		pa(a, b, 1);
		pa(a, b, 1);
	}
	else if (len == 3)
	{
		while (len || !(a->s_data[0] < a->s_data[1]
				&& a->s_data[1] < a->s_data[2]))
		{
			if (len == 1 && a->s_data[0] > a->s_data[1])
				sa(a, 1);
			else if (len == 1 || (len >= 2 && b->s_data[0] > b->s_data[1])
				|| (len == 3 && b->s_data[0] > b->s_data[2]))
			{
				pa(a, b, 1);
				len--;
			}
			else
				sb(b, 1);
		}
	}
	return (1);
}

int	*set_clone(t_stack *stack)
{
	int	i;
	int	*clone;

	i = 0;
	clone = malloc(sizeof(int) * stack->size);
	while (i < stack->size)
	{
		clone[i] = stack->s_data[i];
		i++;
	}
	return (clone);
}

int	sort_three(t_stack *s)
{
	if (s->s_data[0] > s->s_data[1] && s->s_data[0] < s->s_data[2]
		&& s->s_data[1] < s->s_data[2])
		sa(s, 1);
	if (s->s_data[0] > s->s_data[1] && s->s_data[0] > s->s_data[2]
		&& s->s_data[1] > s->s_data[2])
	{
		sa(s, 1);
		rra(s, s->size, 1);
	}
	if (s->s_data[0] > s->s_data[1] && s->s_data[0] > s->s_data[2]
		&& s->s_data[1] < s->s_data[2])
		ra(s, s->size, 1);
	if (s->s_data[0] < s->s_data[1] && s->s_data[0] < s->s_data[2]
		&& s->s_data[1] > s->s_data[2])
	{
		sa(s, 1);
		ra(s, s->size, 1);
	}
	if (s->s_data[0] < s->s_data[1] && s->s_data[0] > s->s_data[2]
		&& s->s_data[1] > s->s_data[2])
		rra(s, s->size, 1);
	return (1);
}

void	two_arg_procc(t_stack *a, t_stack *b, char **argv)
{
	char	**new_split;
	int		i;
	int		len;

	i = -1;
	new_split = ft_split(argv[1], ' ');
	if (new_split == NULL)
	{
		write(1, "Error\n", 6);
		return ;
	}
	len = 0;
	while (new_split[len])
		len++;
	if (!ft_check(new_split, len, 0))
	{
		write(1, "Error\n", 6);
		return ;
	}
	a->size = len;
	push_swap(a, b, new_split, 0);
	while (new_split[++i])
		free(new_split[i]);
	free(new_split);
	ft_free_struct(a, b);
}
