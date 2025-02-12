/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:24:46 by beergin           #+#    #+#             */
/*   Updated: 2025/02/06 14:32:50 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sort(int *arr, int size)
{
	int	tmp;
	int	swap;
	int	i;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swap = 1;
			}
			i++;
		}
		size--;
	}
	return (arr);
}

void	sort_a(t_stack *a)
{
	int	i;
	int	*sorted;
	int	*clone_array;

	i = 0;
	clone_array = malloc(sizeof(int) * a->size);
	if (!clone_array)
		return ;
	while (i < a->size)
	{
		clone_array[i] = a->s_data[i];
		i++;
	}
	sorted = bubble_sort(clone_array, a->size);
	if (!sorted)
	{
		ft_free(clone_array);
		return ;
	}
	sort_a2(sorted, a);
	ft_free(sorted);
}

void	push_b(t_stack *a, t_stack *b, int point)
{
	int	b_point;
	int	tmp_len;

	tmp_len = a->size;
	while (a->size != tmp_len / 2 + tmp_len % 2)
	{
		if (a->s_data[0] < point)
			pb(a, b, 1);
		else
		{
			b_point = get_sorted_mid(b, a, b->size);
			if ((b->s_data[0] <= b_point) && (b->size > 2))
				rr(a, b, 1);
			else
				ra(a, a->size, 1);
		}
	}
	q_sort_a(a, b, tmp_len / 2 + tmp_len % 2, 0);
	q_sort_b(a, b, tmp_len / 2, 0);
}
