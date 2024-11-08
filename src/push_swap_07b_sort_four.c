/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_07b_sort_four.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_four(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;
	int	target;

	i = *size_a;
	while (i > 3)
	{
		pb(stack_a, stack_b, size_a, size_b);
		i--;
	}
	sort_three_in_a(stack_a, *size_a);
	target = find_target_in_stack_a(stack_a, size_a, stack_b, 0);
	put_value_as_first_in_a(stack_a, size_a, target);
	pa(stack_a, stack_b, size_a, size_b);
	rotate_so_that_min_is_first(stack_a, size_a);
	return (1);
}

long	find_target_in_stack_a(int *stack_a, int *size_a, int *stack_b, int x)
{
	int		i;
	long	target;

	target = 2147483650;
	i = 0;
	while (i < *size_a)
	{
		if (stack_a[i] > stack_b[x] && stack_a[i] < target)
			target = stack_a[i];
		i++;
	}
	if (target == 2147483650)
	{
		target = stack_a[find_min_index(stack_a, *size_a)];
	}
	return (target);
}

int	find_min_index(int *stack, int size)
{
	int	min;
	int	min_index;
	int	i;

	min = 2147483647;
	i = -1;
	while (i < size - 1)
	{
		i++;
		if (stack[i] < min)
		{
			min_index = i;
			min = stack[i];
		}
	}
	return (min_index);
}

void	put_value_as_first_in_a(int *stack_a, int *size_a, int target)
{
	int	i;

	i = 0;
	if (stack_a[0] == target)
		return ;
	while (stack_a[i] != target)
		i++;
	if (i + 1 > *size_a / 2)
	{
		while (*size_a - i)
		{
			rra(stack_a, *size_a);
			i++;
		}
	}
	else
	{
		while (i)
		{
			ra(stack_a, *size_a);
			i--;
		}
	}
}

void	rotate_so_that_min_is_first(int *stack_a, int *size_a)
{
	int	min_value_index;

	min_value_index = find_min_index(stack_a, *size_a);
	if (min_value_index == 0)
		return ;
	if (min_value_index + 1 > *size_a / 2)
	{
		while (*size_a - min_value_index)
		{
			rra(stack_a, *size_a);
			min_value_index++;
		}
	}
	else
	{
		while (min_value_index)
		{
			ra(stack_a, *size_a);
			min_value_index--;
		}
	}
}
