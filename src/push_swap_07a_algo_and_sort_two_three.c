/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_07a_algo_and_sort_two_three.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algorythm(t_stacks *s)
{
	if (s->size_a == 1)
		return (1);
	if (s->size_a == 2)
		sort_two(s->stack_a);
	if (s->size_a == 3)
		sort_three_in_a(s->stack_a, s->size_a);
	if (s->size_a == 4)
		sort_four(s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
	if (s->size_a == 5)
		sort_five(s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
	if (s->size_a == 6)
		sort_six(s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
	if (s->size_a == 7)
		sort_seven(s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
	if (s->size_a == 8)
		sort_eight(s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
	if (s->size_a > 8)
		sort_big_number(s);
	return (1);
}

int	sort_two(int *stack)
{
	if (stack[0] > stack[1])
		sa(stack);
	return (1);
}

int	sort_three_in_a(int *stack, int size)
{
	if (stack[0] > stack[1] && stack[0] > stack[2])
		ra(stack, size);
	else if (stack[1] > stack[0] && stack[1] > stack[2])
		rra(stack, size);
	if (stack[0] > stack[1])
		sa(stack);
	return (1);
}
