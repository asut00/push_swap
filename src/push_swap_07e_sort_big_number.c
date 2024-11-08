/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_07e_sort_big_number.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_trgt_idx_in_stk_a(int *stack_a, int *size_a, int *stack_b, int x)
{
	int		i;
	long	target;
	int		target_index;

	target = 2147483650;
	i = 0;
	target_index = 0;
	while (i < *size_a)
	{
		if (stack_a[i] > stack_b[x] && stack_a[i] < target)
		{
			target = stack_a[i];
			target_index = i;
		}
		i++;
	}
	if (target == 2147483650)
	{
		target_index = find_min_index(stack_a, *size_a);
		target = stack_a[target_index];
	}
	return (target_index);
}

void	put_value_as_first_in_b(int *stack_b, int *size_b, int target)
{
	int	i;

	i = 0;
	if (stack_b[0] == target)
		return ;
	while (stack_b[i] != target)
		i++;
	if (i + 1 > *size_b / 2)
	{
		while (*size_b - i)
		{
			rrb(stack_b, *size_b);
			i++;
		}
	}
	else
	{
		while (i)
		{
			rb(stack_b, *size_b);
			i--;
		}
	}
}

void	pre_sorting(t_stacks *s)
{
	int	i;
	int	median;
	int	third_quartile;

	i = s->size_a;
	median = calculate_median(s);
	third_quartile = calculate_third_quartile(s);
	while (i > 0)
	{
		if (s->stack_a[0] < median)
			ra(s->stack_a, s->size_a);
		else if (s->stack_a[0] >= median && s->stack_a[0] < third_quartile)
			pb(s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
		else if (s->stack_a[0] >= third_quartile)
		{
			pb(s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
			if (s->size_b > 1)
				rb(s->stack_b, s->size_b);
		}
		i--;
	}
}

int	recursive_pre_sorting(t_stacks *s)
{
	pre_sorting(s);
	if (s->size_a > 3)
		recursive_pre_sorting(s);
	else if (s->size_a < 3)
	{
		while (s->size_a < 3)
			pa(s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
	}
	return (1);
}

int	sort_big_number(t_stacks *s)
{
	int	i;
	int	target;
	int	best_bnum_indx;
	int	stock_size_a;

	stock_size_a = s->size_a;
	recursive_pre_sorting(s);
	s->size_a = 3;
	s->size_b = stock_size_a - 3;
	sort_three_in_a(s->stack_a, s->size_a);
	i = s->size_b;
	while (i > 0)
	{
		best_bnum_indx = find_best_bnum_indx(
				s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
		put_value_as_first_in_b(
			s->stack_b, &(s->size_b), s->stack_b[best_bnum_indx]);
		target = find_target_in_stack_a(
				s->stack_a, &(s->size_a), s->stack_b, 0);
		put_value_as_first_in_a(s->stack_a, &(s->size_a), target);
		pa(s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
		i--;
	}
	rotate_so_that_min_is_first(s->stack_a, &(s->size_a));
	return (1);
}
