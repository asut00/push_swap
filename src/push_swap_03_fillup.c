/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_03_fillup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long long	res;
	long long	sign;
	int			sign_count;
	long long	result;

	res = 0;
	sign = 1;
	sign_count = 0;
	while (*str && (*str == 32 || (9 <= *str && *str <= 13)))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = sign * -1;
		sign_count++;
		str++;
	}
	if (sign_count > 1)
		return (0);
	while (*str && '0' <= *str && *str <= '9')
		res = res * 10 + (*str++ - '0');
	result = res * sign;
	return (result);
}

void	handle_stack_a_malloc_fail(int argc, char **argv)
{
	if (argc == 2)
		free_splitted_words_and_argv(argv, argc - 1);
	exit(1);
}

void	handle_stack_b_malloc_fail(int argc, char **argv, int *stack_a)
{
	free_and_return_null(&stack_a, NULL, NULL, NULL);
	if (argc == 2)
		free_splitted_words_and_argv(argv, argc - 1);
	exit(1);
}

int	*fill_up_arrays(t_stacks *stacks, int argc, char **argv)
{
	int			i;
	int			malloc_size;
	long long	number;

	i = 1;
	malloc_size = argc - 1;
	stacks->stack_a = malloc(malloc_size * sizeof(int));
	if (!stacks->stack_a)
		handle_stack_a_malloc_fail(argc, argv);
	stacks->stack_b = malloc(malloc_size * sizeof(int));
	if (!stacks->stack_b)
		handle_stack_b_malloc_fail(argc, argv, stacks->stack_a);
	while (i < argc)
	{
		number = ft_atol(argv[i]);
		if (number < -2147483648 || 2147483647 < number)
			return (free_and_return_null(
					&(stacks->stack_a), &(stacks->stack_b), NULL, NULL));
		(stacks->stack_a)[i - 1] = number;
		i++;
	}
	return (stacks->stack_a);
}

/*
	if (!stacks->stack_a)
	{
		if (argc == 2)
			free_splitted_words_and_argv(argv, argc - 1);
		exit(1);
	}

	if (!stacks->stack_b)
		return (free_and_return_null(&(stacks->stack_a), NULL, NULL, NULL));
*/