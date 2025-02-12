/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:39:52 by beergin           #+#    #+#             */
/*   Updated: 2025/01/25 00:28:46 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int arg_len, int check)
{
	int	i;
	int	top;

	i = 0;
	top = a->s_data[0];
	while (i < arg_len - 1)
	{
		a->s_data[i] = a->s_data[i + 1];
		i++;
	}
	a->s_data[i] = top;
	if (check)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int arg_len, int check)
{
	int	i;
	int	top;

	i = 0;
	top = b->s_data[0];
	while (i < arg_len - 1)
	{
		b->s_data[i] = b->s_data[i + 1];
		i++;
	}
	b->s_data[i] = top;
	if (check)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, int check)
{
	ra(a, a->size, 0);
	rb(b, b->size, 0);
	if (check)
		write(1, "rr\n", 3);
}
