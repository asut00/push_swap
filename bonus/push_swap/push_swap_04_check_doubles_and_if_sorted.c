/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_04_check_doubles_and_if_sorted.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_doubles_and_if_sorted(t_stacks *stacks)
{
	if (!check_doubles(stacks))
	{
		free_and_return_null(
			&(stacks->stack_a), &(stacks->stack_b), NULL, NULL);
		return (ERROR_DOUBLES);
	}
	return (10);
}

int	check_doubles(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->size_a)
	{
		j = i + 1;
		while (j < stacks->size_a)
		{
			if (stacks->stack_a[i] == stacks->stack_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(int *stack_a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
