/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:23:47 by beergin           #+#    #+#             */
/*   Updated: 2025/02/10 10:41:49 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_control(int *stack_a, int size, int flag)
{
	int	i;

	i = 0;
	while ((flag == 0) && (++i < size))
	{
		if (stack_a[i - 1] > stack_a[i])
			return (0);
	}
	while ((flag == 1) && (++i < size))
	{
		if (stack_a[i - 1] < stack_a[i])
			return (0);
	}
	return (1);
}

int	compare_arrays(int *arr1, int *arr2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (arr1[i] != arr2[i])
			return (0);
		i++;
	}
	return (1);
}

void	sort_a2(int *sorted, t_stack *a)
{
	while (compare_arrays(sorted, a->s_data, a->size) != 1)
	{
		if (a->size > 2 && a->s_data[0] > a->s_data[1]
			&& a->s_data[0] > a->s_data[2])
			ra(a, a->size, 1);
		if (a->s_data[0] > a->s_data[1])
			sa(a, 1);
		if (a->size > 2 && a->s_data[1] > a->s_data[2])
			rra(a, a->size, 1);
	}
}

int	q_sort_a(t_stack *a, t_stack *b, int len, int max)
{
	int	point;
	int	tmp_len;

	if (ft_sorted_control(a->s_data, len, 0) == 1)
		return (1);
	if (len == 2)
		return (simple_a(a, b));
	if (len == 3 && a->size == 3)
		return (sort_three(a));
	if (len == 3)
		return (simple_a2(a, b, len));
	point = get_sorted_mid(a, b, len);
	tmp_len = len;
	while (len != tmp_len / 2 + tmp_len % 2)
	{
		if (a->s_data[0] < point && (len--))
			pb(a, b, 1);
		else if (++max)
			ra(a, a->size, 1);
	}
	while (tmp_len / 2 + tmp_len % 2 != a->size && max--)
		rra(a, a->size, 1);
	return (q_sort_a(a, b, tmp_len / 2 + tmp_len % 2, 0), q_sort_b(a, b, tmp_len
			/ 2, 0));
}

int	q_sort_b(t_stack *a, t_stack *b, int len, int max)
{
	int	point;
	int	tmp_len;

	if (!max && ft_sorted_control(b->s_data, len, 1) == 1)
		while (len--)
			pa(a, b, 1);
	if (len <= 3)
		return (simple_b(a, b, len));
	point = get_sorted_mid(b, a, len);
	tmp_len = len;
	while (len != tmp_len / 2)
	{
		if (b->s_data[0] >= point && (len--))
			pa(a, b, 1);
		else if (++max)
			rb(b, b->size, 1);
	}
	while (tmp_len / 2 != b->size && max--)
		rrb(b, b->size, 1);
	return (q_sort_a(a, b, tmp_len / 2 + tmp_len % 2, 0), q_sort_b(a, b, tmp_len
			/ 2, 0));
}
