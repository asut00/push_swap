/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_05c_reverse_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(int *stack, int size)
{
	int	temp_last;
	int	i;

	if (!&stack[0] || size == 0)
		return ;
	temp_last = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp_last;
}

void	rra(int *stack_a, int size_a)
{
	reverse_rotate(stack_a, size_a);
	write(1, "rra\n", 4);
}

void	rrb(int *stack_b, int size_b)
{
	reverse_rotate(stack_b, size_b);
	write(1, "rrb\n", 4);
}

void	rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	reverse_rotate(stack_a, size_a);
	reverse_rotate(stack_b, size_b);
	write(1, "rrr\n", 4);
}
