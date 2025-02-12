/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:39:55 by beergin           #+#    #+#             */
/*   Updated: 2025/02/10 10:43:11 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(int *stack)
{
	if (!stack)
		return ;
	free(stack);
}

void	ft_free_struct(t_stack *a, t_stack *b)
{
	if (a)
	{
		if (a->s_data)
		{
			free(a->s_data);
			a->s_data = NULL;
		}
		free(a);
	}
	if (b)
	{
		if (b->s_data)
		{
			free(b->s_data);
			b->s_data = NULL;
		}
		free(b);
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
