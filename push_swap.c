/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:29 by beergin           #+#    #+#             */
/*   Updated: 2025/02/07 22:21:25 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check(char **argv, int argc, int c)
{
	int	i;

	if (c)
		i = 1;
	else
		i = 0;
	while (argv[i])
	{
		if (!ft_is_number(argv[i]))
			return (0);
		i++;
	}
	if (is_repeat(argv, argc - c, c))
		return (0);
	return (1);
}

void	ft_set_a(t_stack *a, char **arg, int c)
{
	int	*clone;
	int	*sorted;

	clone = malloc(sizeof(int) * a->size);
	if (!clone)
		return ;
	set_arrays(a, clone, arg, c);
	sorted = bubble_sort(clone, a->size);
	if (!sorted)
	{
		ft_free(clone);
		return ;
	}
	if (compare_arrays(sorted, a->s_data, a->size) == 1)
	{
		ft_free(sorted);
		exit(0);
	}
	ft_free(sorted);
}

void	push_swap(t_stack *a, t_stack *b, char **argv, int c)
{
	int	point;

	a->s_data = malloc(sizeof(int) * (a->size));
	if (!a->s_data)
		return ;
	b->size = 0;
	b->s_data = malloc(sizeof(int) * (b->size));
	if (!b->s_data)
	{
		ft_free(a->s_data);
		return ;
	}
	ft_set_a(a, argv, c);
	point = get_sorted_mid(a, b, a->size);
	if (a->size > 3)
		push_b(a, b, point);
	else
		sort_a(a);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (1);
	if (!ft_check(argv, argc, 1) && argc != 2)
		return (write(1, "Error\n", 6), 1);
	a = malloc(sizeof(t_stack));
	if (!a)
		return (0);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (free(a), 0);
	a->size = argc - 1;
	if (argc == 2)
	{
		two_arg_procc(a, b, argv);
		return (2);
	}
	push_swap(a, b, argv, 1);
	ft_free_struct(a, b);
	return (0);
}
