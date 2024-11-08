/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_07d_sort_eight.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_eight(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;
	int	target;

	i = 0;
	while (i < 3)
	{
		pb(stack_a, stack_b, size_a, size_b);
		i++;
	}
	reverse_sort_three_in_a(stack_b, *size_b);
	sort_five(stack_a, stack_b, size_a, size_b);
	i = 3;
	while (i > 0)
	{
		target = find_target_in_stack_a(stack_a, size_a, stack_b, 0);
		put_value_as_first_in_a(stack_a, size_a, target);
		pa(stack_a, stack_b, size_a, size_b);
		i--;
	}
	rotate_so_that_min_is_first(stack_a, size_a);
	return (1);
}

int	get_cost_to_move_in_first(int size, int index)
{
	int	move_cost;

	move_cost = 0;
	if (index <= size / 2)
		move_cost = index;
	else
		move_cost = size - index;
	return (move_cost);
}

int	find_best_bnum_indx(int *stk_a, int *stk_b, int *size_a, int *size_b)
{
	int	total_move_cost;
	int	cheapest_total_move_cost;
	int	i;
	int	target_index;
	int	best_bnum_indx;

	cheapest_total_move_cost = 2147483647;
	i = 0;
	best_bnum_indx = 0;
	while (i < *size_b)
	{
		total_move_cost = get_cost_to_move_in_first(*size_b, i);
		target_index = find_trgt_idx_in_stk_a(stk_a, size_a, stk_b, i);
		total_move_cost += get_cost_to_move_in_first(*size_a, target_index);
		if (total_move_cost < cheapest_total_move_cost)
		{
			cheapest_total_move_cost = total_move_cost;
			best_bnum_indx = i;
		}
		i++;
	}
	return (best_bnum_indx);
}
