/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_06_calculate_median.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_median(t_stacks *stacks)
{
	int	*temp_tab;
	int	median;

	temp_tab = malloc(stacks->size_a * sizeof(int));
	if (!temp_tab)
	{
		free_and_return_null(
			&(stacks->stack_a), &(stacks->stack_b), NULL, NULL);
		exit(1);
	}
	temp_tab = copy_tab(temp_tab, stacks->stack_a, stacks->size_a);
	ft_sort_int_tab(temp_tab, stacks->size_a);
	median = temp_tab[stacks->size_a / 2];
	free_and_return_null(&temp_tab, NULL, NULL, NULL);
	return (median);
}

int	calculate_third_quartile(t_stacks *stacks)
{
	int	*temp_tab;
	int	third_quartile;

	temp_tab = malloc(stacks->size_a * sizeof(int));
	if (!temp_tab)
	{
		free_and_return_null(
			&(stacks->stack_a), &(stacks->stack_b), NULL, NULL);
		exit(1);
	}
	temp_tab = copy_tab(temp_tab, stacks->stack_a, stacks->size_a);
	ft_sort_int_tab(temp_tab, stacks->size_a);
	third_quartile = temp_tab[(stacks->size_a / 4) * 3];
	free_and_return_null(&temp_tab, NULL, NULL, NULL);
	return (third_quartile);
}

int	*copy_tab(int *temp_tab, int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		temp_tab[i] = stack[i];
		i++;
	}
	return (temp_tab);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	count;

	count = 0;
	while (count < size - 1)
	{
		if (tab[count] > tab[count + 1])
		{
			ft_swap(&tab[count], &tab[count + 1]);
			count = 0;
		}
		else
			count++;
	}
}
