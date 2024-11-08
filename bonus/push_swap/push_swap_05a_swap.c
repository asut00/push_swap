/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_05a_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(int *stack_a)
{
	ft_swap(&stack_a[0], &stack_a[1]);
}

void	sb(int *stack_b)
{
	ft_swap(&stack_b[0], &stack_b[1]);
}

void	ss(int *stack_a, int *stack_b)
{
	ft_swap(&stack_a[0], &stack_a[1]);
	ft_swap(&stack_b[0], &stack_b[1]);
}
