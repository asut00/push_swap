/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_05b_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int value, int *stack, int index, int *size)
{
	int	temp_size;

	temp_size = *size;
	if (*size)
	{
		while (temp_size > index)
		{
			stack[temp_size] = stack[temp_size - 1];
			temp_size--;
		}
	}
	stack[index] = value;
	*size = *size + 1;
}

void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (!&stack_b[0] || *size_b == 0)
		return ;
	push(stack_b[0], stack_a, 0, size_a);
	delete_index(stack_b, 0, size_b);
	write(1, "pa\n", 3);
}

void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (!&stack_a[0] || *size_a == 0)
		return ;
	push(stack_a[0], stack_b, 0, size_b);
	delete_index(stack_a, 0, size_a);
	write(1, "pb\n", 3);
}

void	delete_index(int *stack, int index, int *size)
{
	while (index < *size - 1)
	{
		stack[index] = stack[index + 1];
		index++;
	}
	*size = *size - 1;
}
