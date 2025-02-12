/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:39:55 by beergin           #+#    #+#             */
/*   Updated: 2025/02/10 14:28:46 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (!new_size)
		return (NULL);
	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (new_size > old_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	ft_memmove(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}

static int	small_sets(t_stack *stack, int c)
{
	if (c)
		rb(stack, stack->size, 0);
	else
		ra(stack, stack->size, 0);
	stack->s_data = ft_realloc(stack->s_data, stack->size * sizeof(int),
			(stack->size - 1) * sizeof(int));
	if (!stack)
		return (0);
	stack->size--;
	return (1);
}

void	pa(t_stack *a, t_stack *b, int check)
{
	int	top;
	int	i;
	int	*tmp_arr;

	if (b->size == 0)
		return ;
	top = b->s_data[0];
	tmp_arr = ft_realloc(a->s_data, a->size * sizeof(int), (a->size + 1)
			* sizeof(int));
	if (!tmp_arr)
		return ;
	a->s_data = tmp_arr;
	a->size++;
	i = a->size - 1;
	while (i > 0)
	{
		a->s_data[i] = a->s_data[i - 1];
		i--;
	}
	a->s_data[0] = top;
	if (!small_sets(b, 1))
		return ;
	if (check)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int check)
{
	int	top;
	int	i;
	int	*tmp_arr;

	if (a->size == 0)
		return ;
	top = a->s_data[0];
	tmp_arr = ft_realloc(b->s_data, b->size * sizeof(int), (b->size + 1)
			* sizeof(int));
	if (!tmp_arr)
		return ;
	b->s_data = tmp_arr;
	b->size++;
	i = b->size - 1;
	while (i > 0)
	{
		b->s_data[i] = b->s_data[i - 1];
		i--;
	}
	b->s_data[0] = top;
	if (!small_sets(a, 0))
		return ;
	if (check)
		write(1, "pb\n", 3);
}
