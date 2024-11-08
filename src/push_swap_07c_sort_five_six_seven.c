/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_07c_sort_five_six_seven.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_five(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int		i;
	long	target;

	i = *size_a;
	while (i > 3)
	{
		pb(stack_a, stack_b, size_a, size_b);
		i--;
	}
	sort_three_in_a(stack_a, *size_a);
	if (stack_b[0] < stack_b[1])
		sb(stack_b);
	i = 2;
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

int	reverse_sort_three_in_a(int *stack, int size)
{
	int	min_value;

	min_value = stack[find_min_index(stack, size)];
	if (stack[0] == min_value)
		rb(stack, size);
	else if (stack[1] == min_value)
		rrb(stack, size);
	if (stack[0] < stack[1])
		sb(stack);
	return (1);
}

int	sort_six(int *stack_a, int *stack_b, int *size_a, int *size_b)
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
	reverse_sort_three_in_a(stack_b, *size_b);
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

int	sort_seven(int *stack_a, int *stack_b, int *size_a, int *size_b)
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
	sort_four(stack_a, stack_b, size_a, size_b);
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
