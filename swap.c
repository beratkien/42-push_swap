/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:38:40 by beergin           #+#    #+#             */
/*   Updated: 2025/01/25 00:28:21 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int check)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->s_data[0];
	a->s_data[0] = a->s_data[1];
	a->s_data[1] = tmp;
	if (check == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int check)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->s_data[0];
	b->s_data[0] = b->s_data[1];
	b->s_data[1] = tmp;
	if (check == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int check)
{
	sa(a, 0);
	sb(b, 0);
	if (check)
		write(1, "ss\n", 3);
}
