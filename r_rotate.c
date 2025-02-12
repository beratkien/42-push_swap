/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:39:49 by beergin           #+#    #+#             */
/*   Updated: 2025/01/25 00:29:06 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int arg_len, int check)
{
	int	i;
	int	bott;

	i = arg_len - 1;
	bott = a->s_data[arg_len - 1];
	while (i > 0)
	{
		a->s_data[i] = a->s_data[i - 1];
		i--;
	}
	a->s_data[i] = bott;
	if (check)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int arg_len, int check)
{
	int	i;
	int	bott;

	i = arg_len - 1;
	bott = b->s_data[arg_len - 1];
	while (i > 0)
	{
		b->s_data[i] = b->s_data[i - 1];
		i--;
	}
	b->s_data[i] = bott;
	if (check)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, int check)
{
	rra(a, a->size, 0);
	rrb(b, b->size, 0);
	if (check)
		write(1, "rrr\n", 4);
}
