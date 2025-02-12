/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:29 by beergin           #+#    #+#             */
/*   Updated: 2025/02/07 19:35:00 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*s_data;
	int	size;
}		t_stack;

void	push_swap(t_stack *a, t_stack *b, char **argv, int c);
int		ft_is_number(char *str);
int		ft_check(char **argv, int argc, int c);
void	ft_set_a(t_stack *a, char **arg, int c);
void	pa(t_stack *a, t_stack *b, int check);
void	pb(t_stack *a, t_stack *b, int check);
void	sa(t_stack *a, int check);
void	sb(t_stack *b, int check);
void	ss(t_stack *a, t_stack *b, int check);
void	ra(t_stack *a, int arg_len, int check);
void	rb(t_stack *b, int arg_len, int check);
void	rr(t_stack *a, t_stack *b, int check);
void	rra(t_stack *a, int arg_len, int check);
void	rrb(t_stack *b, int arg_len, int check);
void	rrr(t_stack *a, t_stack *b, int check);
void	set_arrays(t_stack *a, int *clone, char **arg, int c);
void	push_b(t_stack *a, t_stack *b, int point);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	sort_a(t_stack *a);
int		*bubble_sort(int *arr, int size);
int		compare_arrays(int *arr1, int *arr2, size_t size);
int		is_repeat(char **argv, int len, int c);
void	sort_a2(int *sorted, t_stack *a);
void	ft_free(int *stack);
void	ft_free_struct(t_stack *a, t_stack *b);
int		p_atoi(const char *str);
int		get_sorted_mid(t_stack *s1, t_stack *s2, int len);
int		simple_a(t_stack *a, t_stack *b);
int		simple_a2(t_stack *a, t_stack *b, int len);
int		simple_b(t_stack *a, t_stack *b, int len);
int		q_sort_a(t_stack *a, t_stack *b, int len, int max);
int		q_sort_b(t_stack *a, t_stack *b, int len, int max);
int		ft_sorted_control(int *stack_a, int size, int flag);
int		*set_clone(t_stack *stack);
int		sort_three(t_stack *s);
void	two_arg_procc(t_stack *a, t_stack *b, char **argv);
void	free_split(char **split);
#endif